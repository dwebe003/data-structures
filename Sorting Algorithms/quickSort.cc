#include <iostream>
#include <vector>


using namespace std;

void flagit(vector<Comparable> &a, int left, int right, int & lw, int & lb, int & rb)
{
    
    
    return;
}

template<typename Comparable>
void quicksort(vector<Comparable> & a, int left, int right)
{
    int lw = 0, lb = 0, rb = 0;
    if(left + 10 <= right)
    {
        const Comparable & pivot = median3(a, left, right);
        
        flagit(a, left, right, lw, lb, rb);
        // stuff here
    }
    else
    {
        insertionSort(a, left, right);
    }
    
    return;
}

int main()
{
    vector<int> v;
    v.push_back(3);
    v.push_back(4);
    v.push_back(1);
    v.push_back(7);
    v.push_back(2);
    v.push_back(6);
    
    
    return 0;
}
