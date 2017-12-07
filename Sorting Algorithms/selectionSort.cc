#include <iostream>
#include <vector>
using namespace std;


void selectionsort(vector<int> &v)
{
    for(int i = 0; i < v.size() - 1; i++)
    {
        int minIndex = i;
        
        for(int j = i + 1; j < v.size(); j++)
        {
            if(v.at(minIndex) > v.at(j))
            {
                minIndex = j;
            }
        }
        
        swap(v.at(i), v.at(minIndex));
    }
    
    
    
    return;
}

int main()
{
    vector<int> myVec(7);
    myVec = {8, 2, -5, 4, 0, 14, -2};
    
    for(int i = 0; i < myVec.size(); i++)
    {
        cout << myVec.at(i) << " ";
    }
    cout << endl;
    
    selectionsort(myVec);
    
    
    
    for(int i = 0; i < myVec.size(); i++)
    {
        cout << myVec.at(i) << " ";
    }
    cout << endl;
    
    return 0;
}