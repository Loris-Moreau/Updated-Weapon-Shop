#include "Weapon.h"

Weapon::Weapon(string name, string description, weaponTypes type, double weight, int damage, int buyingCost, double durability)
    : _name(name), _description(description), _type(type), _weight(weight), _damage(damage), _price(buyingCost), _durability(durability)
{

}

string Weapon::GetName()
{
    return _name;
}

string Weapon::GetDescription()
{
    return _description;
}

weaponTypes Weapon::GetType()
{
    return _type;
}

double Weapon::GetWeight()
{
    return _weight;
}

int Weapon::GetDamage()
{
    return _damage;
}

int Weapon::GetPrice()
{
    return _price;
}

double Weapon::GetDurability()
{
    return _durability;
}

void Weapon::ReduceDurability(double reduction)
{
    _durability -= reduction;

    if (_durability < 0)
    {
        _durability = 0;
    }
}