#ifndef DRIVER_H
#define DRIVER_H


#include "person.h"
#include <string> 
#include <vector> 
#include <iostream>
#include <stdio.h>
// #include <unordered_map>

using namespace std;

class driver : public person
{
    public:
    int whatever();
    driver(string name, string gender, int phone, int capacity, string group = "N/A");

    private:
    int capacity;


};

#endif