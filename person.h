#ifndef PERSON_H
#define PERSON_H



#include <string> 
#include <vector> 
#include <iostream>
#include <stdio.h>
// #include <unordered_map>

using namespace std;

class person
{
    public: 

    // Fills in the fields of the person abstract class
    person(string name, string gender, int phone, string group = "N/A"); // : name(name), sex(sex), phone(phone), group(group);
    
    // TEST FOR VIRTUAL ABSTRACT FNS
    virtual int whatever() = 0;

    // Setters and getters for private fields
    void setName(string name);
    string getName();
    void setGender(string gender);
    string getGender();
    void setPhone(int phone);
    int getPhone();
    void setGroup(string group);
    string getGroup();


    private: 
    // private fields of the person
    string name;
    string gender;
    int phone;
    string group;


};
#endif