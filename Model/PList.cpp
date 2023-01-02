

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

