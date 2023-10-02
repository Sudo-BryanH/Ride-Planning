

#include "PList.h"
#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>

PList::PList()
{
}
PList::PList(int capacity) : cap(capacity)
{
    sentinel = new Node();
    last = sentinel;
    sentinel->next = sentinel;
    sentinel->prev = NULL;
}

void PList::addNode(Node *n)
{
    // cout << __LINE__ << endl;
    // //remove the node
    // Node * temp = n->prev;
    // cout << __LINE__ << endl;
    // n->prev->next = n->next;
    // cout << __LINE__ << endl;
    // n->next->prev = temp;

    // add node to plist

    n->next = sentinel;
    sentinel->prev = n;
    last->next = n;

    n->prev = last;

    last = n;

    cap--;
}

Node *PList::PList::getSentinel()
{
    return sentinel;
}

PList::~PList()
{

    last->next = NULL;
    sentinel->prev = NULL;
    deletion(sentinel);
}

void PList::deletion(Node *curr)
{
    if (curr)
    {
        Node *temp = curr->next;
        free(curr);
        deletion(temp);
    }
}

int PList::getCapacity()
{
    return cap;
}
