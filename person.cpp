#include <string> 
#include <vector> 
#include <iostream>
#include <stdio.h>
#include "person.h"

int person :: whatever() 
{

}

person::person(string name, string sex, int phone, string group = "N/A") : name(name), gender(sex), phone(phone), group(group)
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
