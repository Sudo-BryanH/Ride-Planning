#include <string> 
#include <vector> 
#include <iostream>
#include <stdio.h>
#include "driver.h"
#include "person.h"


driver::driver(string name,  int phone, int capacity, string gender, string group) : capacity(capacity), person(name, phone, gender, group)
{

}

int driver::getCapacity()
{
    return capacity;
}

void driver::setCapacity(int cap)
{
    capacity = cap;
}

