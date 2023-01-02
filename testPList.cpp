#define CATCH_CONFIG_MAIN
#define REQUIRE(__VA_ARGS__...)

#include "catch.hpp"
#include "Model/Person.h"

#include "Model/Node.h"
#include "Model/PList.h"
#include <string> 
#include <vector> 
#include <iostream>
#include <stdio.h>

TEST_CASE("PList constructor test with 1", "[weight=1][part=construction]")
{
    PList tester = PList(1);
    Node * sen = tester.getSentinel();

    REQUIRE(tester.getCapacity() == 1);
    REQUIRE(sen->next == tester.getSentinel());


    PList tester1 = PList(2);
    Node*sen1 = tester1.getSentinel();

    REQUIRE(tester1.getCapacity() == 2);
    REQUIRE(sen1->next == tester1.getSentinel());



}

TEST_CASE("PList add node", "[weight=1][part=construction]")
{
    PList tester = PList(2);
    Person alpha = Person("Ken",14, "male",  "PL", false);
    Person alpha1 = Person("Kenneth",16, "male",  "PL", true);
    Node * n = new Node(alpha);
    Node * n1 = new Node(alpha1);
    Node * sen = tester.getSentinel();

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