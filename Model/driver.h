#ifndef DRIVER_H
#define DRIVER_H



#include "person.h"
#include "plist.h"
#include <string> 
#include <vector> 
#include <iostream>
#include <stdio.h>


using namespace std;

// extends person class, represents a driver and all its data.
class driver : public person
{
    public:
    driver();
    // Constructor to declare the capacity, super class, and plist = NULL
    driver(string name, int phone, int capacity, string gender = "none", string group = "none");
    
    //getters and setters for capacity
    int getCapacity();
    void setCapacity(int cap);
    plist * getplist();
    void setplist(plist * p);

    // bool operator==(driver p);

    // TODO make a display method where when called will publish the driver and the group to a .json file

    private:
    int capacity;
    plist * passengers;
    

};

#endif