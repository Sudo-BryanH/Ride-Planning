#include <string> 
#include <vector> 
#include <iostream>
#include <stdio.h>
#include "driver.h"
#include "person.h"


driver::driver(string name, string gender, int phone, int capacity, string group = "N/A") : capacity(capacity)
{
    setName(name);
    setGender(gender);
    setGroup(group);
    setPhone(phone);
}