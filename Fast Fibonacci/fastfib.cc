#include <iostream>
#include <fstream>

using namespace std;

double FibLoopCount(int n, int & totalAdds, int & totalCalls);
double FastFibRecCount(int n, int & totalAdds, int & totalCalls);
void FFRC2(int n, double & Fn_1, double & Fn, int & totalAdds, int & totalCalls);

int main()
{
    const int MAX_N = 30;
    const int MAX_CALLS = 10000;
    int calls = 0;
    int adds = 0;
    
    double Fn = 0;
    
	
	/* Begins putting data into a file test2.csv.
		Counts the number of adds to array as well as
		the number of calls for the Recursive function */
    ofstream outFS; 
    outFS.open("test2.txt");
    
    for(int n = 1; n <= MAX_N; n++)
    {
        Fn = FibLoopCount(n, adds, calls);
		cout << "Fibnacci num = " << Fn << " with n = "<< n << endl;
		
        outFS << n << ", " << adds << ", " << calls << ", ";
        
        calls = 0;
        adds = 0;
        
        Fn = FastFibRecCount(n, adds, calls);
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

double FastFibRecCount(int n, int & totalAdds, int & totalCalls)
{
    double twoBack = 0;
    double oneBack = 0;
    
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
        FFRC2(n-1, twoBack, oneBack, totalAdds, totalCalls);
        return twoBack + oneBack;
    }
    
}

void FFRC2(int n, double & Fn_1, double & Fn, int & totalAdds, int & totalCalls)
{
    totalAdds++;
    totalCalls++;
    
    double temp = 0;

    
    if(n == 1)
    {
        Fn = 1;
        Fn_1 = 0;
    
    }

    
    if(n >= 2)
    {
        FFRC2(n-1, Fn_1, Fn, totalAdds, totalCalls);
        temp = Fn + Fn_1;
        Fn_1 = Fn;
        Fn = temp;
    
    }
    
    
    return;
}
