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

//void fillList(list<int> & IntList, list<double> & DoubList, list<Fraction> & FracList, string type, ifstream inFS);
void getType(string & type, ifstream & inFS);

template <typename Comparable> 
void print_list(list<Comparable> list);

template <typename Comparable>
void split_list(list<Comparable> &mylist, int k, list<Comparable> &rejects);

template<typename Comparable>
void mergesort (list<Comparable> & myList, typename list<Comparable>::iterator & L, int blockSize);

template<typename T>
typename list<T>::iterator merge(list<T> & myList, typename list<T>::iterator & L1, int Lblock, typename list<T> :: iterator & L2, int Rblock);

template <typename T>
void print_merge(list<T> & myList, typename list<T>::iterator P, typename list<T>::iterator P1, typename list<T>::iterator P2, int blockSize);

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
    
    
    
    //Enter data type
    inFS.open("myfile");
    
    string chS = "";
    
    if(inFS.is_open())
    {
        getline(inFS, chS, ' ');
    }
    else
    {
        cout << "Enter a data type (i or I for int, d or D for double, f or F for fraction) and (optional) left and right values, separated by a space: " << endl;
        getline(cin, chS, ' ');
    }
    
    stringstream s3;
    s3 << chS;
    s3 >> ch;
    s3.str("");
    
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
    

    list<int> IntList;
    list<double> DoubList;
    list<Fraction> FracList;
    
    //fillList(IntList, DoubList, FracList, type, inFS);
    
    if(inFS.is_open())
    {
        if(type == "int")
        {
            while(inFS >> n)
            {
                IntList.push_back(n);
            }
        }
        else if(type == "double")  
        {
            while(inFS >> d)
            {
                DoubList.push_back(d);
            }
        }
        else
        {
            while(inFS >> num)
            {

                denom = 1;
                inFS >> denom;
                f = Fraction(num, denom);
                FracList.push_back(f);
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
                IntList.push_back(n);
            }
        }
        else if(type == "double")  
        {
            cout << "Enter each double, separated by a space (press ctrl+D to finish): ";
            while(cin >> d)
            {
                DoubList.push_back(d);
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
                FracList.push_back(f);
            }
        }
    }



    //print unsorted list
    cout << "Before mergesort: ";
    if(type == "int")
    {
        typename list<int>::iterator itr = IntList.begin();
        print_list(IntList);
        mergesort(IntList, itr, IntList.size());
        
        cout << "After mergesort: ";
        print_list(IntList);
    }
    else if(type == "double")
    {
        typename list<double>::iterator itr = DoubList.begin();
        print_list(DoubList);
        mergesort(DoubList, itr, DoubList.size());
        
        cout << "After mergesort: ";
        print_list(DoubList);
    }
    else
    {
        typename list<Fraction>::iterator itr = FracList.begin();
        print_list(FracList);
        mergesort(FracList, itr, FracList.size());
        
        cout << "After mergesort: ";
        print_list(FracList);
    }
    
    

    
    //print sorted list
    if(type == "int")
    {
        cout << endl << "Original: ";
        print_list(IntList);
        cout << endl;
    }
    else if(type == "double")
    {
        cout << endl << "Original: ";
        print_list(DoubList);  
        cout << endl;
    }
    else
    {
        cout << endl << "Original: ";
        print_list(FracList);
        cout << endl;
    }

    int k = 0;
    
    cout << "Enter the spacing between elements, k: ";
    cin >> k;
    cout << endl;
    
    
    list<int> IntRejects;
    list<double> DoubRejects;
    list<Fraction> FracRejects;
    
    //splits list, adds to rejects
    if(type == "int")
    {
        split_list(IntList, k, IntRejects);
        cout << endl << "Ejected nodes: ";
        print_list(IntRejects);
    }
    else if(type == "double")
    {
        split_list(DoubList, k, DoubRejects);
        cout << endl << "Ejected nodes: ";
        print_list(DoubRejects);
    }
    else
    {
        split_list(FracList, k, FracRejects);
        cout << endl << "Ejected nodes: ";
        print_list(FracRejects);
    }
    

    
    return 0;
}

template<typename Comparable>
void mergesort (list<Comparable> & myList, typename list<Comparable>::iterator & L, int blockSize)
{
    typename list<Comparable>::iterator last = myList.end();
    
    int Lblock = blockSize/2;
    int Rblock = blockSize - Lblock;
    
    
    typename list<Comparable>::iterator L1 = L;
    typename list<Comparable>::iterator L2 = L;
    
    advance(L2, Lblock);

    //cout << "L1: " << *L1 << "    L2: " << *L2 << endl;
    if(blockSize < 2)
    {
        return;
    }
    else
    {
        mergesort(myList, L1, Lblock);
        mergesort(myList, L2, Rblock);
    
        L = merge(myList, L1, Lblock, L2, Rblock);
  
    }
    
    return;
}

template<typename T>
typename list<T>::iterator merge(list<T> & myList, typename list<T>::iterator & L1, int Lblock, typename list<T> :: iterator & L2, int Rblock)
{
    
    typename list<T>::iterator first = L1;
    typename list<T>::iterator P = L1;
    
    typename list<T>::iterator L = L1;
    
    typename list<T>::iterator P1 = L1;
    typename list<T>::iterator P2 = L2;
    
    
    unsigned left = 0;
    unsigned right = 0;
    
    
    while((left < Lblock) && (right < Rblock))
    { 
        //print_merge(myList, P, P1, P2, (Rblock + Lblock));
    
        if((*L1 <= *L2))
        {
            left++;
            L1++;
            P1++;
        }
        else
        {
            T temp = *L2;
            
            L2 = myList.erase(L2);
            myList.insert(L1, temp);
            
            right++;
            typename list<T>::iterator it = P2;
            P2 = P1;
            P1 = it;
            P = first;
            
            if(L == L1)
            {
                L--;
            }
            
        }
        //cout << "L1: " << *L1 << "   L2: " << *L2 << endl;
    }
    //cout << "P1: " << *P1 << "  P2: " << *P2 << endl;
    //print_merge(myList, P, P1, P2, (Rblock + Lblock));
    //cout << endl;
    //P1++;

    return L;
}

template <typename Comparable>
void split_list(list<Comparable> &mylist, int k, list<Comparable> &rejects)
{
    typename list<Comparable>::iterator itr = mylist.begin();
    typename list<Comparable>::iterator tmp = itr;
    int numDeletions = mylist.size() / k;
    int index = 0;

    advance(itr, k-1);
    tmp = itr;
    
    
    for(int i = 0; i < numDeletions; i++)
    {
        advance(itr, k);
        rejects.push_back(*tmp);
        cout << "After erasing " << *tmp << ": ";
        mylist.erase(tmp);
        tmp = itr;
        

        print_list(mylist);
        
    }
    
    
    
    return;
}


template <typename Comparable> 
void print_list(list<Comparable> list)
{
    
    while(!list.empty())
    {
        cout << list.front() << " ";
        list.pop_front();
    }
    cout << endl;
    
    return;
}

template <typename T>
void print_merge(list<T> & myList, typename list<T>::iterator P, typename list<T>::iterator P1, typename list<T>::iterator P2, int blockSize)
{
    
    typename list<T>::iterator step = myList.begin(); 
    
    int count = 0;
    bool bracketPrinted = false;
    bool par1 = false;
    bool par2 = false;

    
    for(int i = 0; i < myList.size(); i++)
    {
        if(step == P)
        {
            cout << "[ ";
            bracketPrinted = true;
        }
        
        if((step == P1))
        {
            cout << ") ";
            par1 = true;
        }
        
        if((step == P2))
        {
            cout << ") ";
            par2 = true;
        }
        
        if(bracketPrinted)
        {
            count++;
        }
        

        
        cout << *step << " ";
        
        if(count == blockSize)
        {
            cout << "] ";
        }
        
        step++;
    }
    
    cout << endl;
    
    return;
}

void getType(string & type, ifstream & inFS)
{
    char ch = ' ';
    int found = 0;
    
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
                return;
            }
            else
            {
                cout << "Error: try again." << endl;
            }
        }
    }
    return;
}

/*void fillList(list<int> & IntList, list<double> & DoubList, list<Fraction> & FracList, string type, ifstream inFS)
{
    int num = 0;
    int denom = 1;
    int n = 0;
    double d = 0.0;
    Fraction f = 0;
    
    
        if(inFS.is_open())
        {
            if(type == "int")
            {
                while(inFS >> n)
                {
                    IntList.push_back(n);
                }
            }
            else if(type == "double")  
            {
                while(inFS >> d)
                {
                    DoubList.push_back(d);
                }
            }
            else
            {
                while(inFS >> num)
                {
    
                    denom = 1;
                    inFS >> denom;
                    f = Fraction(num, denom);
                    FracList.push_back(f);
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
                    IntList.push_back(n);
                }
            }
            else if(type == "double")  
            {
                cout << "Enter each double, separated by a space (press ctrl+D to finish): ";
                while(cin >> d)
                {
                    DoubList.push_back(d);
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
                        return;
                    }
                    f = Fraction(num, denom);
                    FracList.push_back(f);
                }
            }
        }
        return;
}   */
