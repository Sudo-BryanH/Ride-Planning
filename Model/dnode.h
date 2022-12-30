#ifndef DNODE_H
#define DNODE_H

#include "node.h"

#include "driver.h"
#include <string> 
#include <vector> 
#include <iostream>
#include <stdio.h>

using namespace std;

// extends node. the node class for drivers
class dnode : public node
{
    public:
    dnode();
    dnode(driver & d);

    driver getPerson();

    private: 
    driver d;


};





#endif