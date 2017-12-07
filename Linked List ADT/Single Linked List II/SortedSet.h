#include "IntList.h"

class SortedSet : public IntList
{
    public:
        SortedSet();
        ~SortedSet();
        SortedSet(const IntList &list);
        SortedSet(const SortedSet &set);
        
        //accessors
        bool in(int data) const;
        SortedSet & operator|(const SortedSet &rhs) const;
        SortedSet & operator&(const SortedSet &rhs) const;
        
        //mutators
        void add(int data);
        void push_front(int data);
        void push_back(int data);
        void insert_ordered(int data);
        SortedSet & operator|=(SortedSet &rhs);
        SortedSet & operator&=(SortedSet &rhs);
        
    //privates are the protected of IntList.h
    //head
    //tail
        
    
    
};