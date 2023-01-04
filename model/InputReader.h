#ifndef INPUTREADER_H
#define INPUTREADER_H

#include <unordered_map>
#include <string> 
#include <vector> 
#include <iostream>
#include <stdio.h>
#include <model>

using namespace std;

// This class stores two unordered maps to represent all passengers and drivers to be assigned as well as features to access and edit them
class InputReader
{

    public: 
    //Constructors: will initialize a pmap and dmap.
    InputReader();

    // functions to add a person or a driver to the pmap or dmap. If their group already exists for
    addToDmap(driver d);
    addToPmap(person p);

    // getters for pmap and dmap
    unordered_map<string, Node*> getPmap();
    unordered_map<string, DNode*> getDmap();



    private:
    // storage containers tha represent <group, passengers/drivers>. Default categories will be the genders and misc.
    unordered_map<string, Node*> pmap;
    unordered_map<string, DNode*> dmap;
    

};
#endif