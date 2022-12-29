#include "node.h"
#include <iostream>
#include <string> 
#include <vector> 

#include <stdio.h>


node::node() :  next(this), prev(this)
{}

node::node(person p) : p(p), next(NULL), prev(NULL)
{}

