

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
    cout << __LINE__ << endl;
    //remove the node
    Node * temp = n->prev;
    cout << __LINE__ << endl;
    n->prev->next = n->next;
    cout << __LINE__ << endl;
    n->next->prev = temp;

    //add node to plist
    cout << __LINE__ << endl;
    n->next = sentinel;
    cout << __LINE__ << endl;
    last->next = n;
    cout << __LINE__ << endl;
    n->prev = last;
cout << __LINE__ << endl;
    last = n;


    cap--;

}

Node* PList::PList::getSentinel()
{
    return sentinel;
}

PList::~PList()
{

    last->next = NULL;
    sentinel->prev = NULL;
    deletion(sentinel);
}

void PList::deletion(Node * curr)
{
    if (curr)
    {
        Node * temp = curr->next;
        deletion(temp);
    }
}

int PList::getCapacity()
{
    return cap;
}

