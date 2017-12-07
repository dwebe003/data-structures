//
//  main.cpp
//  main
//
//  Created by David Weber on 2/3/17.
//  Copyright © 2017 David Weber. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;


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
        };
    
        TreeNode *root;
        
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
        
        bool contains(const Comparable & key_val, TreeNode* rt, TreeNode* & key_loc)
        {
            bool check = false;
            
            if(rt == NULL)           //takes care of case when tree is empty
            {
                return false;
            }
            
            if(key_val == rt->element)      //if key_val = root, we are done
            {                               //else, we need to check its children 
                key_loc = rt;               //by taking each one as a new root
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
        GenericTree(Comparable root_val)
        {
            this->root = new TreeNode(root_val);
            
            return;
        }
        
        int insert(Comparable new_val, Comparable parent_val)
        {
            TreeNode* key_loc;
            
            if(contains(new_val, root, key_loc))
            {
                return -1;
            }
            else if(!contains(parent_val, root, key_loc))
            {
                return -2;
            }
            else
            {
                TreeNode* n = new TreeNode(new_val);
                
    
                if(key_loc->firstChild == NULL)
                {
                    key_loc->firstChild = n;
                }
                else
                {
                    //iterate through all the siblings, find the last one, put the new element after
                    if(key_loc->firstChild->nextSibling == NULL)
                    {
                        key_loc->firstChild->nextSibling = n;
                    }
                    else
                    {
                        key_loc = key_loc->firstChild->nextSibling;
                        while(key_loc->nextSibling != NULL)
                        {
                            key_loc = key_loc->nextSibling;
                        }
                        key_loc->nextSibling = n;
                        
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
    }
    
    






    
    
    return 0;
}