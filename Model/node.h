
#ifndef PNODE_H
#define PNODE_H

#include "person.h"


using namespace std;

// Linked list structured storing persons. subclasses will be made for passengers and drivers pnode and dnode
class node
{
    public: 
    // Constructors 
    node();
    node(person p);

    // Destructor
    ~node();

    node * next;
    node * prev;

    // getters and setters for person's fields
    int getCapacity();

    private:
    person p;



};






#endif









