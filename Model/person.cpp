#include <string> 
#include <vector> 
#include <iostream>
#include <stdio.h>
#include "person.h"


person::person(){}

person::person(string name, int phone, string sex, string group, bool canBus) : name(name), gender(sex), phone(phone), group(group), canBus(canBus)
{

}
void person::setName(string name)
{
    name = name;
}

string person::getName()
{
    return name;
}

void person::setGender(string sex)
{
    gender = sex;
}

string person::getGender()
{
    return gender;
}


void person::setPhone(int phone)
{
    phone = phone;
}

int person::getPhone()
{
    return phone;
}

void person::setGroup(string grp)
{
    group = grp;
}

string person::getGroup()
{
    return group;
}

void person::setCanBus(bool cb)
{
   canBus = cb;
}

bool person::getCanBus()
{
    return canBus;
}


bool person::operator==(person p) const {

    bool nom = p.getName() == name;
    bool gen = p.getGender() == gender;
    bool ph = p.getPhone() == phone;
    bool grp = p.getGroup() == group;
    bool cb = p.getCanBus() == canBus;

    return nom && gen && ph && grp && cb;

}
