#include "IntList.h"
#include "SortedSet.h"

#include <iostream>
using namespace std;

int main()
{
   IntList list;
   list.push_front(10);
   list.push_front(20);
   list.push_front(40);
   list.push_front(50);
   list.push_front(30);
   
   cout << "List: " << list << endl;
   
   SortedSet set1;
   
   // set.add(30);
   set1.push_back(30);
   set1.push_back(10);
   set1.push_front(5);
   
   cout << "set1: " << set1 << endl;
   
   //SortedSet set2(list);
   //set2.push_back(50);
   
   //cout << set2 << endl;
   
   SortedSet set3(list);
   
   cout << "set3: " << set3 << endl;
   
   SortedSet set4(set3);
   
   cout << "set4: " << set4 << endl;
   
   // TESTS UNION
   SortedSet newSet;
   newSet = set1 | set4;
   cout << "newSet = set1 | set4 = " << newSet << endl;
   
   //set1 |= set4;
  // cout << "set1 |= set4: " << set1 << endl;
   
   
   // TEST INTERSECTION
   SortedSet intersection;
   intersection = set1 & set4;
   cout << "intersection = set1 & set4 = " << intersection << endl;
   
   set1 &= set4;
   cout << "set1 &= set4: " << set1 << endl;
   
   
   
   // TESTS in(int data) FUNCTION
   /*if(set.in(40))
   {
      cout << "Data found in list." << endl;
   }
   else
   {
      cout << "not found" << endl;
   }*/
   
   return 0;
}