#include <string> 
#include <vector> 
#include <iostream>
#include <stdio.h>
#include "Person.h"


Person::Person(){}

Person::Person(string name, long phone, string sex, string group, bool canBus) : name(name), gender(sex), phone(phone), group(group), canBus(canBus)
{

}
void Person::setName(string name)
{
    name = name;
}

string Person::getName()
{
    return name;
}

void Person::setGender(string sex)
{
    gender = sex;
}

string Person::getGender()
{
    return gender;
}


void Person::setPhone(long phone)
{
    phone = phone;
}

int Person::getPhone()
{
    return phone;
}

void Person::setGroup(string grp)
{
    group = grp;
}

string Person::getGroup()
{
    return group;
}

void Person::setCanBus(bool cb)
{
   canBus = cb;
}

bool Person::getCanBus()
{
    return canBus;
}


bool Person::operator==(Person p) const {

    bool nom = p.getName() == name;
    bool gen = p.getGender() == gender;
    bool ph = p.getPhone() == phone;
    bool grp = p.getGroup() == group;
    bool cb = p.getCanBus() == canBus;

    return nom && gen && ph && grp && cb;

}
