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

class planner
{

    public: 
    // constructors
    planner();
    planner(unordered_map<string, dnode> & driverlist, unordered_map<string, node> & passengerlist);

    //uses the two maps to assign passengers to drivers
    void planride();



    private: 

    unordered_map<string, dnode> driverlist;
    unordered_map<string, node> passengerlist;


};
#endif