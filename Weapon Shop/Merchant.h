#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Character.h"

using namespace std;

class Merchant
{
public:
    Merchant(string name, string shopName, string description, string catchphrase, int money, vector<Weapon>& weapons);

    void Introduce() const;

    void DisplayShopInventory() const;

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

