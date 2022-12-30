

#include "plist.h"
#include <string> 
#include <vector> 
#include <iostream>
#include <stdio.h>

plist::plist(){

}
plist::plist(int capacity) : cap(capacity)
{
    sentinel = new node();
    last = sentinel;
    sentinel->next = sentinel;
    sentinel->prev = NULL;

}

void plist::addNode(node* n) 
{

    n->next = sentinel;
    last->next = n;
    n->prev = last;

    last = n;
    cap--;

}

node* plist::plist::getSentinel()
{
    return sentinel;
}

plist::~plist()
{
    
}

int plist::getCapacity()
{
    return cap;
}

