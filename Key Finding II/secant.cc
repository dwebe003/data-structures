#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;

double fx(double x);
double gx(double x);
double hx(double x);
double bisect (double (*f) (double x), double a, double b, double eps, int & numCompares);
double sec_plus (double (*f) (double x), double a, double b, double eps, int & numCompares);

int main()
{
    int numCompares = 0;
    
    double (*f)(double);
    f = &fx;
    
    double (*g)(double);
    g = &gx;
    
    double (*h)(double);
    h = &hx;
    
    double result = 0;
    double eps1 = 1e-6;
    double eps2 = 1e-15;

    
    cout << "-----USING EPSILON = 1e-6-----" << endl;
    
    cout << "f(x) = x^2 - 2  on the interval [1,2] :" << endl;
    
    cout << endl << "Root: " << bisect(f, 1, 2, eps1, numCompares) << endl << endl;
    cout << endl << "Root: " << sec_plus(f, 1, 2, eps1, numCompares) << endl << endl;
    
    
    cout << "g(x) = 2x^3 - 4x^2 + 3x  on the interval [-1, 1] :" << endl;
    
    cout << endl << "Root: " << bisect(g, -1, 1, eps1, numCompares) << endl << endl;
    cout << endl << "Root: " << sec_plus(g, -1, 1, eps1, numCompares) << endl << endl;
    
    
    cout << "h(x) = x^3 - 4  on the interval [1, 3] :" << endl;
    
    cout << endl << "Root: " << bisect(h, 1, 3, eps1, numCompares) << endl << endl;
    cout << endl << "Root: " << sec_plus(h, 1, 3, eps1, numCompares) << endl << endl;
    
    
    
    cout << "------ USING EPSILON = 1e-15 ------" << endl;
    cout << "f(x) = x^2 - 2  on the interval [1,2] :" << endl;
    
    cout << endl << "Root: " << bisect(f, 1, 2, eps2, numCompares) << endl << endl;
    cout << endl << "Root: " << sec_plus(f, 1, 2, eps2, numCompares) << endl << endl;
    
    
    cout << "g(x) = 2x^3 - 4x^2 + 3x  on the interval [-1, 1] :" << endl;
    
    cout << endl << "Root: " << bisect(g, -1, 1, eps2, numCompares) << endl << endl;
    cout << endl << "Root: " << sec_plus(g, -1, 1, eps2, numCompares) << endl << endl;
    
    
    cout << "h(x) = x^3 - 4  on the interval [1, 3] :" << endl;
    
    cout << endl << "Root: " << bisect(h, 1, 3, eps2, numCompares) << endl << endl;
    cout << endl << "Root: " << sec_plus(h, 1, 3, eps2, numCompares) << endl << endl;
    
    
    
    
    return 0;
}



double fx(double x)
{
    double a = pow(x,2) - 2;
    return a;
}

double gx(double x)
{
    double a = (2*pow(x,3)) - (4*pow(x,2)) + (3*x);
    return a;
}

double hx(double x)
{
    double a = pow(x,3) - 4;
    return a;
}

double bisect (double (*f) (double x), double a, double b, double eps, int & numCompares)
{
    numCompares = 0;
    double m = a + (b-a)/2;
    int n = 0;
    
    double largest = max(fabs(a), fabs(b));
    cout << "BISECTION METHOD :" << endl;
    cout << setw(22) << "a " << setw(24) << "Fa " << setw(24) << "b " << setw(24) << "Fb " << setw(24) << "m " << setw(24) << "Fm " << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    
    while(n <= numCompares)
    {
        m = a + (b-a)/2;
        
        largest = max(fabs(a), fabs(b));
        
        if( (f(m) == 0)  || (fabs(a-b) < (largest*eps)) )
        {
            numCompares++;
            return m;
        }
    
        
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
        
        cout << setprecision(16) << setw(22) << a << " " << setw(24) << f(a) << " " << setw(24) << b << " " << setw(24) << f(b) << " " << setw(24) << m << " " << setw(24) << f(m) << " " << endl;
        n++;    
        
    }
    
    
}

double sec_plus (double (*f) (double x), double a, double b, double eps, int & numCompares)
{
    numCompares = 0;
    double m = 0.0;
    int n = 0;
    char replaced = ' ';
    
    double largest = max(fabs(a), fabs(b));
    
    double Fa = f(a);
    double Fb = f(b);
    double Fm = f(m);
    
    cout << "ACCELERATED SECANT METHOD : " << endl;
    cout << setw(22) << "a " << setw(24) << "Fa " << setw(24) << "b " << setw(24) << "Fb " << setw(24) << "m " << setw(24) << "Fm " << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    
    while(n <= numCompares)
    {
        m = ((Fb * a) - (Fa * b)) / (Fb - Fa);
        Fm = f(m);
        
        largest = max(fabs(a), fabs(b));
        
        if( (Fm == 0)  || (fabs(a-b) < (largest*eps)) )
        {
            numCompares++;
            return m;
        }
        
        
        if( Fa * Fm > 0 )
        {
            numCompares++;
            a = m;
            Fa = Fm;
            
            if(replaced == 'a')
            {
                Fb = Fb/2;
            }
            
            replaced = 'a';
        }
        else
        {
            numCompares++;
            b = m;
            Fb = Fm;
            
            if(replaced == 'b')
            {
                Fa = Fa/2;
            }
            
            replaced = 'b';
        }
        cout << setprecision(16) << setw(22) << a << " " << setw(24) << Fa << " " << setw(24) << b << " " << setw(24) << Fb << " " << setw(24) << m << " " << setw(24) << Fm << " " << endl;
        n++;
    }
    
}