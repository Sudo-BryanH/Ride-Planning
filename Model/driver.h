#ifndef DRIVER_H
#define DRIVER_H



#include "person.h"
#include <string> 
#include <vector> 
#include <iostream>
#include <stdio.h>
// #include <unordered_map>

using namespace std;

// extends person class, represents a driver and all its data.
class driver : public person
{
    public:
    int whatever();
    driver(string name, int phone, int capacity, string gender = "none", string group = "none");
    
    //getters and setters for capacity
    int getCapacity();
    void setCapacity(int cap);

    private:
    int capacity;
    

};

#endif