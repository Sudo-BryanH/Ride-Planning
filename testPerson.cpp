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