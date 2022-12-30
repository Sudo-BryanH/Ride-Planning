#ifndef PLIST_H
#define PLIST_H



#include "node.h"
#include <string> 
#include <vector> 
#include <iostream>
#include <stdio.h>


using namespace std;

// class stored in the driver class. aside from the sentinel, this structure holds at most cap nodes
class plist 
{

    // TODO make tests for this class and fix person tests

    public:
    // constructor
    plist();
    plist(int capacity);

    // destructor
    ~plist();

    // Adds a node to the end of the last node, and this new node points to the sentinel. 
    void addNode(node* n);

    node * getSentinel();

    int getCapacity();

    private: 
    node * sentinel;
    node * last;
    int cap;




};

#endif