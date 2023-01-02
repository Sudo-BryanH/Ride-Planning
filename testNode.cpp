// CITATIONS: catch.hpp is copied from https://github.com/catchorg/Catch2.git

#define CATCH_CONFIG_MAIN
#define REQUIRE(__VA_ARGS__...)

#include "catch.hpp"
#include "Model/person.h"
#include "Model/driver.h"
#include "Model/node.h"
#include "Model/dnode.h"
#include <string> 
#include <vector> 
#include <iostream>
#include <stdio.h>


using namespace std;


TEST_CASE("default node constructor test", "[weight=1][part=construction]")
{
    node * n = new node();

    REQUIRE(n->next == NULL);
    REQUIRE(n->prev == NULL);
    //REQUIRE(n->getPerson() == NULL);
    delete(n);

}

TEST_CASE("node constructor test w/ passenger", "[weight=1][part=construction]")
{
    person p = person("Ken",14, "male",  "PL", false);
    node * n = new node(p);
    person a = n->getPerson();

    REQUIRE(n->next == NULL);
    REQUIRE(n->prev == NULL);
    REQUIRE(a == p);
    REQUIRE(n->getPerson().getName() == "Ken");
    delete(n);

}


TEST_CASE("dnode constructor test w/ driver", "[weight=1][part=construction]")
{
    driver p = driver("Ken",14, 3 , "male",  "PL");
    dnode * n = new dnode(p);

    REQUIRE(n->next == NULL);
    REQUIRE(n->prev == NULL);
    REQUIRE(n->getPerson() == p);
    REQUIRE(n->getPerson().getName() == "Ken");
    REQUIRE(n->getPerson().getCapacity() == 3);

    delete(n);
    

}

TEST_CASE("connecting nodes", "[weight=1][part=construction]")
{

    person p = person("Anakin", 14, "male",  "Jedi", false);
    node * n = new node(p);

    person q = person("Obi Wan", 15, "male", "Jedi", true);
    node * m = new node(q);

    n->next = m;
    m->prev = n;

    REQUIRE(n->next == m);
    REQUIRE(m->prev == n);

}

