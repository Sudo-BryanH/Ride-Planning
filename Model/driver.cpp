#include <string> 
#include <vector> 
#include <iostream>
#include <stdio.h>
#include "driver.h"

driver::driver() {}

driver::driver(string name, int phone, int capacity, string gender, string group) : passengers(NULL), capacity(capacity), person(name, phone, gender, group, false)
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


// bool driver::operator==(driver p) {
//     return p == this && 
// }
