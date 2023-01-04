#ifndef DNODE_H
#define DNODE_H

#include "Node.h"

#include "Driver.h"
#include <string> 
#include <vector> 
#include <iostream>
#include <stdio.h>

using namespace std;

// extends node. the node class for drivers
class DNode : public Node
{
    public:
    DNode();
    DNode(Driver & d);

    Driver getPerson();

    DNode * next;
    DNode * prev;

    private: 
    Driver d;


};





#endif