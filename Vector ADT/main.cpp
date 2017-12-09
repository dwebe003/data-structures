#include <iostream>

using namespace std;

#include "IntVector.h"

int main()
{
	cout << "\nInitializing vector of size 1 with value 4...\n\n";
    IntVector vec = IntVector(1, 4); 							// initializes vector
	
	// S I Z E
	cout << "vec.size() test...\n";
    cout << "Vec size: " << vec.size() << endl << endl;
	
	// E R A S E
	cout << "vec.erase() test...\n";
    vec.erase(0);
    cout << "Vec size: " << vec.size() << endl << endl;
	
	// E M P T Y 
	cout << "vec.empty() test...\n";
    if(!vec.empty())                            
    {       
        cout << "NOT EMPTY\n\n";                    			// tests empty() fctn
    }
	else
	{
		cout << "EMPTY\n\n";
	}
	
	// P U S H _ B A C K
	cout << "vec.push_back(-1) and vec.push_back(500) test...\n";
    vec.push_back(-1);                                  		// tests push_back() fn
	vec.push_back(500);
	
	// A T
	cout << "vec.at(x) test...\n";
    cout << "vec.at(0) = " << vec.at(0) << endl;        		// tests at() function
	cout << "vec.at(1) = " << vec.at(1) << endl;        		// tests at() function
    cout << "Vec size: " << vec.size() << endl;         		// tests size() function
    cout << "Vec cap: " << vec.capacity() << endl << endl;     	// tests cap() function
    

    // F R O N T
	cout << "vec.front() and vec.back() test...\n";
    cout << "Vec front: " << vec.front() << endl;       		// tests front() fctn
    // B A C K
    cout << "Vec back: " << vec.back() << endl << endl;        	// tests back() fctn

    
    // P O P _ B A C K
	cout << "vec.pop_back(); test...\n";
    vec.pop_back();                                     		// tests pop_back() fn
	cout << "Vec size: " << vec.size() << endl;
	cout << "Vec front: " << vec.front() << endl << endl;

    
    // C L E A R
	cout << "vec.clear() test...\n";
    vec.clear();
    cout << "Vec size: " << vec.size() << endl << endl;
    
    // R E S I Z E
	cout << "vec.resize(6, -2) test...\n";
    vec.resize(6, -2);                                 			 // tests resize() fctn
	cout << "Vec size: " << vec.size() << endl;
	cout << "Vec back: " << vec.back() << endl << endl;
	
    
    // I N S E R T
	cout << "vec.insert(4, 0) test...\n";
    vec.insert(4, 0);                                   		// test insert() fctn
	cout << "vec.at(4) = " << vec.at(4) << endl << endl;
    
    cout << "Vector list so far...\n";
	for(unsigned i = 0; i < vec.size(); i++)
	{
		cout << vec.at(i) << " ";
	}
	cout << endl << endl;
    
    
    // A S S I G N
	cout << "vec.assign(5, 0) test...\n";
    vec.assign(5, 0);
    cout << "Vector list after assign(5, 0): " << endl;
    for(unsigned i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i) << " ";
    }
    cout << endl << endl;
    
    // R E S E R V E
	cout << "vec.reserve(20) test...\n";
    cout << "Cap: " << vec.capacity() << endl << "...reserving..." << endl;
    vec.reserve(20);                                    		// tests reserve() fn
    cout << "Cap: " << vec.capacity() << endl << endl;
    

    return 0;
}
