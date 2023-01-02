// CITATIONS: catch.hpp is copied from https://github.com/catchorg/Catch2.git

#define CATCH_CONFIG_MAIN
#define REQUIRE(__VA_ARGS__...)

#include "catch.hpp"
#include "Model/Person.h"
#include "Model/Driver.h"
#include "Model/Node.h"
#include "Model/DNode.h"
#include <string> 
#include <vector> 
#include <iostream>
#include <stdio.h>


using namespace std;


TEST_CASE("default node constructor test", "[weight=1][part=construction]")
{
    Node * n = new Node();

    REQUIRE(n->next == NULL);
    REQUIRE(n->prev == NULL);
    //REQUIRE(n->getPerson() == NULL);
    delete(n);

}

TEST_CASE("node constructor test w/ passenger", "[weight=1][part=construction]")
{
    Person p = Person("Ken",14, "male",  "PL", false);
    Node * n = new Node(p);
    Person a = n->getPerson();

    REQUIRE(n->next == NULL);
    REQUIRE(n->prev == NULL);
    REQUIRE(a == p);
    REQUIRE(n->getPerson().getName() == "Ken");
    delete(n);

}


TEST_CASE("DNode constructor test w/ Driver", "[weight=1][part=construction]")
{
    Driver p = Driver("Ken",14, 3 , "male",  "PL");
    DNode * n = new DNode(p);

    REQUIRE(n->next == NULL);
    REQUIRE(n->prev == NULL);
    REQUIRE(n->getPerson() == p);
    REQUIRE(n->getPerson().getName() == "Ken");
    REQUIRE(n->getPerson().getCapacity() == 3);

    delete(n);
    

}

TEST_CASE("connecting nodes", "[weight=1][part=construction]")
{

    Person p = Person("Anakin", 14, "male",  "Jedi", false);
    Node * n = new Node(p);

    Person q = Person("Obi Wan", 15, "male", "Jedi", true);
    Node * m = new Node(q);

    n->next = m;
    m->prev = n;

    REQUIRE(n->next == m);
    REQUIRE(m->prev == n);

}

