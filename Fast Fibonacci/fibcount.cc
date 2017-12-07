#include <iostream>
#include <fstream>

using namespace std;

double FibLoopCount(int n, int & totalAdds, int & totalCalls);
double FibRecCount(int n, int & totalAdds, int & totalCalls);

int main()
{
    const int MAX_N = 30;
    const int MAX_CALLS = 10000;
    int calls = 0;
    int adds = 0;
    
    double Fn = 0;
    
    ofstream outFS; 
    outFS.open("test1.csv");
    
    for(int n = 1; n <= MAX_N; n++)
    {
        Fn = FibLoopCount(n, adds, calls);
        outFS << n << ", " << adds << ", " << calls << ", ";
        
        calls = 0;
        adds = 0;
        
        Fn = FibRecCount(n, adds, calls);
        if(calls > MAX_CALLS)
        {
            break;
        }
        else
        {
            outFS << adds << ", " << calls << endl;
        }
        
        calls = 0;
        adds = 0;
    }
    
    outFS.close();
    return 0;
}

double FibLoopCount(int n, int & totalAdds, int & totalCalls)
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
            totalAdds++;
            arr[i] = arr[i-1] + arr[i-2];
        }
    }
    
    return arr[n];
}

double FibRecCount(int n, int & totalAdds, int & totalCalls)
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
        totalAdds++;
        totalCalls += 2;
        return FibRecCount(n-1, totalAdds, totalCalls) + FibRecCount(n-2, 
            totalAdds, totalCalls);
    }
    
}