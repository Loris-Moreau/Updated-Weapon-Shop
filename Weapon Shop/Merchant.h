#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Weapon.h"
#include "Character.h"

using namespace std;

class Merchant
{
public:
    void Introduce() const
    {
        cout << "Name : " << _merchantName << "Welcome to " << _shopName << " " << _description << endl;
        //cout << "Catchphrase : " << _merchantCatchphrase << endl;
        cout << "Money : " << _shopMoney << " coins" << endl;
    }

private:
	string _merchantName;
	string _shopName;
	string _description;
	string _merchantCatchphrase;
	int _shopMoney;

};

