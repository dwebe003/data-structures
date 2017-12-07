#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;


int closest2key(double key, double A[], int n, int & numCompares);
int closestBinary(double key, double A[], int n, int & numCompares);
int giantStepper(double key, double A[], int n, int & numCompares);


int main()
{
    int n = 0;
    
    ifstream inFS;
    
    inFS.open("myfile");
    
    //gets number of elements n
    if(!inFS.is_open())
    {
        cout << "Enter number of elements n: ";
        cin >> n;
        cout << endl;
    }
    else
    {
        inFS >> n;
        
    }
    
    //creates array and populates
    double arr1[n];
    
    if(!inFS.is_open())
    {
        
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            inFS >> arr1[i];
        }
        
    }

    //creates copy array and then sorts
    double arr2[n];
    
    for(int i = 0; i < n; i++)
    {
        arr2[i] = arr1[i];
    }
    
    sort(arr2, arr2 + n);
    
    //gets key values
    double x;
    int numCompares = 0;
    int closestIndex;
    double closestVal;
    
    cout << "Enter a new key value: ";
    cin >> x;
    cout << endl;
    
    closestIndex = closest2key(x, arr2, n, numCompares);
    closestVal = arr2[closestIndex];
    
    cout << "closest2key " << closestIndex << " " << closestVal << " " << numCompares << endl;
    
    closestIndex = closestBinary(x, arr2, n-1, numCompares);
    closestVal = arr2[closestIndex];
    
    cout << "closestBinary " << closestIndex << " " << closestVal << " " << numCompares << endl;
    
    
    closestIndex = giantStepper(x, arr2, n, numCompares);
    closestVal = arr2[closestIndex];
    
    cout << "giantStepper " << closestIndex << " " << closestVal << " " << numCompares << endl;
    
    //-----------------------------------
    
    inFS.close();
    return 0;
}


int closestBinary(double key, double A[], int n, int & numCompares)
{
    numCompares = 0;
    unsigned midpoint;
    int min = 0;
    int max = n;
    int index = 0;
    int temp = 2000000;
    int tempInd = -1;
    
    if(n < 1)
    {
        return -1;
    }
    
    while(min <= max)  
    {
        numCompares++;
        midpoint = (min + max) / 2;

        if(temp >= abs(key - A[midpoint]))
        {
            temp = abs(key - A[midpoint]);
            tempInd = midpoint;
        }
        
        if(A[midpoint] == key)
        {
            return midpoint;
        }
        else if(A[midpoint] > key)
        {
            min = min;
            max = midpoint - 1;
        }
        else
        {
            min = midpoint + 1;
            max = max;
        }
        
    }
    
    return tempInd;
    
}


int giantStepper(double key, double A[], int n, int & numCompares)
{
    numCompares = 0;
    int jump = sqrt(n);
    int min = 0;
    int max = jump - 1;
    int tempInd = -1;
    int temp = 2000000;
    bool stop = false; 
    
    if(n < 1)
    {
        return -1;
    }
    
    while(!stop)
    {
        if(key > A[max])
        {
            numCompares++;
            temp = abs(key - A[max]);
            tempInd = max;
            
            min = max + 1;
            max = max + jump;
        }
        else if(key == A[max])
        {
            numCompares++;
            return max;
        }
        else
        {
            stop = true;
            for(unsigned i = min; i < max; i++)
            {
                numCompares++;
                
                if(temp > abs(key - A[i]))
                {
                    temp = abs(key - A[i]);
                    tempInd = i;
                }
                else if(A[i] == key)
                {
                    return i;
                }
            }
            
            
        }
        
        
    }
    
    return tempInd;
}


int closest2key(double key, double A[], int n, int & numCompares)
{
    numCompares = 0;
    int index;
    int temp = 2000000;
    
    if(n < 1)
    {
        return -1;
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            if(abs(key - A[i]) < temp)
            {
                index = i;
                temp = abs(key - A[i]);
            }
            numCompares++;
        }
        
        return index;
        
        
    }
}


