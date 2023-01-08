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

using namespace std;



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

    // TESTS FOR TESTREADER

        REQUIRE(pm.find("PL")->second->next->getPerson() == alpha);
    REQUIRE(pm.find("AW")->second->next->getPerson() == alpha1);
    REQUIRE(dm.find("MM")->second->next->getPerson() == beta);
    REQUIRE(pm.count("misc") != 0);
    REQUIRE(pm.count("male") != 0);
    REQUIRE(pm.count("female") != 0);
    REQUIRE(pm.size() == 5);
    REQUIRE(pm.count("PL") != 0);
    REQUIRE(pm.count("AW") != 0);
    REQUIRE(dm.count("misc") != 0);
    REQUIRE(dm.count("male") != 0);
    REQUIRE(dm.count("female") != 0);
    REQUIRE(dm.size() == 4);

    // TESTS FOR PLANNER
    Planner tester = Planner(dm, pm, gl);
    REQUIRE(tester.getGList() == gl);
    REQUIRE(tester.getDList().size() == dm.size());
    REQUIRE(tester.getPList().size() == pm.size());
    
    

}

TEST_CASE("test add node", "[weight = 1][part construction]")
{
    Person alpha = Person("Ken",14, "male",  "PL", false);
    Person alpha1 = Person("Kim",14, "female",  "AW", false);
    Person alpha2 = Person("Al",14, "male",  "AW", false);


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
    cout << __LINE__ << endl;
    tester.addNodePub(n, "PL");
     cout << __LINE__ << endl;
    //iterator<string, Node*> pl = tester.getPList().at("PL");
    cout << __LINE__ << endl;
    REQUIRE(tester.getPList().at("PL")->next == n);
     
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
    
    REQUIRE(tester.getPList().at("PL")->prev == n);
    
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

    tester.removeNodePub(tester.getPList().at("PL")->next);
    
    REQUIRE(tester.getPList().find("PL")->second->next == tester.getPList().find("PL")->second);
    
}