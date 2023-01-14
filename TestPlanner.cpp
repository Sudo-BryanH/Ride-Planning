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
    REQUIRE(tester.getdmap().size() == dm.size());
    REQUIRE(tester.getpmap().size() == pm.size());
    
    

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
    //iterator<string, Node*> pl = tester.getpmap().at("PL");
    cout << __LINE__ << endl;
    REQUIRE(tester.getpmap().at("PL")->next == n);
     
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
    
    REQUIRE(tester.getpmap().at("PL")->prev == n);
    
    delete n;
}

TEST_CASE("test remove node", "[weight = 1][part construction]")
{
        Person alpha = Person("Ken",14, "male",  "PL", false);
    Person alpha1 = Person("Kim",14, "female",  "AW", false);
    Person alpha2 = Person("Al",14, "male",  "PL", false);


    Driver beta = Driver("Rock", 12, 3, "male", "MM");

    InputReader ir = InputReader();

    ir.addToPmap(alpha);
    ir.addToPmap(alpha1);
    ir.addToDmap(beta);
    //ir.addToPmap(alpha2);

    unordered_map<string, Node*> pm = ir.getPmap();
    unordered_map<string, DNode*> dm = ir.getDmap();
    vector<string> gl = ir.getGroupList();

    Planner tester = Planner(dm, pm, gl);

    // Node * n = new Node(alpha2);

    tester.removeNodePub(tester.getpmap().at("PL")->next);
    
    REQUIRE(tester.getpmap().find("PL")->second->next == tester.getpmap().find("PL")->second);
    // TODO may want to do one more test here where a node is sandwiched 
}

TEST_CASE("test remove node sandwiched", "[weight = 1][part construction]")
{
        Person alpha = Person("Ken",14, "male",  "PL", false);
    Person alpha1 = Person("Kim",14, "female",  "AW", false);
    Person alpha2 = Person("Al",14, "male",  "PL", false);


    Driver beta = Driver("Rock", 12, 3, "male", "MM");

    InputReader ir = InputReader();

    ir.addToPmap(alpha);
    ir.addToPmap(alpha1);
    ir.addToDmap(beta);
    ir.addToPmap(alpha2);

    unordered_map<string, Node*> pm = ir.getPmap();
    unordered_map<string, DNode*> dm = ir.getDmap();
    vector<string> gl = ir.getGroupList();

    Planner tester = Planner(dm, pm, gl);

    Node * n = new Node(alpha2);

    Node * n1 = tester.getpmap().at("PL")->next->next;

    tester.removeNodePub(tester.getpmap().at("PL")->next);
    

    REQUIRE(n1->getPerson() == tester.getpmap().at("PL")->next->getPerson());
    // TODO may want to do one more test here where a node is sandwiched 
    delete(n);

}


// TESTED SO FAR: add, add back, remove
// TO TEST: checkerase, canpublish, assigngen, sortgen

TEST_CASE("test checkErase", "[weight = 1][part construction")
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
    tester.checkErasePmapPub(tester.getpmap().at("PL"), "PL");
    REQUIRE(tester.getpmap().count("PL") != 0);

    tester.removeNodePub(tester.getpmap().at("PL")->next);
    //tester.removeDNodePub(tester.getdmap().at("MM")->next);
    tester.checkErasePmapPub(tester.getpmap().at("PL"), "PL");
    //tester.checkEraseDmapPub(tester.getdmap().at("MM"), "MM");
    REQUIRE(tester.getpmap().count("PL") == 0);
    //REQUIRE(tester.getdmap().count("MM") == 0);

}

TEST_CASE("test canPublish", "[weight = 1][part construction")
{

    // TODO THIS TEST CREATES CREATES THE PLIST IN DRIVER BEFORE ADDING IT TO A NODE. IF TESTS FAIL OR SEGFAULT, TRY THIS IMPLEMENTATION
    Driver d = Driver("Touma", 604, 2, "female");
    Person p1 = Person("Haruki", 778, "male");
    Person p2 = Person("Setsuna", 672, "female");

    
    Node * pn1 = new Node(p1);
    Node * pn2 = new Node(p2);
    PList * pl = new PList(2);

    Planner p = Planner();

    d.setplist(pl);
    DNode * dn = new DNode(d);
    REQUIRE(dn->getPerson() == d);
    REQUIRE(d.getplist() == pl);
    REQUIRE(pl->getCapacity() == 2);
    //cout << __LINE__ << endl;
    REQUIRE(p.canPublishPub(dn) == FALSE);
    //cout << __LINE__ << endl;
    pl->addNode(pn1);
    REQUIRE(pl->getCapacity() == 1);
    //cout << __LINE__ << endl;

    REQUIRE(p.canPublishPub(dn) == FALSE);
    pl->addNode(pn2);

    //cout << __LINE__ << endl;
    REQUIRE(p.canPublishPub(dn) == TRUE);
    REQUIRE(pl->getCapacity() == 0);

   // cout << __LINE__ << endl;

}

TEST_CASE("test assignGen, already in gen", "[weight = 1]")
{
    InputReader ir = InputReader();
    
    Person p1 = Person("Hinata", 604, "male");
    Person p2 = Person("Kageyama", 778, "male");
    Person p4 = Person("Nishinoya", 772, "male", "_", true);
    Person p3 = Person("Yachi", 423, "female");
    
    Driver d1 = Driver("Ukai", 602, 3, "male");
    Driver d2 = Driver("Sawko", 609, 4, "female");
    
    ir.addToPmap(p1);
    ir.addToPmap(p2);
    ir.addToPmap(p3);
    ir.addToPmap(p4);
    
    ir.addToDmap(d2);
    ir.addToDmap(d1);
    //ir.addToDmap(d2);
    
    unordered_map<string, Node*> pm = ir.getPmap();
    unordered_map<string, DNode*> dm = ir.getDmap();
    vector<string> gl = ir.getGroupList();
    REQUIRE(pm.at("female")->prev->getPerson().getName() == "Yachi");
   
    //cout << pm.find("female")->first <<endl;
    Planner plan = Planner(dm, pm, gl);
    REQUIRE(plan.getpmap().at("female")->prev->getPerson().getName() == "Yachi");
    
    REQUIRE(plan.getdmap() == dm);
    
    REQUIRE(plan.getpmap() == pm);
    REQUIRE(plan.getGList() == gl);

    
    plan.assignGenPub(dm.at("male"));
    REQUIRE(plan.getpmap().at("female")->prev->getPerson() == p3);

    DNode * dn1 = plan.getdmap().at("male")->next;
    
    REQUIRE(dn1->getPerson().getplist()->getCapacity() == 1);

    REQUIRE(dn1->getPerson().getplist()->getSentinel()->next->getPerson().getName() == "Hinata");
    REQUIRE(dn1->getPerson().getplist()->getSentinel()->prev->getPerson().getName() == "Kageyama");
    REQUIRE(plan.getpmap().at("misc")->prev->getPerson().getName() == "Nishinoya");

    plan.assignGenPub(dm.at("female"));

    dn1 = plan.getdmap().at("female")->next;

    REQUIRE(dn1->getPerson().getplist()->getCapacity() == 3);

}

TEST_CASE("test assignGen, already in gen multiple driver", "[weight = 1]")
{
    InputReader ir = InputReader();
    
    Person p1 = Person("Hinata", 604, "male");
    Person p2 = Person("Kageyama", 778, "male");
    Person p4 = Person("Nishinoya", 772, "male");
    Person p3 = Person("Yachi", 423, "female");
    
    Driver d1 = Driver("Ukai", 602, 3, "male");
    Driver d2 = Driver("Takeda", 129, 1, "male");
    Driver d2 = Driver("Sawko", 609, 4, "female");
    
    ir.addToPmap(p1);
    ir.addToPmap(p2);
    ir.addToPmap(p3);
    ir.addToPmap(p4);
    
    ir.addToDmap(d2);
    ir.addToDmap(d1);
    //ir.addToDmap(d2);
    
    unordered_map<string, Node*> pm = ir.getPmap();
    unordered_map<string, DNode*> dm = ir.getDmap();
    vector<string> gl = ir.getGroupList();
    REQUIRE(pm.at("female")->prev->getPerson().getName() == "Yachi");
   
    //cout << pm.find("female")->first <<endl;
    Planner plan = Planner(dm, pm, gl);
    REQUIRE(plan.getpmap().at("female")->prev->getPerson().getName() == "Yachi");
    
    REQUIRE(plan.getdmap() == dm);
    
    REQUIRE(plan.getpmap() == pm);
    REQUIRE(plan.getGList() == gl);

    
    plan.assignGenPub(dm.at("male"));
    REQUIRE(plan.getpmap().at("female")->prev->getPerson() == p3);

    DNode * dn1 = plan.getdmap().at("male")->next;
    
    // REQUIRE(dn1->getPerson().getplist()->getCapacity() == 1);

    // REQUIRE(dn1->getPerson().getplist()->getSentinel()->next->getPerson().getName() == "Hinata");
    // REQUIRE(dn1->getPerson().getplist()->getSentinel()->prev->getPerson().getName() == "Kageyama");
    // REQUIRE(plan.getpmap().at("misc")->prev->getPerson().getName() == "Nishinoya");

    

}

