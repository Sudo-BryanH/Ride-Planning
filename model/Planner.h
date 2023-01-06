#ifndef PLANNER_H
#define PLANNER_H

#include <string> 
#include <vector> 
#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <utility>

#include "Person.h"
#include "Driver.h"
#include "Node.h"
#include "PList.h"
#include "DNode.h"
#include "Publisher.h"

using namespace std;

// This class is in charge of the assignment of passengers and drivers. class is made to ensure ease of testing
class Planner
{

    public: 
    // constructors
   
    Planner(unordered_map<string, DNode *> & driverlist, unordered_map<string, Node *> & passengerlist, vector<string> & grouplist);

    //uses the two maps to assign passengers to drivers. Any remaining passengers/drivers will remain in the 
    void planride();


    

    // to iterate over an unordered map, use https://www.geeksforgeeks.org/set-cbegin-and-cend-function-in-c-stl/
    private: 

    unordered_map<string, DNode *> driverlist;
    unordered_map<string, Node *> passengerlist;
    vector<string> grouplist;
    Publisher pub;

        /*
        TODO for testing, make sure these are public and have getters for private fields
    Helper for planride. Based on capacity c of a driver, a plist will be used to group c passenger nodes and assign them to 
    a driver. 
    - After a driver is filled, it's assignment will be published
    - If at the end, driver(s) are not filled, it will remain untouched
    - if there are remaining passengers, or the passenger could bus, they will be moved to their respective genders or misc. 
    */
   void sort(unordered_map<string, DNode *>::iterator & dl, unordered_map<string, Node *>::iterator & pl);

    //helper to add node to the back of a linked list of a grouping
    void addNodeBack(Node * n, string destination);


    //helper to add node to the front of a linked list of a grouping
    void addNode(Node * n, string destination);

    /*
    Helper for planride. Uses similar mechanics to sort but applies to the special cases of gender
     It will identify a driver that is most optimal for it
    */
   void sortgen(string gender);
        /*
    Helper for planride. Uses similar mechanics to sort but applies to the special cases of gender and misc.
     It will identify a driver that is most optimal for it
    */
   void sortmisc();
};
#endif