
#ifndef NODE_H
#define NODE_H

#include "Person.h"


using namespace std;

// Linked list structured storing persons. subclasses will be made for passengers and drivers pnode and DNode
class Node
{
    //TODO make tests for this class
    public: 
    // Constructors.  
    Node();
    Node(Person & p);

    Person getPerson();
    Node * next;
    Node * prev;

    bool operator==(Node & d) const;
    // int getCapacity(); this will be for the Driver subclass

    private:
    Person p;



};

#endif














