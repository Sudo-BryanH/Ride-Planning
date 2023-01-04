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
    Person alpha = Person("Ken",14, "male",  "PL", false);
    Person alpha1 = Person("Kim",14, "female",  "AW", false);


    Driver beta = Driver("Rock", 12, 3, "male", "MM");

    InputReader tester = InputReader();

    tester.addToPmap(alpha);
    // tester.addToPmap(alpha1);
    tester.addToDmap(beta);

    unordered_map<string, Node*> pm = tester.getPmap();
    unordered_map<string, DNode*> dm = tester.getDmap();

    REQUIRE(pm.find("PL")->second->getPerson() == alpha);
    REQUIRE(dm.find("MM")->second->getPerson() == beta);
    REQUIRE(pm.count("misc") != 0);


}