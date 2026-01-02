#ifndef ROLDEFENSANT_H
#define ROLDEFENSANT_H

#include <string>
#include <iostream>

using namespace std;

class rolDefensant
{
public:
    virtual ~rolDefensant() = default;
    virtual void defensa() = 0;
};

#endif