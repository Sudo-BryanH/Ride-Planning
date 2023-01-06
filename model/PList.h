#ifndef PLIST_H
#define PLIST_H



#include "Node.h"
#include <string> 
#include <vector> 
#include <iostream>
#include <stdio.h>


using namespace std;

// class stored in the Driver class. aside from the sentinel, this structure holds at most cap nodes
class PList 
{

    // TODO make tests for this class and fix Person tests

    public:
    // constructor
    PList();
    PList(int capacity);

    // destructor
    ~PList();

    // Adds a node to the end of the last node, and this new node points to the sentinel. 
    void addNode(Node* n);

    Node * getSentinel();

    int getCapacity();

    private: 
    Node * sentinel;
    Node * last;
    int cap;

    //helper for destructor
    void deletion(Node * curr);




};

#endif