#define CATCH_CONFIG_MAIN
#define REQUIRE(__VA_ARGS__...)

#include "catch.hpp"



#include <string> 
#include <vector> 
#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <utility>

#include "model/Person.h"
#include "model/Driver.h"
#include "model/Node.h"
#include "model/PList.h"
#include "model/DNode.h"
// #include "model/Publisher.h"
#include "model/InputReader.h"
#include "model/Planner.h"





TEST_CASE("test planner constructor", "[weight = 1][part construction]")
{
    Person alpha = Person("Ken",14, "male",  "PL", false);
    Person alpha1 = Person("Kim",14, "female",  "AW", false);


    Driver beta = Driver("Rock", 12, 3, "male", "MM");

    InputReader ir = InputReader();

    ir.addToPmap(alpha);
    ir.addToPmap(alpha1);
    ir.addToDmap(beta);

    unordered_map<string, Node*> pm = ir.getPmap();
    unordered_map<string, DNode*> dm = ir.getDmap();
    vector<string> gl = ir.getGroupList();

    Planner tester = Planner(dm, pm, gl);

    REQUIRE(tester.getDList() == dm);
    REQUIRE(tester.getPList() == pm);
    REQUIRE(tester.getGList() == gl);
    

}

TEST_CASE("test add node", "[weight = 1][part construction]")
{
    Person alpha = Person("Ken",14, "male",  "PL", false);
    Person alpha1 = Person("Kim",14, "female",  "AW", false);
    Person alpha2 = Person("Al",14, "male",  "PL", false);


    Driver beta = Driver("Rock", 12, 3, "male", "MM");

    InputReader ir = InputReader();

    ir.addToPmap(alpha);
    ir.addToPmap(alpha1);
    ir.addToDmap(beta);

    unordered_map<string, Node*> pm = ir.getPmap();
    unordered_map<string, DNode*> dm = ir.getDmap();
    vector<string> gl = ir.getGroupList();

    Planner tester = Planner(dm, pm, gl);

    Node * n = new Node(alpha2);

    tester.addNodePub(n, "PL");
    
    REQUIRE(tester.getPList().find("PL")->second->next == n);
    
    delete n;
}

TEST_CASE("test add back node", "[weight = 1][part construction]")
{
    Person alpha = Person("Ken",14, "male",  "PL", false);
    Person alpha1 = Person("Kim",14, "female",  "AW", false);
    Person alpha2 = Person("Al",14, "male",  "PL", false);


    Driver beta = Driver("Rock", 12, 3, "male", "MM");

    InputReader ir = InputReader();

    ir.addToPmap(alpha);
    ir.addToPmap(alpha1);
    ir.addToDmap(beta);

    unordered_map<string, Node*> pm = ir.getPmap();
    unordered_map<string, DNode*> dm = ir.getDmap();
    vector<string> gl = ir.getGroupList();

    Planner tester = Planner(dm, pm, gl);

    Node * n = new Node(alpha2);

    tester.addNodeBackPub(n, "PL");
    
    REQUIRE(tester.getPList().find("PL")->second->prev == n);
    
    delete n;
}

TEST_CASE("test remove node", "[weight = 1][part construction]")
{
        Person alpha = Person("Ken",14, "male",  "PL", false);
    Person alpha1 = Person("Kim",14, "female",  "AW", false);
    //Person alpha2 = Person("Al",14, "male",  "PL", false);


    Driver beta = Driver("Rock", 12, 3, "male", "MM");

    InputReader ir = InputReader();

    ir.addToPmap(alpha);
    ir.addToPmap(alpha1);
    ir.addToDmap(beta);

    unordered_map<string, Node*> pm = ir.getPmap();
    unordered_map<string, DNode*> dm = ir.getDmap();
    vector<string> gl = ir.getGroupList();

    Planner tester = Planner(dm, pm, gl);

    // Node * n = new Node(alpha2);

    tester.removeNodePub(tester.getPList().find("AW")->second->next);
    
    REQUIRE(tester.getPList().find("PL")->second->next == tester.getPList().find("PL")->second);
    
}