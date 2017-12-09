//
//  main.cpp
//  main
//
//  Created by David Weber on 2/3/17.
//  Copyright © 2017 David Weber. All rights reserved.
//

#include <iostream>
#include <queue>
#include <functional>
#include <utility>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
#include <cstdlib>
using namespace std;

int hashSlingingSlasher(double key_val)
{
    //This function creates the index (hashedVal) of where to place the key_val
	//7919, 28411, and 101 are all prime
    int x = floor(key_val);
    double y = (key_val - x);
    int z = floor(y * 7919);
    
    int hashedVal = ((28411 + (x + z)*8121)%101);
    
    return hashedVal;
}

int hashSlingingSlasher(string key_val)
{
    int sum = 0;
    
    for(int i = 0; i < key_val.size(); i++)
    {
        sum += key_val[i];
    }
    
    int hashedVal = sum % 101;
    
    return hashedVal;
}

enum EntryType {ACTIVE, EMPTY, DELETED};      //important

template<typename Comparable>
class GenericTree
{
    private:
        struct TreeNode
        {
            Comparable element;
            TreeNode *firstChild;
            TreeNode *nextSibling;
            int height;
            TreeNode(Comparable element) : element(element), firstChild(NULL), nextSibling(NULL), height(-1) {}
            TreeNode(TreeNode* rt)                                                                                  //This copy constructor is super important for hang_left
            {
                this->element = rt->element;
                this->height = rt->height;
                this->firstChild = rt->firstChild;
                this->nextSibling = 0;
            }
        };
            
        struct HashEntry
        {
            Comparable key_val;
            TreeNode *key_loc;
            EntryType info;
            HashEntry( const Comparable & e = Comparable ( ),     
             TreeNode * const n = NULL,
             EntryType i = EMPTY) : key_val( e ), key_loc ( n ), info( i ) { }
        };

        class HashTable
        {   private:
                vector<HashEntry> array;
                
            public:
				//resizes array to 101 and initializes
                HashTable()              
                {
                    array.resize(101);
                    makeEmpty();
                    return;
                }
				
                //hashes and inserts a key value into the array
                void insert(Comparable key_val, TreeNode* key_loc)      
                {
					//Calls hashing function, which is located globally in order to overload string or double
                    int index = hashSlingingSlasher(key_val);             
                    cout << "key_val: " << key_val << "    index: " << index << endl;
                    array[index].key_val = key_val;
                    array[index].key_loc = key_loc;
                    array[index].info = ACTIVE;
                    
                    return;
                }
                
				//initializes an EMPTY table
                void makeEmpty()
                {
                    for(int i = 0; i < array.size(); i++)
                    {
                        array[i].info = EMPTY;
                    }
                    return;
                }
				
                //Searches through hash table for key value, "returns" key_loc implicitly
                bool findHash(Comparable key_val, TreeNode* & key_loc)                      {
                    
                    for(int i = 0; i < array.size() - 1; i++)
                    {
                        if(key_val == array[i].key_val)
                        {
                            key_loc = array[i].key_loc;
                            return true;
                        }
                    }
                    
                    return false;
                }
                
				//Just a fancy print function essentially
                void dump_hash_table() 
                {
                    char ch = 34;
                    for(int i = 0; i < array.size(); i++)
                    {
                        cout << i << ": ";
                        if(array[i].info == EMPTY) { cout << "EMPTY"; }
                        else if(array[i].info == DELETED) { cout << "DELETED"; }
                        else { cout << "ACTIVE"; }
                        if(array[i].info == ACTIVE)
                        {
                            cout << " " << ch << array[i].key_val << ch << " " << hashSlingingSlasher(array[i].key_val)
                                << "->" << ch <<  array[i].key_loc->element << ch;
                        }
                        cout << endl;
                    }
                    return;
                }
        };
        
        HashTable htable;
        TreeNode *root;
        
        //Taken from Generic Tree
        void set_height(TreeNode *rt)
        {
            if(rt->firstChild == NULL)
            {
                rt->height = 0;
            }
            
            if(rt->nextSibling != NULL)
            {
                set_height(rt->nextSibling);
            }
            
            if(rt->firstChild != NULL)
            {
                set_height(rt->firstChild);
                
                TreeNode* i = rt->firstChild;
                int max = 0;
                
                while(i != NULL)
                {
                    if(i->height > max)
                    {
                        max = i->height;
                    }
                    i = i->nextSibling;
                }
                
                
                rt->height = 1 + max;
            }
            return;
        }
        
        void hang_left(TreeNode *rt)
        {
            if(rt->firstChild == NULL)
            {
                return;
            }
			
            //recursive call towards right
            if(rt->nextSibling != NULL)
            {
                hang_left(rt->nextSibling);                         
            }
            
			//recursive call downwards
            if(rt->firstChild != NULL)
            {
                hang_left(rt->firstChild);                          
                
                /* starts here once we reach the bottom right of tree 
				and the recursion starts backtracking */
				
                //declares a pointer to the current rt's firstChild.
                TreeNode* i = rt->firstChild;                       
                
				//initializes an empty priority queue, where each spot contains the height and a pointer to a child
                priority_queue<pair<int, TreeNode*> > childQ;       
                
				//so long as current rt has children, we add each child's height and pointer to the queue,
                while(i != NULL)                                    
                {                                                   
                    //then increment the pointer
                    childQ.push(make_pair(i->height, i));
                    
                    i = i->nextSibling;
                }
                
				//declares a new pointer to current rt
                TreeNode* current = rt;                             
                
				//extracts a pair (height and pointer) from top of queue, priority queue is sorted in decreasing order                    
                pair<int, TreeNode*> p = childQ.top();
				   
				//sets first child equal to the pointer on top of queue           
                current->firstChild = p.second;
				
				//pops the top of the queue                     
                childQ.pop();                                       
                
				//changes current to rt's firstChild
                current = rt->firstChild;                           
                int size = childQ.size();
                
                for(int i = 0; i < size; i++)
                {
					//same process, but slightly different because nextSibling is complicated
                    p = childQ.top(); 
					   
					/*Creates a new node, copying whatever is now on the top of the queue, 
					had to make a copy constructor in TreeNode struct */                                             
					current->nextSibling = new TreeNode(p.second);                      
					childQ.pop();                   
					
					//increments current towards right            
                    current = current->nextSibling;                 
                }
            }
            
            return;
        }
        
        //Unchanged from Generic Tree
        void print_Tree(const TreeNode *rt, vector<int> & nodeLabel)
        {
            for(int i = 0; i < nodeLabel.size(); i++)
            {
                cout << nodeLabel.at(i) << ".";
            }
            
            cout << "[" << rt->height << "]: ";
            
            cout  << rt->element << endl;
            
            
            if(rt->firstChild != NULL)
            {
                nodeLabel.push_back(1);
                print_Tree(rt->firstChild, nodeLabel);
                nodeLabel.pop_back();
            }
            
            int last = nodeLabel.size() - 1;
            if(rt->nextSibling != NULL)
            {
                nodeLabel.at(last)++;
                print_Tree(rt->nextSibling, nodeLabel);
                nodeLabel.at(last)--;
            }
            

            
            
            return;
        }
        
        //Unchanged from Generic Tree
        bool contains(const Comparable & key_val, TreeNode* rt, TreeNode* & key_loc)
        {
            bool check = false;
            
			//takes care of case when tree is empty
            if(rt == NULL)           
            {
                return false;
            }
            
			/* If key_val == root, we are done. Otherwise we
				must check its children recursively by taking 
				each one as a new root */
            if(key_val == rt->element)  
            {    
                key_loc = rt;     
                return true;
            }
        
            if(rt->firstChild != NULL)
            {
                check = contains(key_val, rt->firstChild, key_loc);
                if(check == true)
                {
                    return true;
                }
            }
            if(rt->nextSibling != NULL)
            {
                return contains(key_val, rt->nextSibling, key_loc);
            }
            
            
        }
        
    public:
    
        //Added a call to add the value to the hash table.
        GenericTree(Comparable root_val)
        {
            this->root = new TreeNode(root_val);
            TreeNode* key_loc = root;
            htable.insert(root_val, key_loc);
            
            return;
        }
        
        //made this in order to call the private version
        void hangLeft()
        {
            hang_left(root);
            return;
        }
        
        //made this in order to call the private version
        void dumpHash()
        {
            htable.dump_hash_table();
            return;
        }
        
        //Changed the contents of this function a little bit. Using the hash table, searching through the tree is much faster.
        int insert(Comparable new_val, Comparable parent_val)
        {
            TreeNode* key_loc = NULL;
            
            //search hash table
            bool contains = htable.findHash(new_val, key_loc);
            
            if(contains)
            {
                return -1;
            }
            
            contains = htable.findHash(parent_val, key_loc);
            
            
            if(!contains)
            {
                return -2;
            }
            else
            {
                TreeNode* n = new TreeNode(new_val);
                
    
                if(key_loc->firstChild == NULL)
                {
                    key_loc->firstChild = n;
                    htable.insert(new_val, key_loc->firstChild);
                }
                else
                {
                    //iterate through all the siblings, find the last one, put the new element after
                    if(key_loc->firstChild->nextSibling == NULL)
                    {
                        key_loc->firstChild->nextSibling = n;
                        htable.insert(new_val, key_loc->firstChild->nextSibling);
                        //add to hash table. (hash table hashes the value and places it in its array)
                    }
                    else
                    {
                        key_loc = key_loc->firstChild->nextSibling;
                        while(key_loc->nextSibling != NULL)
                        {
                            key_loc = key_loc->nextSibling;
                        }
                        key_loc->nextSibling = n;
                        htable.insert(new_val, key_loc->nextSibling);
                        //add to hash table.
                        
                    }
                }
                
                
                return 1;
            }
        }
        
        void print_Tree()
        {
            
            vector<int> nodeLabel;
            nodeLabel.push_back(1);
            
            
            print_Tree(root, nodeLabel);
            
            return;
        }
        
        int set_height()
        {
            set_height(root);
            
            return root->height;
        }
        

};



int main() 
{
    ifstream inFS;
    char type;
    string chString;
    
    
    inFS.open("myfile");
    
    getline(inFS, chString);
    
    stringstream ss;
    ss << chString;
    ss >> type;
    
    if((type == 's') || (type == 'S'))
    {
        string root;
        ss >> root;
        
        GenericTree<string> myTree(root);
        
        while(getline(inFS, chString))
        {
            string newVal;
            string parVal;
            
            stringstream s1;
            s1 << chString;
            s1 >> newVal;
            s1 >> parVal;
            s1.str("");
            
            int error = myTree.insert(newVal, parVal);
            if(error == -1)
            {
                cout << "Error: new_val '" << newVal << "' is already in the tree." << endl;
            }
            if(error == -2)
            {
                cout << "Error: parent_val '" << parVal << "' is NOT in the tree." << endl;
            }
        }
        cout << endl;
        // PRINTS    
        myTree.print_Tree();
        
        cout << endl;
        int h = myTree.set_height();
        
        myTree.print_Tree();
        cout << endl;
        
        myTree.hangLeft();
        myTree.print_Tree();
    }
    else if((type == 'd') || (type == 'D'))
    {
        double root;
        ss >> root;
        
        GenericTree<double> myTree(root);
        
        while(getline(inFS, chString))
        {
            double newVal;
            double parVal;
            
            stringstream s2;
            s2 << chString;
            s2 >> newVal;
            s2 >> parVal;
            s2.str("");
            
            int error = myTree.insert(newVal, parVal);
            if(error == -1)
            {
                cout << "Error: new_val '" << newVal << "' is already in the tree." << endl;
            }
            if(error == -2)
            {
                cout << "Error: parent_val '" << parVal << "' is NOT in the tree." << endl;
            }
            
        }
        cout << endl;
        // PRINTS    
        myTree.print_Tree();
        
        cout << endl;
        int h = myTree.set_height();
        
        myTree.print_Tree();
        cout << endl;
        
        //myTree.dumpHash();
        
        myTree.hangLeft();
        myTree.print_Tree();
    }
    

    
    
    return 0;
}
