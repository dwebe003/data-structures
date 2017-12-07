#include <iostream>
#include <stdexcept>
using namespace std;
#include "IntVector.h"


       // unsigned sz; //stores the size of the IntVector (the number of elements currently being used).
       // unsigned cap; //store the size of the array
       // int *data; //stores the address of the dynamically-allocated array of integers


IntVector::IntVector()
{
    sz = 0;
    cap = 0;
    
    data = new int[0];
    
    return;
}

IntVector::IntVector(unsigned size, int value)
{
    sz = size;
    cap = size;
    
    data = new int[size];
    
    for(unsigned i = 0; i < size; i++)
    {
        data[i] = value;
    }
    
    return;
}

unsigned IntVector::size() const
{
    return sz;
}

unsigned IntVector::capacity() const
{
    return cap;
}

bool IntVector::empty() const
{
    if(sz == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

const int& IntVector::at(unsigned index) const
{
    //int val = 0;
    
    if(index >= sz)
    {
        throw out_of_range("IntVector::at_range_check");
    }
    else
    {
        return data[index];
        //val = data[index];
    }
    //return val;
}

int& IntVector::at(unsigned index)
{
    //int val = 0;
    if(index >= sz)
    {
        throw out_of_range("IntVector::at_range_check");
    }
    else
    {
        return data[index];
        //val = data[index];
    }
    //return val;
}

const int& IntVector::front() const
{
    return data[0];
}

const int& IntVector::back() const
{
    return data[(sz - 1)];
}

int& IntVector::front()
{
    return data[0];
}

int& IntVector::back()
{
    return data[(sz - 1)];
}

void IntVector::expand()
{
    if(cap == 0)
    {
        cap++;
        int* newdata = new int[cap];
        newdata[0] = data[0];
        delete data;
        data = newdata;
        return;
    }
    //expand when sz == cap
    int* newdata =  new int[cap * 2];
    
    //copies
    for(unsigned i = 0; i < sz; i++)
    {
        newdata[i] = data[i];
    }
    
    delete data;
    data = newdata;

    cap = cap*2;
    
    return;
}

void IntVector::expand(unsigned amount)
{
    
    int* newdata = new int[cap + amount];
    //copies data
    for(unsigned i = 0; i < sz; i++)
    {
        newdata[i] = data[i];
    }
    delete data;
    data = newdata;

    cap = cap + amount;
    
    return;
}

void IntVector::push_back(int value)
{
    if(sz >= cap)
    {
        expand();
    }
    
    sz++;
    
    data[sz-1] = value;
    
    return;
}

void IntVector::pop_back()
{
    sz--;
    return;
}

void IntVector::clear()
{
    sz = 0;
    return;
}

void IntVector::resize(unsigned size, int value)
{
    if(size > cap)
    {
        if((cap*2) > size)
        {
            expand();
        }
        else
        {
            expand(size-cap);
        }
    }
    unsigned max = size - sz;
    
    // shrinks vector if requested
    if(size < sz)
    {
        sz = size;
    }
    else        // enlarges vector
    {
        for(unsigned i = 0; i < max; i++)
        {
            push_back(value);
        }
    }

    return;
}

void IntVector::insert(unsigned index, int value)
{
    // checks index
    if(index > sz)
    {
        throw out_of_range("IntVector::insert_range_check");
    }
    
    if(sz == cap)
    {
        expand();
        sz++;
    }
    else
    {
        sz++;
    }

    
    // actual insertion
    int temp = data[index];
    data[index] = value;
    for(unsigned i = index + 1; i < sz; i++)
    {
        int temp2 = data[i];
        data[i] = temp;
        temp = temp2;
    }

    return;
}

void IntVector::erase(unsigned index)
{
    // checks index
    if(index >= sz)
    {
        throw out_of_range("IntVector::erase_range_check");
    }
    
    
    if(sz == 1)
    {
        data[0] = 0;
        sz--;
        return;
    }
    
    for(unsigned i = index; i < sz; i++)
    {
        data[i] = data[i+1];
    }
    sz--;

    return;
}

void IntVector::reserve(unsigned n)
{
    if(cap < n)
    {
        if((cap*2) > n)
        {
            expand();
        }
        else
        {
            expand(n-cap);
        }
    }
    
    return;
}

void IntVector::assign(unsigned n, int value)
{
    clear();
    
    if(cap < n)
    {
        if((cap*2) > n)
        {
            expand();
        }
        else
        {
            expand(n-cap);
        }
    }
    resize(n, value);
    
    
    return;
}

IntVector::~IntVector()
{
    if(data != 0)
    {
        delete data;
    }
    return;
}
