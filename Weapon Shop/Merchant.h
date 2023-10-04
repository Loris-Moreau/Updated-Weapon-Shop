#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Character.h"

using namespace std;

class Merchant
{
public:
    void Introduce() const;

    void DisplayShopInventory() const;
    
    // Function to add a weapon to the merchant's inventory
    void AddWeapon(Weapon& weapon);

    void BuyWeapon(Character& character, const string& weaponName, double durabilityModifier = 1.0);

    void SellWeapon(Character& character, const string& weaponName, double durabilityModifier = 1.0);

private:
	string _merchantName;
	string _shopName;
	string _description;
	string _merchantCatchphrase;
	int _shopMoney;

    vector<Weapon> _weapons;
};

