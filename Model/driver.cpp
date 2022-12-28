#include <string> 
#include <vector> 
#include <iostream>
#include <stdio.h>
#include "driver.h"
#include "person.h"


driver::driver(string name, string gender, int phone, int capacity, string group = "N/A") : capacity(capacity), person(name, gender, phone, group)
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

