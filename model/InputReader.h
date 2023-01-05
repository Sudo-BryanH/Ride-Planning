#ifndef INPUTREADER_H
#define INPUTREADER_H

#include <unordered_map>
#include <string> 
#include <vector> 
#include <iostream>
#include <stdio.h>
#include "Person.h"
#include "Driver.h"
#include "DNode.h"
#include "Node.h"

using namespace std;

// This class stores two unordered maps to represent all passengers and drivers to be assigned as well as features to access and edit them
class InputReader
{

    public: 
    //Constructors: will initialize a pmap and dmap.
    InputReader();

    // functions to add a person or a driver to the pmap or dmap. If their group already exists for
    void addToDmap(Driver & d);
    void addToPmap(Person & p);

    // getters for grouplist, pmap and dmap
    unordered_map<string, Node*> getPmap();
    unordered_map<string, DNode*> getDmap();
    vector<string> getGroupList();

    private:
    // storage containers tha represent <group, passengers/drivers>. Default categories will be the genders and misc.
    unordered_map<string, Node*> pmap;
    unordered_map<string, DNode*> dmap;

    //list of all groups
    vector<string> grouplist;

    // adds a node to the linked list
    void addDNode(DNode * at, DNode * n);
    void addNode(Node * at, Node * n);

};
#endif