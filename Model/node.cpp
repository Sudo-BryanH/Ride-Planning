#include "Node.h"
#include <iostream>
#include <string> 
#include <vector> 

#include <stdio.h>


Node::Node()
{}

Node::Node(Person & p) : p(p), next(NULL), prev(NULL)
{}

Person Node::getPerson()
{
    return p;
}

bool Node::operator==(Node & d) const {

    return d.getPerson() == p;
}

