#include <iostream>

using namespace std;

#include "IntVector.h"

int main()
{
    IntVector vec = IntVector(1, 4); // initializes vector
    cout << "Vec sz: " << vec.size() << endl;
    vec.erase(0);
    cout << vec.at(0) << endl;
    /*cout << "vec.at(4) = " << vec.at(4) << endl;        // tests at() function
    cout << "Vec size: " << vec.size() << endl;         // tests size() function
    cout << "Vec cap: " << vec.capacity() << endl;      // tests cap() function
    
    // E M P T Y
    if(!vec.empty())                            
    {       
        cout << "NOT EMPTY" << endl;                    // tests empty() fctn
    }
    
    // F R O N T
    cout << "Vec front: " << vec.front() << endl;       // tests front() fctn
    // B A C K
    cout << "Vec back: " << vec.back() << endl;         // tests back() fctn
    
    // P U S H _ B A C K
    vec.push_back(-1);                                  // tests push_back() fn
    
    // (these make sure push_back() operated correctly)
    cout << "New vec size: " << vec.size() << endl;
    cout << "Vec back() after pushback: " << vec.back() << endl;
    
    // P O P _ B A C K
    vec.pop_back();                                     // tests pop_back() fn
    
    // (these ensure pop_back() operated correctly)
    cout << "Vec size() after popback: " << vec.size() << endl;
    //cout << "Vec at index 5 after pop_back(): " << vec.at(5) << endl; //should abort
    
    // C L E A R
    vec.clear();
    //cout << "Vec at index 0 after clear(): " << vec.at(0) << endl; //should abort
    
    // R E S I Z E
    vec.resize(6, -2);                                  // tests resize() fctn
    
    // (these make sure resize() operated correctly)
    cout << "Vec front after resize: " << vec.front() << endl;
    cout << "Vec back after resize: " << vec.back() << endl; 
    
    // I N S E R T
    vec.insert(4, 0);                                   // test insert() fctn
    
    cout << "Vector list after clear, resize, and insert: " << endl;
    for(unsigned i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i) << " ";
    }
    cout << endl;
    
    // E R A S E    
    vec.erase(4);                                       // tests erase() fctn
    cout << "After erase, vec at index 4 (where the 0 was inserted) = "
        << vec.at(4) << endl;
    
    // A S S I G N
    vec.assign(5, 0);
    cout << "Vec list after assign(): " << endl;
    for(unsigned i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i) << " ";
    }
    cout << endl;
    
    // R E S E R V E
    cout << "Cap: " << vec.capacity() << endl << "...reserving..." << endl;
    vec.reserve(20);                                    // tests reserve() fn
    cout << "Cap: " << vec.capacity() << endl;
    */

    return 0;
}