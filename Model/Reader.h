#ifndef READER_H
#define READER_H

#include "Person.h"
#include "json.hpp"

#include "Node.h"
#include "DNode.h"
#include <unordered_map>

using namespace std;
using json = nlohmann::json;


// This class will take a json object and use it to derive a hashmap for passengers and drivers
class Reader 
{

    public: 
    // Constructor. stores the json data file and create hashmaps for drivers and passengers
    Reader(json & data);

    // constructs an unordered_map for passengers
    void extractPassengers();

    // constructs an unordered_map for drivers
    void extractDrivers();

    //getters for data, pmap and dmap
    json getData();
    unordered_map<string, Node *> getPmap();

    unordered_map<string, DNode *> getDmap();


    private: 
    unordered_map<string, Node *> pmap;
    unordered_map<string, DNode *> dmap;
    
    json data;


};
#endif