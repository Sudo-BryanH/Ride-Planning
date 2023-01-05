#ifndef PUBLISHER_H
#define PUBLISHER_H


#include "DNode.h"
#include "Person.h"
#include "PList.h"
#include "Node.h"
#include "Driver.h"
#include <string> 
#include <vector> 
#include <iostream>
#include <stdio.h>

// This class prints out vital information of a DNode after it has been assigned
class Publisher
{

    public:
    Publisher();

    //Prints out assigned drivers
    void Publish(DNode * d);

    //Prints out remaining people
    void Publish(vector<Node *> n);


};
#endif