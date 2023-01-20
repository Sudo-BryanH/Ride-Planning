#include <string> 
#include <vector> 
#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <utility>
#include "model/Person.h"
#include "model/Driver.h"
#include "model/Planner.h"
#include "model/InputReader.h"


using namespace std;

void makeDriver(InputReader & ir) 
{
    string name;
    string gender;
    string group;
    int phone;
    int cap;
    cout << "adding a driver. When prompted, input each as requested." << endl;
    cout << "name: " << endl;
    cin >> name; 
    cout << "gender (can type in a single underscore): " << endl;
    cin >> gender;
    cout << "group (can type in a single underscore): " << endl;
    cin >> group;
    cout << "phone: " << endl;
    cin >> phone;
    cout << "capacity (minus the driver): " << endl;
    cin >> cap;

    Driver d = Driver(name, phone, cap, gender, group);
    ir.addToDmap(d);

}

void makePassenger(InputReader & ir)
{
    string name;
    string gender;
    string group;
    int phone;
    string canBus;
    bool cb;
    cout << "adding a passenger. When prompted, input each as requested." << endl;
    cout << "name: " << endl;
    cin >> name; 
    cout << "gender (can type in a single underscore): " << endl;
    cin >> gender;
    cout << "group (can type in a single underscore): " << endl;
    cin >> group;
    cout << "phone: " << endl;
    cin >> phone;
    cout << "can this person get there on their own ('true') or do they need a ride ('false')?: " << endl;
    cin >> canBus;

    if (canBus == "true") 
    {
        cb = true;
    } else{
        cb = false;
    }

    Person p = Person(name, phone, gender, group, cb);
    ir.addToPmap(p);
}

int main() {

    // cout << "hello world" << endl;

    string response = "_";

    InputReader ir = InputReader();

    while (response != "plan") 
    {
        while(response != "driver" && response != "passenger")
        {
            cout << "Do you want to add a passenger or driver?";
            cin >> response;
            if (response == "driver")
            {
                makeDriver(ir);
            } else 
            {
                makePassenger(ir);
            }
        }
    }
    unordered_map<string, DNode*> dmap = ir.getDmap();
    unordered_map<string, Node*> pmap = ir.getPmap();
    vector<string> glist = ir.getGroupList();

    Planner plan = Planner(dmap, pmap, glist);
    plan.planride();


    return 0;
}






