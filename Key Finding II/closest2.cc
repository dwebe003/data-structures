#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <algorithm>
//template <typename Comparable>

using namespace std;

template <typename Comparable> 
int closest2key(Comparable key, const vector<Comparable> & A, int & numCompares);


class Fraction
{
        int gcd(int a, int b) { return b==0 ? a : gcd(b,a%b); }
        int n, d;
    public:
        Fraction(int n, int d = 1) : n(n/gcd(abs(n),abs(d))), d(d/gcd(abs(n),abs(d))) {
            if (this->d < 0) {
                this->n *= -1;
                this->d *= -1;
            }
        }
        Fraction& operator-=(const Fraction& rhs)
        {
            if((this->n == 0) || (this->d == 0) || (rhs.n == 0) || (rhs.d == 0))
            {
                if((this->n == 0) || (this->d == 0))
                {
                    if((rhs.n == 0) || (rhs.d == 0))
                    {
                        this->n = 0;
                        this->d = 0;
                        return *this;
                    }
                    else
                    {
                        this->n = -(rhs.n);
                        this->d = rhs.d;
                    }
                }
                
                if((rhs.n == 0) || (rhs.d == 0))
                {
                    if((this->n == 0) || (this->d == 0))
                    {
                        this->n = 0;
                        this->d = 0;
                        return *this;
                    }
                    else
                    {
                        this->n = this->n;
                        this->d - this->d;
                        return *this;
                    }
                }
            }
            else
            {
                this->n = ( (this->n) * (rhs.d) ) - ( (this->d) * (rhs.n) );
                this->d = ( (this->d) * (rhs.d) );
            }
            return *this;
        }
        Fraction operator-(const Fraction& rhs)
        {
            Fraction result = 1;
            
            if((this->n == 0) || (this->d == 0) || (rhs.n == 0) || (rhs.d == 0))
            {
                if((this->n == 0) || (this->d == 0))
                {
                    if((rhs.n == 0) || (rhs.d == 0))
                    {
                        result.n = 0;
                        result.d = 0;
                        return result;
                    }
                    else
                    {
                        result.n = -(rhs.n);
                        result.d = rhs.d;
                    }
                }
                
                if((rhs.n == 0) || (rhs.d == 0))
                {
                    if((this->n == 0) || (this->d == 0))
                    {
                        result.n = 0;
                        result.d = 0;
                        return result;
                    }
                    else
                    {
                        result.n = this->n;
                        result.d - this->d;
                        return result;
                    }
                }
            }
            else
            {
                result.n = ( (this->n) * (rhs.d) ) - ( (this->d) * (rhs.n) );
                result.d = ( (this->d) * (rhs.d) );
            }
            return result;
        }
        int num() const { return n; }
        int den() const { return d; }
        Fraction& operator*=(const Fraction& rhs) {
            int new_n = n*rhs.n / gcd(abs(n*rhs.n), abs(d*rhs.d));
            d = d*rhs.d / gcd(abs(n*rhs.n), abs(d*rhs.d));
            n = new_n;
            return *this;
        }
};

ostream& operator<<(ostream& out, const Fraction& f) {
    return out << f.num() << '/' << f.den() ;
}
bool operator==(const Fraction& lhs, const Fraction& rhs) {
    return ((lhs.num() * rhs.den()) == (rhs.num() * lhs.den()));
}
bool operator<(const Fraction& lhs, const Fraction& rhs) {
    return (lhs.num() * rhs.den() < rhs.num() * lhs.den());
}
bool operator>(const Fraction& lhs, const Fraction& rhs) {
    return (lhs.num() * rhs.den() > rhs.num() * lhs.den());
}
Fraction operator*(Fraction lhs, const Fraction& rhs) {
    return lhs *= rhs;
}

int main()
{
    ifstream inFS;
    char ch;
    int found = 0;
    string type = "";
    int n = 0;
    double d = 0.0;
    Fraction f = 0;
    int num = 0;
    int denom = 0;
    
    inFS.open("myfile");
    
    //gets data type
    if(inFS.is_open())
    {
        inFS >> ch;
    }
    
    while(found == 0)
    {
        if(!inFS.is_open())
        {
            cout << "Enter a data type (i = int, d = double, f = fraction): ";
            cin >> ch;
            cout << endl;
        }
        
        
        if((ch == 'i') || (ch == 'I'))
        {
            type = "int";
            found++;
        }
        else if((ch == 'd') || (ch == 'D'))
        {
            type = "double";
            found++;
        }
        else if((ch == 'f') || (ch == 'F'))
        {
            type = "fraction";
            found++;
        }
        else
        {
            if(!inFS.is_open())
            {
                cout << "Error." << endl;
                return 0;
            }
            else
            {
                cout << "Error: try again." << endl;
            }
        }
    }
    
    vector<int> vi;
    vector<double> vd; //NOTES: possible make v a pointer to vf. see how that reacts with the int and double case
    vector<Fraction> vf;
    
    
    //fills vector
    if(inFS.is_open())
    {
        if(type == "int")
        {
            while(inFS >> n)
            {
                vi.push_back(n);
            }
        }
        else if(type == "double")  
        {
            while(inFS >> d)
            {
                vd.push_back(d);
            }
        }
        else
        {
            while(inFS >> num)
            {

                denom = 1;
                inFS >> denom;
                f = Fraction(num, denom);
                vf.push_back(f);
            }
        }
    }
    else
    {

        if(type == "int")
        {
            cout << "Enter each int, separated by a space (press ctrl+D to finish): ";
            while(cin >> n)
            {
                vi.push_back(n);
            }
        }
        else if(type == "double")  
        {
            cout << "Enter each double, separated by a space (press ctrl+D to finish): ";
            while(cin >> d)
            {
                vd.push_back(d);
            }
        }
        else if(type == "fraction")
        {
            cout << "Enter numerator and denominator, separated by a space (press ctrl+D to finish): ";
            while(cin >> num)
            {
                denom = 1;
                cin >> denom;
                if(denom == 0)
                {
                    cout << "Fatal error: divide by zero." << endl;
                    return 0;
                }
                f = Fraction(num, denom);
                vf.push_back(f);
            }
        }
    }
    

    
    for(unsigned i = 0; i < vf.size(); i++)
    {
        cout << vf.at(i) << " ";
    }
    cout << endl;
    
    
    int intkey = 0;
    double doublekey = 0.0;
    int result = 0;
    int numCompares = 0;
    
    cout << "Enter a key to search: ";
    cin.clear();
    if(type == "int")
    {
        sort(vi.begin(), vi.end());
        
        cin >> intkey;
        cout << endl;
        
        result = closest2key(intkey, vi, numCompares);
        cout << "key: " << intkey << "    closest value: " << vi.at(result) << "  at index: " << result << endl;
    }
    else if(type == "double")
    {
        sort(vd.begin(), vd.end());
        
        cin >> doublekey;
        cout << endl;
        
        result = closest2key(doublekey, vd, numCompares);
        cout << "key: " << doublekey << "    closest value: " << vd.at(result) << "  at index: " << result << endl;
    }
    else if(type == "fraction")
    {
        sort(vf.begin(), vf.end());
        
        cin >> num;
        cin >> denom;
        cout << endl;
        
        if(denom == 0)
        {
            cout << "Fatal error: divide by zero." << endl;
            return 0;
        }
        
        Fraction fractionkey = Fraction(num, denom);
        
        result = closest2key(fractionkey, vf, numCompares);
        cout << "key: " << fractionkey << "    closest value: " << vf.at(result) << "  at index: " << result << endl;
    }
    


    
    inFS.close();
    return 0;
}

template <typename Comparable>
int closest2key(Comparable key, const vector<Comparable> & A, int & numCompares)
{
    numCompares = 0;
    Comparable temp = 2000000;
    int index;
    Comparable val = 0;
    
    if(A.size() < 1)
    {
        return -1;
    }
    else
    {
        for(auto i = A.begin(); i < A.end(); i++)
        {
            Comparable difference = key - (*i);
            
            if(difference < 0)
            {
                difference *= -1;
            }
            
            if(difference < temp)
            {
                index = i - A.begin();
                val = A.at(index);
                temp = difference;
            }
            numCompares++;
            
            cout << "A[" << index << "] = " << val << ", Key Distance = " << temp << endl;
        }
        
        return index;
    }
    
    
    
    
}