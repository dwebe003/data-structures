#include <iostream>
using namespace std;


void insertionsort(int arr[], int n)  ////////--- Average/Worst: O(n^2)   Best: O(n)
{
    for(int i = 1; i < n; i++)
    {
        int j = i;
        
        while(j > 0 && arr[j] < arr[j-1])
        {
            swap(arr[j], arr[j-1]);
            j--;
        }
        
    }
    
    
    return;
}

int main()
{
    int arr1[10] = {7, 1, -2, 0, 5, 14, 21, 50, 4, 3};
    
    
    insertionsort(arr1, 10);
    
    
    for(int i = 0; i < 10; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    
    
    return 0;
}