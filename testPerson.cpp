#define CATCH_CONFIG_MAIN
#define REQUIRE(__VA_ARGS__...)

#include "catch.hpp"
#include "Model/person.h"
#include "Model/driver.h"
#include "Model/plist.h"
#include "Model/node.h"
#include <string> 
#include <vector> 
#include <iostream>
#include <stdio.h>


using namespace std;

TEST_CASE("person constructor test", "[weight=1][part=construction]")
{
    person alpha = person("Ken",14, "male",  "PL", false);

    REQUIRE(alpha.getGroup() == "PL");
    REQUIRE(alpha.getName() == "Ken");
    REQUIRE(alpha.getGender() == "male");
    REQUIRE(alpha.getPhone() == 14);
    REQUIRE(alpha.getCanBus() == false);

    person alpha1 = person("Billy", 13);

    REQUIRE(alpha1.getGroup() == "none");
    REQUIRE(alpha1.getName() == "Billy");
    REQUIRE(alpha1.getGender() == "none");
    REQUIRE(alpha1.getPhone() == 13);
    REQUIRE(alpha1.getCanBus() == true);

}

TEST_CASE("driver constructor test", "[weight=1][part=construction]")
{
    driver beta = driver("Rock", 12, 3, "male", "MM");

    REQUIRE(beta.getGroup() == "MM");
    REQUIRE(beta.getName() == "Rock");
    REQUIRE(beta.getGender() == "male");
    REQUIRE(beta.getPhone() == 12);
    REQUIRE(beta.getCanBus() == false);
    REQUIRE(beta.getCapacity() == 3);
}

TEST_CASE("person equality test", "[weight=1][part=construction]")
{
    person alpha = person("Ken",14, "male",  "PL", false);
    person alpha1 = person("Billy", 13);
    person alpha2 = person("Blly", 13);

    REQUIRE((alpha == alpha) == true);
    REQUIRE((alpha == alpha1) == false);
    REQUIRE((alpha2 == alpha1) == false);

    driver beta = driver("Rock", 12, 3, "male", "MM");
    
    REQUIRE((beta == beta) == true);
    REQUIRE((beta == alpha1) == false);
}

TEST_CASE("driver get plist", "[weight = 1][part = construction]")
{
    driver beta = driver("Rock", 12, 3, "male", "MM");
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

    beta.setplist(&tester);

    REQUIRE(beta.getplist() == &tester);

    delete(n);
    delete(n1);



}