#include "Reader.h"



Reader::Reader(json & data) : data(data)
{

    extractPassengers();
    extractDrivers();
}

unordered_map<string, Node *> Reader::getPmap()
{
    return pmap;
}

unordered_map<string, DNode *> Reader::getDmap()
{
    return dmap;
}

void Reader::extractDrivers()
{

}

void Reader::extractPassengers()
{
    
}