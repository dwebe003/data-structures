#include <iostream>
using namespace std;

void bucketsort(int arr[], int n)  ////////------ Best/Average: O(n + m)   Worst: O(n^2)
{
    int m = 101;
    
    int buckets[m];
    
    for(int i = 0; i < m; i++)
    {
        buckets[i] = 0;
    }
    
    
    
    
    for(int i = 0; i < n; i++)
    {
        ++buckets[arr[i]];
    }
    
    for(int i = 0, j = 0; j < m; j++)
    {
        for(int k = buckets[j]; k > 0; k--)
        {
            arr[i++] = j;
        }
    }
    
    return;
}

int main()
{
    int arr1[10] = {15, 6, 8, 23, 3, 20, 19, 17, 5, 7};
    
    bucketsort(arr1, 10);
    
    for(int i = 0; i < 10; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    
    return 0;
}


