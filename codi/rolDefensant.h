#ifndef ROLDEFENSANT_H
#define ROLDEFENSANT_H

#include <string>

using namespace std;

class rolDefensant
{
public:
    virtual ~rolDefensant() = default;
    virtual void defensa() = 0;
    virtual string nom() const = 0;
};

#endif