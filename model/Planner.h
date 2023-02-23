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
    Planner();
    Planner(unordered_map<string, DNode * > & dmap, unordered_map<string, Node * > & pmap, vector<string> & glist);

    //uses the two maps to assign passengers to drivers. Any remaining passengers/drivers will remain in the 
    void planride();

    
    unordered_map<string, DNode *> getdmap();
    unordered_map<string, Node *> getpmap();
    vector<string> getGList();

    void addNodeBackPub(Node * n, string destination);
    void addNodePub(Node * n, string destination);
    void removeNodePub(Node * n);     
    void checkErasePmapPub(Node * pl, string group);    
    bool canPublishPub(DNode * d);  
    void assignGenPub(DNode * d);
    void sortPub(DNode * dl, Node* pl);

    void sortgenPub();

    // to iterate over an unordered map, use https://www.geeksforgeeks.org/set-cbegin-and-cend-function-in-c-stl/
    private: 

    unordered_map<string, DNode *> dmap;
    unordered_map<string, Node *> pmap;
    vector<string> grouplist;
    Publisher pub;


        /*

    Helper for planride. Based on capacity c of a driver, a pmap will be used to group c passenger nodes and assign them to 
    a driver. 
    - After a driver is filled, it's assignment will be published
    - If at the end, driver(s) are not filled, it will remain untouched
    - if there are remaining passengers, or the passenger could bus, they will be moved to their respective genders or misc. 
    */
  // void sort(unordered_map<string, DNode *>::iterator & dl, unordered_map<string, Node *>::iterator & pl);
    void sort(DNode * dl, Node* pl);
    //helper to add node to the back of a linked list of a grouping
    void addNodeBack(Node * n, string destination);
    

    //helper to add node to the front of a linked list of a grouping
    void addNode(Node * n, string destination);
    void addNode(DNode * n, string destination);

    //helper to remove a node from a list by reassigning neighbour pointers
    void removeNode(Node * n);
    void removeNode(DNode * n);

    // helper to decide if a driver should be published and publish if yes
    bool canPublish(DNode * d);

       // Assigns based on gender
    void assignGen(DNode * n);

    // helper to remove empty elements in the maps. calls erase to remove element from hashmap WITHOUT RESIZING
    void checkEraseDmap(DNode * dl, string group);
    void checkErasePmap(Node * pl, string group);

    // helper to decide if a node should be added to plist or to misc
    void assignOrReassign(Node * sen, PList * pl);

    /*
    Helper for planride. Uses similar mechanics to sort but applies to the special cases of gender
     It will identify a driver that is most optimal for it
    */
   void sortgen();
        /*
    Helper for planride. Uses similar mechanics to sort but applies to the special cases of gender and misc.
     It will identify a driver that is most optimal for it
    */
   void sortmisc();
};
#endif