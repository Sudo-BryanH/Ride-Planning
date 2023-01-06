

#include "PList.h"
#include <string> 
#include <vector> 
#include <iostream>
#include <stdio.h>

PList::PList(){

}
PList::PList(int capacity) : cap(capacity)
{
    sentinel = new Node();
    last = sentinel;
    sentinel->next = sentinel;
    sentinel->prev = NULL;

}

void PList::addNode(Node* n) 
{

    //remove the node
    Node * temp = n->prev;
    n->prev->next = n->next;
    n->next->prev = temp;

    //add node to plist
    n->next = sentinel;
    last->next = n;
    n->prev = last;

    last = n;


    cap--;

}

Node* PList::PList::getSentinel()
{
    return sentinel;
}

PList::~PList()
{
    
}

int PList::getCapacity()
{
    return cap;
}

