#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "WeaponTypes.h"

using namespace std;

class Weapon
{
public:
    Weapon(string name, string description, weaponTypes type, double weight, int damage, int buyingCost, double durability);

    string GetName();

    string GetDescription();

    weaponTypes GetType();

    double GetWeight();

    int GetDamage();

    int GetPrice();

    double GetDurability();

    void ReduceDurability(double reduction);

private:
    string _name;
    string _description;

    weaponTypes _type;

    double _weight;
    int _damage;
    int _price;
    double _durability;
};

