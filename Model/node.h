
#ifndef NODE_H
#define NODE_H

#include "person.h"


using namespace std;

// Linked list structured storing persons. subclasses will be made for passengers and drivers pnode and dnode
class node
{
    //TODO make tests for this class
    public: 
    // Constructors.  
    node();
    node(person p);

    person getPerson();
    node * next;
    node * prev;

    
    // int getCapacity(); this will be for the driver subclass

    private:
    person p;



};

#endif














