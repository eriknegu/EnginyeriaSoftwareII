#ifndef ROLATACANT_H
#define ROLATACANT_H

#include <string>

using namespace std;

class rolAtacant
{
public:
    virtual ~rolAtacant() = default; // IMPORTANT (polimorfisme)
    virtual void ataca() = 0;        // =0 => “interfície” (virtual pur)
    virtual string nom() const = 0;  // útil per mostrar quin rol és
};

#endif