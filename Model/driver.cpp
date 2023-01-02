#include <string> 
#include <vector> 
#include <iostream>
#include <stdio.h>
#include "Driver.h"

Driver::Driver() {}

Driver::Driver(string name, int phone, int capacity, string gender, string group) : passengers(NULL), capacity(capacity), Person(name, phone, gender, group, false)
{
}    

int Driver::getCapacity()
{
    return capacity;
}

void Driver::setCapacity(int cap)
{
    capacity = cap;
}

PList * Driver::Driver::getplist()
{

    return passengers;

}

void Driver::setplist(PList * p)
{

    passengers = p;
}


// bool Driver::operator==(Driver p) {
//     return p == this && 
// }
