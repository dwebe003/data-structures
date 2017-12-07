#include <iostream>

using namespace std;

double FibLoop( int n );
double FibRec( int n);

int main()
{
    int k = 0;
    
    cout << "Enter number of rows K: ";
    cin >> k;
    cout << endl;
    
    for(int i = 0; i <= k; i++)
    {
        if(FibLoop(i) == FibRec(i))
        {
            cout << i << " " << FibLoop(i) << endl;
        }
    }
    
    return 0;
}

double FibLoop( int n )
{
    if(n < 0)
    {
        return 0;
    }
    
    double arr[n+1];
    
    for(int i = 0; i < n + 1; i++)
    {
        if(i == 0)
        {
            arr[i] = 0;
        }
        else if(i == 1)
        {
            arr[i] = 1;
        }
        else
        {
            arr[i] = arr[i-1] + arr[i-2];
        }
    }
    
    return arr[n];
}

double FibRec( int n )
{
    if(n <= 0)
    {
        return 0;
    }
    
    else if(n == 1)
    {
        return 1;
    }
    else
    {
        return FibRec(n-1) + FibRec(n-2);
    }
    
}