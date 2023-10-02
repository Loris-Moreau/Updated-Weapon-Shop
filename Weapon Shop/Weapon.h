#pragma once
#include <iostream>
#include <string>

#include "WeaponTypes.h"

using namespace std;

class Weapon
{
public:
    Weapon(const string& name, const string& description, WeaponTypes type, double weight, int damage, int buyingCost, double durability)
        : _name(name), _description(description), _type(type), _weight(weight), _damage(damage), _price(buyingCost), _durability(durability)
    {

    }

    const string& GetName() const
    {
        return _name;
    }

    const string& GetDescription() const
    {
        return _description;
    }

    WeaponTypes GetType() const
    {
        return _type;
    }

    double GetWeight() const
    {
        return _weight;
    }

    int GetDamage() const
    {
        return _damage;
    }

    int GetPrice() const
    {
        return _price;
    }

    double GetDurability() const
    {
        return _durability;
    }

    void ReduceDurability(double reduction)
    {
        _durability -= reduction;

        if (_durability < 0)
        {
            _durability = 0;
        }
    }

private:
    string _name;
    string _description;

    WeaponTypes _type;

    double _weight;
    int _damage;
    int _price;
    double _durability;
};

