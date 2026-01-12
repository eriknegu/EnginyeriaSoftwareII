#ifndef ROLATACANT_H
#define ROLATACANT_H

#include <string>
#include <iostream>

using namespace std;

class rolAtacant
{
public:
    virtual ~rolAtacant() = default; // IMPORTANT (polimorfisme)
    virtual void ataca() = 0;        // =0 => “interfície” (virtual pur)
};

#endif