#ifndef PERSON_H
#define PERSON_H



#include <string> 
#include <vector> 
#include <iostream>
#include <stdio.h>
// #include <unordered_map>

using namespace std;

// represents a person with all required data about them. will be used to represent 
// passengers while drivers will be its own extension of this class
class person
{
    public: 

    // Fills in the fields of the person abstract class
    person(string name,  int phone, string gender = "none", string group = "none", bool canBus = true); // : name(name), sex(sex), phone(phone), group(group);
    person();
    
    


    // Setters and getters for private fields
    void setName(string name);
    string getName();
    void setGender(string gender);
    string getGender();
    void setPhone(int phone);
    int getPhone();
    void setGroup(string group);
    string getGroup();
    void setCanBus(bool canBus);
    bool getCanBus();


    private: 
    // private fields of the person
    string name;
    string gender;
    int phone;
    string group;
    bool canBus;


};
#endif