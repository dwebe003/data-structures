#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;

double fx(double x);
double bisect (double (*f) (double x), double a, double b, double eps, int & numCompares);


int main()
{
    int numCompares = 0;
    
    double (*f)(double);
    f = &fx;
    
    double result = 0;
    double eps = 1e-15;
    double a = 1;
    double b = 2;
    
    result = bisect(f, a, b, eps, numCompares);
    
    
    cout << setprecision(15) << "root: " << result << endl;
    
    
    return 0;
}



double fx(double x)
{
    double a = pow(x,2) - 3;
    return a;
}

double bisect (double (*f) (double x), double a, double b, double eps, int & numCompares)
{
    numCompares = 0;
    double m = a + (b-a)/2;
    int n = 0;
    
    double largest = max(fabs(a), fabs(b));
    
    while(n <= numCompares)
    {
        m = a + (b-a)/2;
        
        largest = max(fabs(a), fabs(b));
        
        if( (f(m) == 0)  || (fabs(a-b) < (largest*eps)) )
        {
            numCompares++;
            return m;
        }
        
        n++;
        
        if( (f(m) * f(a)) > 0 )
        {
            numCompares++;
            a = m;
        }
        else
        {
            numCompares++;
            b = m;
        }
    }
    
}