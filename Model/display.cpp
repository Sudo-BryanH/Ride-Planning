#ifndef DISPLAY_H
#define DISPLAY_H

#include <string> 
#include <vector> 
#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <utility>

// Using singleton design. will write whatever it is given onto a .json file.
class display
{

    public: 
    static display& getInstance()
    {
        return instance;

    }

    private: 
    display() {}

    static display instance; 

};

display display::instance;

#endif