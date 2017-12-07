#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>


using namespace std;

//global variables
int vertices = 0;
int edges = 0;
bool vertError = false;
bool edgeError = false;
int vertCalls = 0;
int edgeCalls = 0;

class UnionFind
{
    private:
        int *id;
        int count;
        int *size;
        
    public:
        UnionFind(int n)
        {
            id = new int[n];
            size = new int[n];
            count = n;
            
            for(int i = 0; i < n; i++)
            {
                id[i] = i;
                size[i] = 1;
            }
            return;
        }
        
        ~UnionFind()
        {
            delete [] id;
            delete [] size;
            return;
        }
        void merge(int x, int y)
        {
            int i = find(x);
            int j = find(y);
            
            if(i == j)
            {
                return;
            }
            
            if(size[i] < size[j])
            {
                id[i] = j;
                size[j] += size[i];
            }
            else
            {
                id[j] = i;
                size[i] += size[j];
            }
            
            count--;
            
            return;
        }
        bool connected(int x, int y)
        {
            return find(x) = find(y);
        }
        
        int count()
        {
            return count;
        }
        int find(int obj)
        {
            int root = obj;
            while(root != id[root])
            {
                root = id[root];

            }
            while(obj != root)
            {
                int newObj = id[obj];
                id[obj] = root;
                obj = newObj;
            }
            return root;
        }
};

class GenericGraph
{
    private:
        UnionFind *unionfind;
        vector<Vertex> vert;
        vector<Edge> edge;
        
    public:
        struct Vertex
        {
            string name;
            vector<int> edges;
        };
        
        struct Edge
        {
            string name;
            double weight;
            pair<int, int> endpoints;
            bool selected;
        };
        
        GenericGraph(int numVerts, int numEdges)
        {
            edge.clear();
            vert.clear();
            edge.resize(numEdges);
            vert.resize(numVerts);
            
            unionfind = new UnionFind(numVerts);
            
            return;
            
            
        }
        
        bool valid (int numVerts, int numEdges)
        {
            bool stop1 = false;
            bool stop2 = false;
            
            if((vertCalls == numVerts) && (edgeCalls == numEdges))
            {
                stop1 = true;
            }
            if( (!vertError) && (!edgeError) )
            {
                stop2 = true;
            }
            
            if( (stop1) && (stop2) )
            {
                return true;
            }
            
            return false;
        }
        
        int edge(const string& name, double weight, const string& v1, const string& v2)
        {
            Edge *esse = new Edge;
            
            for(int i = 0; i < edge.size(); i++)
            {
                if(edge.at(i).name == name)
                {
                    edgeError = true;
                    return -1;
                }
            }
        
        
            edgeCalls++;
            
            
            if(edges < edgeCalls)
            {
                edgeError = true;
                return -2;
            }
            
            
            edgeCalls--;
            
            bool exists1 = false;
            bool exists2 = false;
            for(int i = 0; i < vert.size(); i++)
            {
                if(vert.at(i).name == v1)
                {
                    exists1 = true;
                }
                if(vert.at(i).name == v2)
                {
                    exists2 = true;
                }
            }
            
            bool connect = false;
            
            if( (exists1) && (exists2) )
            {
                edgeError = true;
                return -3;
            }
            
            int v1Pos = -1;
            int v2Pos = -1;
            
            for(int i = 0; i < vert.size(); i++)
            {
                if(vert.at(i).name == v1)
                {
                    v1Pos = i;
                    break;
                }
            }
            
            for(int i = 0; i < vert.size(); i++)
            {
                if(vert.at(i).name == v2)
                {
                    v2Pos = i;
                    break;
                }
            }
    
            for(int i = 0; i < edge.size(); i++)
            {
                if( ((edge.at(i).endpoints.first == v1Pos) && (edge.at(i).endpoints.second == v2Pos)) 
                    || ( (edge.at(i).endpoints.first == v2Pos) && (edge.at(i).endpoints.second == v2Pos) ) )
                {
                    edgeError = true;
                    return -4;
                }
            }
            
            edgeCalls++;
            esse->endpoints.first = v1Pos;
            esse->endpoints.second = v2Pos;
            esse->name = name;
            esse->weight = weight;
            
            edge.push_back(*esse);
            
            return 1;
        }
        
        int vertex(const string& name)
        {
            Vertex *wert = new Vertex;
            
            for(int i = 0; i < vert.size(); i++)
            {
                if(vert.at(i).name == name)
                {
                    vertError = true;
                    return -1;
                }
            }
            vertCalls++;
            if(vertCalls > vertices)
            {
                verError = true;
                return -2;
            }
            vertCalls--;
            
            wert->name = name;
            
            
            vert.push_back(*wert);
        }
        
        void printVerts()
        {
            for(int i = 0; i < vert.size(); i++)
            {
                cout << "Vertex: " << vert.at(i).name << endl;
            }
            cout << endl;
            return;
        }
        
        void printEdges()
        {
            for(int i = 0; i < edge.size(); i++)
            {
                cout << "Edge: " << edge.at(i).name << " " << edge.at(i).weight 
                    << " " << edge.at(i).endpoints.first << " " << edge.at(i).endpoints.second << endl;
            }
            cout << endl;
            return;
        }
        
        double NUTs(vector<string> &edgeList)
        {
            double weightSum = 0.0;
            edgeList.clear();
            
            for(int i = 0; i < edge.size(); i++)
            {
                edge.at(i).selected = false;
            }
            
            unionfind = new UnionFind(vert.size());
            
            for(int i = 0; i < edge.size(); i++)
            {
                if(unionfind->find(edge.at(i).endpoints.first) != unionfind->find(edge.at(i).endpoints.second))
                {
                    edgeList.push_back(edge.at(i).name);
                    unionfind->merge(edge.at(i).endpoints.first, edge.at(i).endpoints.second);
                    edge.at(i).selected = true;
                }
                if( (edgeList.size() == fabs(vert.size() - 1)) || (unionfind->count() == 1) )
                {
                    break;
                }
            }
            
            sort(edgeList.begin(), edgeList.end();
            
            //count weights
            for(int i = 0; i < edge.size(); i++)
            {
                if(edge.at(i).selected)
                {
                    weightSum += edge.at(i).weight;
                }
            }
            
            return weightSum;
        }
};