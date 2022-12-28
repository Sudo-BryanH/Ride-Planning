#define CATCH_CONFIG_MAIN
#define REQUIRE(__VA_ARGS__...) 

#include "catch.hpp"
#include "Model/person.h"
#include "Model/driver.h"
#include <string> 
#include <vector> 
#include <iostream>
#include <stdio.h>


using namespace std;

TEST_CASE("person constructor test", "[weight=1][part=construction]")
{
    person alpha = person("Ken", "male", 14, "PL");
    driver beta = driver("Rock", "male", 12, 3, "MM");

    REQUIRE(alpha.getGroup == "PL");


}