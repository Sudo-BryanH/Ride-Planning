#define CATCH_CONFIG_MAIN
#define REQUIRE(__VA_ARGS__...)

#include "catch.hpp"
#include "model/Person.h"
#include "model/Driver.h"
#include "model/InputReader.h"
#include "model/Node.h"
#include "model/DNode.h"
#include <unordered_map>
#include <string> 
#include <vector> 
#include <iostream>
#include <stdio.h>

TEST_CASE("BASIC CONSTRUCTOR TEST", "[weight = 1][part=construction]")
{
    // Person alpha = Person("Ken",14, "male",  "PL", false);
    // Person alpha1 = Person("Kim",14, "female",  "AW", false);


    // Driver beta = Driver("Rock", 12, 3, "male", "MM");

    InputReader tester = InputReader();

    // tester.addToPmap(alpha);
    // tester.addToPmap(alpha1);
    // tester.addToDmap(beta);

    unordered_map<string, Node*> pm = tester.getPmap();
    unordered_map<string, DNode*> dm = tester.getDmap();

    // REQUIRE(pm.find("PL")->second->getPerson() == alpha);
    // REQUIRE(dm.find("MM")->second->getPerson() == beta);
    REQUIRE(pm.count("misc") != 0);
    REQUIRE(pm.count("male") != 0);
    REQUIRE(pm.count("female") != 0);
    REQUIRE(pm.size() == 3);

    REQUIRE(dm.count("misc") != 0);
    REQUIRE(dm.count("male") != 0);
    REQUIRE(dm.count("female") != 0);
    REQUIRE(dm.size() == 3);



}

TEST_CASE("BASIC ADD TO TEST", "[weight = 1][part=construction]")
{
    Person alpha = Person("Ken",14, "male",  "PL", false);
    Person alpha1 = Person("Kim",14, "female",  "AW", false);


    Driver beta = Driver("Rock", 12, 3, "male", "MM");

    InputReader tester = InputReader();

    tester.addToPmap(alpha);
    //tester.addToPmap(alpha1);
    tester.addToDmap(beta);

    unordered_map<string, Node*> pm = tester.getPmap();
    unordered_map<string, DNode*> dm = tester.getDmap();

    REQUIRE(pm.find("PL")->second->next->getPerson() == alpha);
    REQUIRE(dm.find("MM")->second->next->getPerson() == beta);
    REQUIRE(pm.count("misc") != 0);
    REQUIRE(pm.count("male") != 0);
    REQUIRE(pm.count("female") != 0);
    REQUIRE(pm.size() == 4);

    REQUIRE(dm.count("misc") != 0);
    REQUIRE(dm.count("male") != 0);
    REQUIRE(dm.count("female") != 0);
    REQUIRE(dm.size() == 4);



}

TEST_CASE("MULTI-PASSENGER ADD TO TEST", "[weight = 1][part=construction]")
{
    Person alpha = Person("Ken",14, "male",  "PL", false);
    Person alpha1 = Person("Kim",14, "female",  "AW", false);


    Driver beta = Driver("Rock", 12, 3, "male", "MM");

    InputReader tester = InputReader();

    tester.addToPmap(alpha);
    tester.addToPmap(alpha1);
    tester.addToDmap(beta);

    unordered_map<string, Node*> pm = tester.getPmap();
    unordered_map<string, DNode*> dm = tester.getDmap();

    REQUIRE(pm.find("PL")->second->next->getPerson() == alpha);
    REQUIRE(pm.find("AW")->second->next->getPerson() == alpha1);
    REQUIRE(dm.find("MM")->second->next->getPerson() == beta);
    REQUIRE(pm.count("misc") != 0);
    REQUIRE(pm.count("male") != 0);
    REQUIRE(pm.count("female") != 0);
    REQUIRE(pm.size() == 5);

    REQUIRE(dm.count("misc") != 0);
    REQUIRE(dm.count("male") != 0);
    REQUIRE(dm.count("female") != 0);
    REQUIRE(dm.size() == 4);



}

TEST_CASE("MULTI-PASSENGER SAME GROUP ADD TO TEST", "[weight = 1][part=construction]")
{
    Person alpha = Person("Ken",14, "male",  "PL", false);
    Person alpha1 = Person("Kim",14, "female",  "AW", false);
    Person alpha2 = Person("Al",14, "male",  "PL", false);


    Driver beta = Driver("Rock", 12, 3, "male", "MM");

    InputReader tester = InputReader();

    tester.addToPmap(alpha);
    tester.addToPmap(alpha1);
    tester.addToDmap(beta);

    unordered_map<string, Node*> pm = tester.getPmap();
    unordered_map<string, DNode*> dm = tester.getDmap();

    REQUIRE(pm.find("PL")->second->next->getPerson() == alpha);
    REQUIRE(pm.find("AW")->second->next->getPerson() == alpha1);
    REQUIRE(pm.find("PL")->second->next->next->getPerson() == alpha2);
    REQUIRE(dm.find("MM")->second->next->getPerson() == beta);
    REQUIRE(pm.count("misc") != 0);
    REQUIRE(pm.count("male") != 0);
    REQUIRE(pm.count("female") != 0);
    REQUIRE(pm.size() == 5);

    REQUIRE(dm.count("misc") != 0);
    REQUIRE(dm.count("male") != 0);
    REQUIRE(dm.count("female") != 0);
    REQUIRE(dm.size() == 4);



}