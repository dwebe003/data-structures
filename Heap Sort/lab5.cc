#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>
#include <vector>
#include <cmath>
#include <iomanip>
#include <iterator>
#include <sstream>

using namespace std;

template<typename T>
int Marjory(vector<T> &v);

template<typename T>
int Marjory(vector<T> &v, int left, int right);

template<typename T>
void buildHeap(vector<T> &v, int size);

template<typename T>
void buildHeap(vector<T> &v, int left, int right);

template<typename T>
void printHeap(vector<T> &v, int left, int right);

template<typename T>
void maxHeap(vector<T> &v, int i, int size);

template<typename T>
void heapSort(vector<T> &v, int left, int right);

template<typename T>
void heapSort(vector<T> &v, int size);

template<typename T>
void maxHeap(vector<T> &v, int i, int left, int right);

template <typename Comparable> 
void print_vector(vector<Comparable> v, int left, int right);


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
bool operator<=(const Fraction& lhs, const Fraction& rhs) {
    return (lhs.num() * rhs.den() <= rhs.num() * lhs.den());
}
bool operator>(const Fraction& lhs, const Fraction& rhs) {
    return (lhs.num() * rhs.den() > rhs.num() * lhs.den());
}
bool operator>=(const Fraction& lhs, const Fraction& rhs) {
    return (lhs.num() * rhs.den() >= rhs.num() * lhs.den());
}
Fraction operator*(Fraction lhs, const Fraction& rhs) {
    return lhs *= rhs;
}



int main()
{
    //variables
    ifstream inFS;
    char ch = ' ';
    int found = 0;
    string type = "";
    int num = 0;
    int denom = 1;
    int n = 0;
    double d = 0.0;
    Fraction f = 0;
    
    string firstline = "";
    string secondline = "";
    
    int left = -1;
    int right = -1;
    string leftS = "";
    string rightS = "";
    string chS = "";
    
    
    
    //Enter data type
    inFS.open("myfile");
    
    if(inFS.is_open())
    {
        getline(inFS, chS);
    }
    else
    {
        cout << "Enter a data type (i or I for int, d or D for double, f or F for fraction) and (optional) left and right values, separated by a space: " << endl;
        getline(cin, chS);
    }

    if(chS.size() > 1)
    {
        
        stringstream s3;
        s3 << chS;
        s3 >> ch;
        s3 >> left;
        s3 >> right;
        s3.str("");
    }
    else
    {
        stringstream s3;
        s3 << chS;
        s3 >> ch;
        s3.str("");
    }
    
        
    vector<int> vInt;
    vector<double> vDoub;
    vector<Fraction> vFrac;
    
    if((ch == 'i') || (ch == 'I'))
    {
        type = "int";
    }
    else if((ch == 'd') || (ch == 'D'))
    {
        type = "double";
    }
    else if((ch == 'f') || (ch == 'F'))
    {
        type = "fraction";
    }
    else
    {
        cout << "Invalid data type. Exiting program." << endl;
        return 0;
    }
    
    
    // -------------- GETS NUMBERS --------------------
    if(inFS.is_open())
    {
        if(type == "int")
        {
            while(inFS >> n)
            {
                vInt.push_back(n);
            }
        }
        else if(type == "double")  
        {
            while(inFS >> d)
            {
                vDoub.push_back(d);
            }
        }
        else
        {
            while(inFS >> num)
            {

                denom = 1;
                inFS >> denom;
                f = Fraction(num, denom);
                vFrac.push_back(f);
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
                vInt.push_back(n);
            }
        }
        else if(type == "double")  
        {
            cout << "Enter each double, separated by a space (press ctrl+D to finish): ";
            while(cin >> d)
            {
                vDoub.push_back(d);
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
                vFrac.push_back(f);
            }
        }
    }


    cout << "Original: ";
    //print unsorted list
    if((left == -1) && (right == -1))
    {
        if(type == "int")
        {
            print_vector(vInt, 0, (vInt.size() - 1));
            int a = Marjory(vInt);
        }
        else if(type == "double")
        {
            print_vector(vDoub, 0, (vDoub.size() - 1));
            int a = Marjory(vDoub);
        }
        else
        {
            print_vector(vFrac, 0, (vFrac.size() - 1));
            int a = Marjory(vFrac);
        }
    }
    else
    {
        if(type == "int")
        {
            print_vector(vInt, left, right);
            int a = Marjory(vInt, left, right);
        }
        else if(type == "double")
        {
            print_vector(vDoub, left, right);
            int a = Marjory(vDoub, left, right);
        }
        else
        {
            print_vector(vFrac, left, right);
            int a = Marjory(vFrac, left, right);
        }
    }
    

    
    return 0;
}

template<typename T>
void heapSort(vector<T> &v, int size)
{
    T tmp = v.at(0); //initialize
    
    for(int i = size - 1; i >= 2; i--)
    {
        tmp = v.at(i);
        v.at(i) = v.at(0);
        v.at(0) = tmp;
        
        maxHeap(v, 0, i - 1);
    }
    
    return;
}

template<typename T>
void heapSort(vector<T> &v, int left, int right)
{
    T tmp = v.at(left);
    
    for(int i = right; i >= left + 2; i--)
    {
        tmp = v.at(i);
        v.at(i) = v.at(left);
        v.at(left) = tmp;
        
        maxHeap(v, left, i - 1);
    }
    
    return;
}

template<typename T>
int Marjory(vector<T> &v)
{

    int left = 0;
    int right = v.size() - 1;
    buildHeap(v, v.size());
    
    
    cout << "Heap'd: ";
    print_vector(v, left, right);
    cout << endl;
    
    cout << "Heap: " << endl;
    printHeap(v, 0, (v.size() - 1));
    
    heapSort(v, v.size());
    
    cout << "Final: ";
    print_vector(v, left, right);

    
    
    return 1;
}

template<typename T>
int Marjory(vector<T> &v, int left, int right)
{
    
    
    //check errors
    if(left > right)
    {
        return -1;
    }
    
    buildHeap(v, left, right);

    cout << "Heap'd: ";
    print_vector(v, left, right);
    cout << endl;
    
    cout << "Heap: " << endl;
    printHeap(v, left, right);

    heapSort(v, left, right);
    
    cout << "Final: ";
    print_vector(v, left, right);
    
    
    return 1;
}

template<typename T>
void buildHeap(vector<T> &v, int left, int right)
{
    int mid = (left + right) / 2;
    for(int i = mid; i>= left; i--)
    {
        maxHeap(v, i, left, right);
    }
    return;
}

template<typename T>
void buildHeap(vector<T> &v, int size)
{
    for(int i = size/2 - 1; i >= 0; i--)
    {
        maxHeap(v, i, size - 1);
    }
    return;
}

template<typename T>
void maxHeap(vector<T> &v, int i, int left, int right)
{
    int j;
    T tmp = v.at(i);
    j = i*2;
    
    while(j <= (right - left + 1))
    {
        if((j < (right - left + 1)) && (v.at(j+1) > v.at(j)))
        {
            j = j + 1;
        }
        if(tmp > v.at(j))
        {
            break;
        }
        else if(tmp <= v.at(j))
        {
            v.at(j/2) = v.at(j);
            j = j*2;
        }
    }
    
    
    v.at(j/2) = tmp;
    
    return;
}


template<typename T>
void printHeap(vector<T> &v, int left, int right)
{
    int level = 0;
    int i = left;
    int j = 0;
    int prints = 0;
    
    while(i <= right)
    {
        cout << level + 1 << ": ";
        for(j = 0; j < pow(2, level); j++)
        {
            if(i <= right)
            {
                cout << v.at(i) << " ";
            }
            i++;
            
            if(i == v.size())
            {
                break;
            }
        }
        level++;
        cout << endl;
    }
    cout << endl;
    return;
}

template<typename T>
void maxHeap(vector<T> &v, int i, int size)
{
    int j;
    T tmp = v.at(i);
    j = i*2;
    
    while(j <= size)
    {
        if((j < size) && (v.at(j+1) > v.at(j)))
        {
            j = j + 1;
        }
        if(tmp > v.at(j))
        {
            break;
        }
        else if(tmp <= v.at(j))
        {
            v.at(j/2) = v.at(j);
            //v.at(j) = tmp;
            j = j*2;
        }
    }
    
    
    v.at(j/2) = tmp;
    
    return;
}




template <typename Comparable> 
void print_vector(vector<Comparable> v, int left, int right)
{
    
    for(unsigned i = 0; i < v.size(); i++)
    {
        if(i == left)
        {
            cout << "[ ";
        }
        
        if(i == (v.size() - 1))
        {
            cout << v.at(i);
        }
        else
        {
            cout << v.at(i) << " ";
        }
        
        if(i == right)
        {
            cout << "] ";
        }
    }
    cout << endl;
    
    return;
}
