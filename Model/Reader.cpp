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
    unordered_map<string, Node*> pm;


    array passengers = json::parse("passengers");

    for(auto& a : passengers) {
        Person p = Person(json::parse("name"), json::parse("phone"), json::parse("gender"), json::parse("group"), json::parse("canBus"));
        Node * n =  new Node(p);

        if (pm.find(json::parse("group")) == pm.end())
        {
            Node * sentinel = new Node();
            sentinel->next = n;
            n->prev = sentinel;
            sentinel->prev = n;
            n->next = sentinel;

            pm.emplace(make_pair(json::parse("group"), sentinel));


        } else {

            Node * sentinel = pm.find(json::parse("group"))->second;
            sentinel->next = n;
            n->prev = sentinel;
            sentinel->prev = n;
            n->next = sentinel;

        }

        
    }

    pmap = pm;

}