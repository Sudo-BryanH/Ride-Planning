#ifndef DRIVER_H
#define DRIVER_H



#include "Person.h"
#include "PList.h"
#include <string> 
#include <vector> 
#include <iostream>
#include <stdio.h>


using namespace std;

// extends person class, represents a Driver and all its data.
class Driver : public Person
{
    public:
    Driver();
    // Constructor to declare the capacity, super class, and PList = NULL
    Driver(string name, int phone, int capacity, string gender = "none", string group = "none");
    
    //getters and setters for capacity
    int getCapacity();
    void setCapacity(int cap);
    PList * getplist();
    void setplist(PList * p);

    // bool operator==(Driver p);

    // TODO make a display method where when called will publish the Driver and the group to a .json file

    private:
    int capacity;
    PList * passengers;
    

};

#endif