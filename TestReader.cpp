#define CATCH_CONFIG_MAIN
#define REQUIRE(__VA_ARGS__...)

#include "/Users/a113/Dropbox (VCS)/My Mac (Bryans-MacBook-Air.local)/Documents/Personal_Projects/Ride-Planning/json.hpp"
#include "catch.hpp"
#include "Model/Person.h"
#include "Model/Driver.h"
#include "Model/Node.h"
#include "Model/DNode.h"
#include "Model/Reader.h"
#include <string> 
#include <unordered_map>
#include <vector> 
#include <iostream>
#include <stdio.h>
#include <iomanip>



using namespace std;
using json = nlohmann::json;

TEST_CASE("Reader constructor", "[weight=1][part=construction]")
{
    cout << __LINE__ << endl;
    std::ifstream f("testinput.json");

    cout << __LINE__ << endl;
    json data = json::parse(f);

    Reader r = Reader(data);

    cout << __LINE__ << endl;
    REQUIRE(data == r.getData());

}

TEST_CASE("extract passengers test", "[weight=1][part=construction]")
{

    cout << __LINE__ << endl;
    std::ifstream f("testinput.json");

    cout << __LINE__ << endl;
    json data = json::parse(f);

    cout << __LINE__ << endl;
    Reader r = Reader(data);

    cout << __LINE__ << endl;
    r.extractPassengers();

    unordered_map<string, Node*> testmap;

    Person p1 = Person("p1", 604, "male", "PL", false);
    Person p2 = Person("p2", 778, "female", "SU", false);
    Person p3 = Person("p3", 672, "male", "PL", true);

    cout << __LINE__ << endl;
    Node n1 = Node(p1);
    Node n2 = Node(p2);
    Node n3 = Node(p3);

    Node *PL = r.getPmap().find("PL")->second;
    Node *SU = r.getPmap().find("PL")->second;

    Node u1 = *(PL->next);
    Node u2 = *(SU->next);
    Node u3 = *(PL->next->next);

    REQUIRE(n1.getPerson() == u1.getPerson());
    REQUIRE(n2.getPerson() == u2.getPerson());
    REQUIRE(n3.getPerson() == u3.getPerson());

}