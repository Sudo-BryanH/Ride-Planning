#define CATCH_CONFIG_MAIN
#define REQUIRE(__VA_ARGS__...)

#include "catch.hpp"
#include "model/Person.h"
#include "model/Driver.h"
#include "model/PList.h"
#include "model/Node.h"
#include <string> 
#include <vector> 
#include <iostream>
#include <stdio.h>


using namespace std;

TEST_CASE("person constructor test", "[weight=1][part=construction]")
{
    Person alpha = Person("Ken",14, "male",  "PL", false);

    REQUIRE(alpha.getGroup() == "PL");
    REQUIRE(alpha.getName() == "Ken");
    REQUIRE(alpha.getGender() == "male");
    REQUIRE(alpha.getPhone() == 14);
    REQUIRE(alpha.getCanBus() == false);

    Person alpha1 = Person("Billy", 13);

    REQUIRE(alpha1.getGroup() == "none");
    REQUIRE(alpha1.getName() == "Billy");
    REQUIRE(alpha1.getGender() == "none");
    REQUIRE(alpha1.getPhone() == 13);
    REQUIRE(alpha1.getCanBus() == true);

}

TEST_CASE("Driver constructor test", "[weight=1][part=construction]")
{
    Driver beta = Driver("Rock", 12, 3, "male", "MM");

    REQUIRE(beta.getGroup() == "MM");
    REQUIRE(beta.getName() == "Rock");
    REQUIRE(beta.getGender() == "male");
    REQUIRE(beta.getPhone() == 12);
    REQUIRE(beta.getCanBus() == false);
    REQUIRE(beta.getCapacity() == 3);
}

TEST_CASE("person equality test", "[weight=1][part=construction]")
{
    Person alpha = Person("Ken",14, "male",  "PL", false);
    Person alpha1 = Person("Billy", 13);
    Person alpha2 = Person("Blly", 13);

    REQUIRE((alpha == alpha) == true);
    REQUIRE((alpha == alpha1) == false);
    REQUIRE((alpha2 == alpha1) == false);

    Driver beta = Driver("Rock", 12, 3, "male", "MM");
    
    REQUIRE((beta == beta) == true);
    REQUIRE((beta == alpha1) == false);
}

TEST_CASE("Driver get plist", "[weight = 1][part = construction]")
{
    Driver beta = Driver("Rock", 12, 3, "male", "MM");
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

    beta.setplist(&tester);

    REQUIRE(beta.getplist() == &tester);

    delete(n);
    delete(n1);



}