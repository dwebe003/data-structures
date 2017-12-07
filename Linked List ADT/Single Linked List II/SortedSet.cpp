#include "SortedSet.h"
#include "IntList.h"
using namespace std;

SortedSet::SortedSet() : IntList()
{
	//The default constructor initializes an empty set.
	return;
};


SortedSet::~SortedSet()
{
	//The destructor of a Derived class needs to deallocate all dynamically 
	//allocated memory that the IntList destructor does not already deallocate. 
	//You may very well find that this function does not need to do anything :)

	return;
};


SortedSet::SortedSet(const IntList &list) : IntList(list)
{
	//A copy constructor that is passed an IntList instead of a SortedSet. 
	//It should initialize the set using the values in the IntList. 
	//You can use the IntList copy constructor, and then remove any 
	//duplicates and sort the remaining values.

	SortedSet* set = new SortedSet();
	for(IntNode* i = head; i!= 0; i = i->next)
	{
		set->add(i->data);
		
	}

	clear();
	SortedSet();
	
	for(IntNode* i = set->head; i != 0; i = i->next)
	{
		add(i->data);
	}
	
	return;
};


SortedSet::SortedSet(const SortedSet &set) : IntList(set)
{
	//The copy constructor initializes the set to be a copy of the set passed in. 
	//Use the IntList copy constructor.
	
	return;
};

//accessors
bool SortedSet::in(int data) const
{
	bool found = false;
	//This function returns true if the value in data is a member 
	//of the set, otherwise false.
	
	for(IntNode* i = head; i != 0; i = i->next)
	{
		if(i->data == data)
		{
			found = true;
		}
	}
	
	return found;
};

SortedSet & SortedSet::operator|(const SortedSet &rhs) const
{
	//This function returns a SortedSet object that is the union of 2 
	//SortedSet objects, the left and right operands of this binary operator. 
	//A union of 2 sets is a set that consists of all of the distinct elements 
	//of both sets combined. That is, all of the values in both sets,
	//minus any duplicates.
	//sset1 = sset2 | sset3;
	//The return type is const SortedSet; the explicit parameter must be const SortedSet &
	//This must be an O(n) operation.
	//This means you cannot call remove_duplicates or selection_sort member 
	//functions within this function. Recall, the remove_duplicates and 
	//selection_sort functions are O(n2) functions. You may, however, 
	//use the in and add functions.
	SortedSet* newSet = new SortedSet();
	
	for(IntNode* i = head; i != 0; i = i->next)
	{
		int val = i->data;
		newSet->add(val);															// adds all values from lhs to newSet
	}
	
	for(IntNode* i = rhs.head; i != 0; i = i->next)
	{
		int val = i->data;															// adds all values from rhs to newSet, but does not add dupes
		newSet->add(val);
	}
	
	//merges 2 sets
	//checks for dupes, deletes them
	//returns implicit param
	return *newSet;
};


SortedSet & SortedSet::operator&(const SortedSet &rhs) const
{
	/* This function returns a SortedSet object that is the intersection of 2 
	SortedSet objects, the left and right operands of this binary operator. 
	An intersection of 2 sets is a set of all elements that are in both sets. 
	That is, all of the values that are in both the left operand and the right operand.
	sset1 = sset2 & sset3;
	The return type is const SortedSet; the explicit parameter must be const SortedSet &

	This must be an O(n) operation.

	This means you cannot call remove_duplicates or selection_sort member 
	functions within this function. Remember, the remove_duplicates and 
	selection_sort functions are O(n2) functions. You may, however, use 
	the in and add functions. 
	
	//populates new set, adds data to this set whenever set1->data == set2->data
	//checks for dupes
	//returns new */
	
	SortedSet* newSet = new SortedSet();
	
	for(IntNode* i = head; i != 0; i = i->next)
	{
		if((in(i->data)) && rhs.in(i->data))										// traverses through length of lhs and checks if any data equal rhs
		{
			newSet->add(i->data);
		}
	}
	return *newSet;
};

//mutators
void SortedSet::add(int data)
{
	
	int value = data;
    IntNode* insert = new IntNode(value);
    
    if(head == NULL)
    {
		head = insert;
		tail = insert;
		return;
    }
    for(IntNode* i = head; i != 0; i = i->next)
    {

		// takes care of single node case
		if(head == tail)
		{

		    if(value > i->data)
		    {
				i->next = insert;
				tail = insert;
				return;
		    }
		    else
		    {
				head = insert;
				insert->next = i;
				return;
		    }
		}

		//takes care of any other node case
		else if(value < head->data)         // adds node and makes it new head
		{
		    insert->next = head;
		    head = insert;
		    return;
		}
		
		else if(value > tail->data)        // adds node and makes it new tail
		{
		    tail->next = insert;
		    tail = insert;
		    return;
		}
		
		else if(value == i->data)       // returns if duplicate
		{
		    return;
		}
		
		else if((value > i->data) && (value < i->next->data))
		{
			insert->next = i->next;
			i->next = insert;
			return;
		}
		
    }
	
	return;
};

void SortedSet::push_front(int data)
{
	/* Override this function so that it inserts the value in data in the 
	proper position (in ascending order) only if the value does not already 
	exist in the set (no duplicates).

	In other words, this function should do exactly what add does. The reason 
	we are overriding this function is to ensure that the push_front from the 
	IntList is not inherited - a user of the SortedSet should not be able to 
	push just any value onto the front of the list.

	In fact, since this function should do exactly what add does, all it needs 
	to do is call the add function. */
	
	
	//call add function
	
	add(data);
	
	return;
};


void SortedSet::push_back(int data)
{
	/*Override this function so that it inserts the value in data in the 
	proper position (in ascending order) only if the value does not already 
	exist in the set (no duplicates).

	See specs for push_front above - the same rationale for overriding applies to this function. */
	add(data);
	
	return;
};


void SortedSet::insert_ordered(int data)
{
	/* Override this function so that it does not insert duplicates - again, 
	without invoking the remove_duplicates function.

	See specs for push_front above - the same rationale for overriding applies 
	to this function. */
	add(data);
	
	return;
};

SortedSet & SortedSet::operator|=(SortedSet &rhs)
{
	/* This function is the union-assign operator function. It returns a 
	union of the left and right operands, but also sets the left operand's 
	value to be that union as well. The return type is a non-const reference 
	to a SortedSet.

	See operator| function specs above. */
	
	for(IntNode* i = rhs.head; i != 0; i = i->next)
	{
		int val = i->data;
		this->add(val);
	}
	return *this;
};


SortedSet & SortedSet::operator&=(SortedSet &rhs)
{
	/* This function is the intersection-assign operator function. It returns 
	an intersection of the left and right operands, but also sets the left 
	operand's value to be that intersection as well. The return type is a 
	non-const reference to a SortedSet.

	See operator& specs above. */
	SortedSet* copy = new SortedSet();
	for(IntNode* i = head; i!= 0; i = i->next)
	{
		copy->add(i->data);
		
	}

	clear();
	SortedSet();
	
	for(IntNode* i = copy->head; i != 0; i = i->next)
	{
		if(copy->in(i->data) && rhs.in(i->data))
		{
			this->add(i->data);
		}
	}
	
	return *this;
};
