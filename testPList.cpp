#define CATCH_CONFIG_MAIN
#define REQUIRE(__VA_ARGS__...)

#include "catch.hpp"
#include "Model/person.h"

#include "Model/node.h"
#include "Model/plist.h"
#include <string> 
#include <vector> 
#include <iostream>
#include <stdio.h>

TEST_CASE("plist constructor test with 1", "[weight=1][part=construction]")
{
    plist tester = plist(1);
    node * sen = tester.getSentinel();

    REQUIRE(tester.getCapacity() == 1);
    REQUIRE(sen->next == tester.getSentinel());


    plist tester1 = plist(2);
    node*sen1 = tester1.getSentinel();

    REQUIRE(tester1.getCapacity() == 2);
    REQUIRE(sen1->next == tester1.getSentinel());



}

TEST_CASE("plist add node", "[weight=1][part=construction]")
{
    plist tester = plist(2);
    person alpha = person("Ken",14, "male",  "PL", false);
    person alpha1 = person("Kenneth",16, "male",  "PL", true);
    node * n = new node(alpha);
    node * n1 = new node(alpha1);
    node * sen = tester.getSentinel();

    REQUIRE(tester.getCapacity() == 2);
    REQUIRE(sen->next == tester.getSentinel());


    tester.addNode(n);


    REQUIRE(tester.getCapacity() == 1);
    REQUIRE(sen->next == n);
    REQUIRE(n->next == sen);
    REQUIRE(n->prev == sen);

    tester.addNode(n1);


    REQUIRE(tester.getCapacity() == 0);
    REQUIRE(sen->next == n);
    REQUIRE(n->next == n1);
    REQUIRE(n->prev == sen);
    REQUIRE(n1->prev ==n);
    REQUIRE(n1->next == sen);



    delete(n);
    delete(n1);
}