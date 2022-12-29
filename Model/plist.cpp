

#include "plist.h"
#include <string> 
#include <vector> 
#include <iostream>
#include <stdio.h>


plist::plist(int capacity) : cap(capacity)
{
    sentinel = new node();
    last = sentinel;

}

void plist::addNode(node* n) 
{

    n->next = sentinel;
    n->prev = last;
    last = n;
    cap--;

}

