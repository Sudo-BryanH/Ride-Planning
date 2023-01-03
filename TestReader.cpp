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
    std::ifstream f("testinput.json");
    json data = json::parse(f);

    Reader r = Reader(data);

    REQUIRE(data == r.getData());

}

TEST_CASE("extract passengers test", "[weight=1][part=construction]")
{
    std::ifstream f("testinput.json");
    json data = json::parse(f);
    Reader r = Reader(data);
    r.extractPassengers();

    unordered_map<string, Node*> testmap;

    Person p1 = Person("p1", 604, "male", "PL", false);
    Person p2 = Person("p2", 778, "female", "SU", false);
    Person p3 = Person("p3", 672, "male", "PL", true);

    Node * n1 = new Node(p1);
    Node * n2 = new Node(p2);
    Node * n3 = new Node(p3);

    Node * PL = r.getPmap().find("PL")->second;
    Node * SU = r.getPmap().find("PL")->second;

    REQUIRE(*n1 == *PL->next);
    REQUIRE(*n2 == *SU->next);
    REQUIRE(*n3 == *PL->next->next);

}