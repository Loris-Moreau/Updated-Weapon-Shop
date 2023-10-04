// Weapon Shop.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>

#include "Weapon.h"
#include "Character.h"
#include "Merchant.h"

using namespace std;
int main()
{
	//Initialize weapons
	
	//Initialize chara
	// Character(const string& firstName, const string& lastName, const string& catchphrase, int money, int lifePoints, const string& race, const string& characterClass)
	string fName = "John";
	cout << "your First Name : ";
	cin >> fName;

	string LName = "Doe";
	cout << "your Last Name : ";
	cin >> LName;

	int race;
	cout << "choose from the available races : ";
	cin >> race;
	while (race > 4)
	{
		cout << "try again dingus" << endl;
		cout << "choose from the available races : ";
		cin >> race;
	}

	int charaClass;
	cout << "choose from the available classes : ";
	cin >> charaClass;
	while (charaClass > 5)
	{
		cout << "try again dingus" << endl;
		cout << "choose from the available classes : ";
		cin >> charaClass;
	}
	Character player(fName, LName, "I am the dumbest!", 500, 100, (Race)race, (CharacterClass)charaClass, weaponTypes::Dagger);

	cout << "you are : " << endl; 
	player.Introduce();

	//Initialize merchant/shop

}
