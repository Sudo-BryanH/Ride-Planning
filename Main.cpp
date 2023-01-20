#include <string> 
#include <vector> 
#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <utility>
#include <model/Person.h>
#include <model/Driver.h>
#include <model/Planner.h>
#include <model/InputReader.h>


using namespace std;

int Main() {

    // cout << "hello world" << endl;

    string response = "_";

    InputReader ir = InputReader();

    while (response != "plan") 
    {
        while(response != "driver" && response != "passenger")
        {
            cout << "Do you want to add a passenger or driver?"
            cin << response;
            if (response == "driver")
            {
                makeDriver(ir);
            } else 
            {
                makePassenger(ir);
            }
        }
    }

    Planner plan = Planner(ir.getDmap, ir.getPmap, ir.getGroupList);
    plan.planride();


    return 0;
}

void makeDriver(InputReader & ir) 
{
    string name;
    string gender: 
    string group;
    int phone;
    int cap;
    cout << "adding a driver. When prompted, input each as requested." << endl;
    cout << "name: " << endl;
    cin << name; 
    cout << "gender (can type in a single underscore): " << endl;
    cin << gender;
    cout << "group (can type in a single underscore): " << endl;
    cin << group;
    cout << "phone: " << endl;
    cin << phone;
    cout << "capacity (minus the driver): " << endl;
    cin << cap;

    Driver d = Driver(name, phone, cap, gender, group);
    ir.addToDmap(d);

}

void makePassenger(InputReader & ir)
{
    string name;
    string gender: 
    string group;
    int phone;
    int cap;
    cout << "adding a passenger. When prompted, input each as requested." << endl;
    cout << "name: " << endl;
    cin << name; 
    cout << "gender (can type in a single underscore): " << endl;
    cin << gender;
    cout << "group (can type in a single underscore): " << endl;
    cin << group;
    cout << "phone: " << endl;
    cin << phone;
    cout << "capacity (minus the driver): " << endl;
    cin << cap;

    Person p = Person();
    ir.addToPmap(p);
}




