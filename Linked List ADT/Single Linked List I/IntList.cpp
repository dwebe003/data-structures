#include <iostream>
#include "IntList.h"
using namespace std;

IntList::IntList()
{
    head = 0;
    tail = 0;
    return;
}

IntList::~IntList()
{
    if(head != NULL)
    {
        for(IntNode* i = head->next; i != 0; i = i->next)
        {
            delete i;
        }
        delete head;
    }
    return;
}

void IntList::push_front(int value)
{
    if(head == 0)
    {
        head = tail = new IntNode(value);
        return;
    }
    else if(head == tail)
    {
        head = new IntNode(value);
        head->next = tail;
        return;
    }
    else
    {
        IntNode* tmp = new IntNode(value);  //possibly fix
        tmp->next = head;
        head = tmp;
        tmp = 0;
        return;
    }
}

void IntList::pop_front()
{
    if(head == 0)
    {
        return;
    }
    else if(head == tail)
    {
        delete head;
        head = 0;
        return;
    }
    else
    {
        IntNode* tmp = head->next;
        delete head;
        head = tmp;
        tmp = 0;
        return;
    }    
}

void IntList::display() const
{

    for(IntNode* i = head; i != 0; i = i->next)
    {
        if(i != tail)
        {
            cout << i->data << " ";
        }
        else
        {
            cout << i->data;
        }
    }
    return;
}

bool IntList::empty() const
{
    if(head == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void IntList::push_back(int value)
{
    IntNode* n = new IntNode(value);
    if(head == 0)
    {
        head = tail = new IntNode(value);
        return;
    }
    else if(head == tail)
    {
        head->next = n;
        tail = n;
        return;
    }
    else
    {
        tail->next = n;
        tail = n;
        /*IntNode* tmp = new IntNode(value); 
        tail->next = tmp;
        tail = tmp;
        tmp = 0; */
        return;
    }
}

void IntList::clear()
{

    if(head != NULL)
    {
        while(head->next != 0)
        {
            delete head->next;
        }
        delete head;
    }
    return;
}

void IntList::selection_sort()
{
    if(head == NULL)
    {
        return;
    }
    for(IntNode* i = head; i != tail; i = i->next)
    {
        for(IntNode* j = i->next; j != 0; j = j->next)
        {
            if(i->data > j->data)
            {
                int tmp = j->data;
                j->data = i->data;
                i->data = tmp;
            }
        }
    }
    return;
}

void IntList::remove_duplicates()
{
    /*IntNode* cur;
    int count = 0, count2 = 0;
    if(head == 0)
    {
        return;
    }
    for(IntNode* i = head; i != 0; i = i->next)
    {
        for(IntNode* j = i->next; j != 0; j = j->next)
        {
            if(i->data == j->data)
            {
                if(count == 0)
                {
                    cur = i;
                }
                if(j == tail)
                {
                    cur->next = 0;
                    delete j;
                    tail = cur;
                }
                else
                {
                    cur->next = j->next;
                    delete j;
                }
                count2++;
            }
            count++;
            if(count2 == 0)
            {
                cur = j;
            }
        }
    }*/

    IntNode *ptr1, *ptr2, *dupe, *ptr3;
    ptr1 = head;
    int count = 0;

    while(ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;
     
        while(ptr2->next != NULL)
        {
            ptr3 = head;
            if(ptr1->data == ptr2->next->data)
            {
                  count++;
                  dupe = ptr2->next;
                  ptr2->next = ptr2->next->next;
                  delete dupe;
                  while(ptr3->next != 0)
                  {
                        ptr3 = ptr3->next;
                  }
                  tail = ptr3;
                  if(count >= 2) //2 or more dupes were removed
                  {
                      
                  }
            }
            else
            {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
    return;
}

void IntList::insert_ordered(int value)
{
    IntNode* insert = new IntNode(value);
    if(head == NULL)
    {
        push_front(value);
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
        else if(value < head->data)
        {
            insert->next = head;
            head = insert;
            return;
        }
        
        else if(value >= tail->data)
        {
            tail->next = insert;
            tail = insert;
            return;
        }
        
        else if(value == i->data)
        {
            insert->next = i->next;
            i->next = insert;
            return;
        }
        else if((value > i->data) && (value < i->next->data))
        {
            IntNode* tmp = i->next;
            i->next = insert;
            insert->next = tmp;
            return;
        }
        
        /*IntNode* afterInsert = i->next;
        if(value > i->data)
        {
            if(value < afterInsert->data)
            {
                //insert after *i values
                IntNode* insertedNode = new IntNode(value);
                i->next = insertedNode;
                insertedNode->next = afterInsert;
            }
        }*/
    }
    cout << endl << "head: " << head->data << "  tail: " << tail->data << endl;
    return;
}

IntList& IntList::operator=(const IntList &rhs)
{
    int size = 0;
    
    if(this != &rhs)
    {
        for(IntNode* i = rhs.head; i != 0; i=i->next)
        {
            size++;
        }
        if(size == 0)
        {
            head = NULL;
        }
        else
        {
            IntNode* origPtr;
            IntNode* lastPtr;
            
            origPtr = rhs.head;
            lastPtr = new IntNode(origPtr->data);
            head = lastPtr;
            if(size == 1)
            {
                tail = lastPtr;
                return *this;
            }
            IntNode* tmp;
            origPtr = origPtr->next;
            while(origPtr != NULL)
            {
                tmp = new IntNode(origPtr->data);
                lastPtr->next = tmp;
                lastPtr = lastPtr->next;
                
                origPtr = origPtr->next;
            }
            tail = lastPtr;
        }
    }

    return *this;
}

IntList::IntList(const IntList &cpy)
{
    int size = 0;
    for(IntNode* i = cpy.head; i != 0; i=i->next)
    {
        size++;
    }
    if(size == 0)
    {
        head = NULL;
    }
    else
    {
        IntNode* origPtr;
        IntNode* lastPtr;
        
        origPtr = cpy.head;
        lastPtr = new IntNode(origPtr->data);
        head = lastPtr;
        if(size == 1)
        {
            tail = lastPtr;
            return;
        }
        IntNode* tmp;
        origPtr = origPtr->next;
        while(origPtr != NULL)
        {
            tmp = new IntNode(origPtr->data);
            lastPtr->next = tmp;
            lastPtr = lastPtr->next;
            
            origPtr = origPtr->next;
        }
        tail = lastPtr;
    }

    return;
    
}

ostream &operator<<(ostream &out, const IntList &rhs)
{
    for(IntNode* i = rhs.head; i != 0; i = i->next)
    {
        if(i != rhs.tail)
        {
            out << i->data << " ";
        }
        else
        {
            out << i->data;
        }
    }
    return out;
}