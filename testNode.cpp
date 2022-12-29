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

}

TEST_CASE("node constructor test w/ passenger", "[weight=1][part=construction]")
{
    person p = person("Ken",14, "male",  "PL", false);
    node * n = new node(p);

    REQUIRE(n->next == NULL);
    REQUIRE(n->prev == NULL);
    //REQUIRE(n->getPerson() == p);
    REQUIRE(n->getPerson().getName() == "Ken");

}


TEST_CASE("dnode constructor test w/ driver", "[weight=1][part=construction]")
{
    driver p = driver("Ken",14, 3 , "male",  "PL");
    dnode * n = new dnode(p);

    REQUIRE(n->next == NULL);
    REQUIRE(n->prev == NULL);
    //REQUIRE(n->getDriver() == p);
    REQUIRE(n->getDriver().getName() == "Ken");
    REQUIRE(n->getDriver().getCapacity() == 3);
    

}

