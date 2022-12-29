#include "node.h"
#include <iostream>
#include <string> 
#include <vector> 

#include <stdio.h>


node::node()
{}

node::node(person p) : p(p), next(NULL), prev(NULL)
{}

person node::getPerson()
{
    return p;
}

