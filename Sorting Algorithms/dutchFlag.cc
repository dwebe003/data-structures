#include <iostream>
using namespace std;

void dutchflag(int arr[], int n)  ////////------ Best/Average/Worst: O(n)
{
    int low = 0;
    int high = n - 1;
    int mid = 0;
    
    while(mid <= high)
    {
        if(arr[mid] == 2)
        {
            int tmp = arr[high];
            arr[high] = arr[mid];
            arr[mid] = tmp;
            high--;
        }
        else if(arr[mid] == 0)
        {
            int tmp = arr[low];
            arr[low] = arr[mid];
            arr[mid] = tmp;
            mid++;
            low++;
        }
        else
        {
            mid++;
        }
    }
    
    
    return;
}


int main()
{
    int arr1[9] = {2, 1, 0, 1, 2, 0, 1, 2, 1};
    
    dutchflag(arr1, 9);
    
    for(int i = 0; i < 9; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    
    
    return 0;
}