#ifndef PLANNER_H
#define PLANNER_H

#include <string> 
#include <vector> 
#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <utility>

#include "person.h"
#include "driver.h"
#include "node.h"
#include "plist.h"
#include "dnode.h"

using namespace std;

// This class is in charge of the assignment of passengers and drivers. class is made to ensure ease of testing
class planner
{

    public: 
    // constructors
    planner();
    planner(unordered_map<string, dnode> & driverlist, unordered_map<string, node> & passengerlist, vector<string> & grouplist);

    //uses the two maps to assign passengers to drivers
    void planride();


    // to iterate over an unordered map, use https://www.geeksforgeeks.org/set-cbegin-and-cend-function-in-c-stl/
    private: 

    unordered_map<string, dnode> driverlist;
    unordered_map<string, node> passengerlist;
    vector<string> grouplist;


};
#endif