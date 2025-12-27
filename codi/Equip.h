#ifndef EQUIP_H
#define EQUIP_H

#include <ctime>
#include <string>

class Equip
{
public:
    Equip();
    ~Equip();
    int quantesTarjetes() const;
    string NomEquip() const;

private:
    string nom;
    int anyFundacio;
    int nTarjetes;
};

#endif