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
	///Weapon(string name, string description, weaponTypes type, double weight, int damage, int buyingCost, double durability);
	Weapon dagger("dagger", "small dagger",      weaponTypes::Dagger,  2,           5,         100,               10);
	Weapon sword("Sword",   "a sturdy sword",    weaponTypes::Sword,   10,          20,        275,               10);
	Weapon gun("Gun",       "good ol' reliable", weaponTypes::Gun,     6,           200,       700,               70);
	Weapon staff("Staff",   "good for Bonking",  weaponTypes::Staff,   7,           30,        450,               50);
	Weapon bow("Bow",       "pew pew pew pew",   weaponTypes::Bow,     4,           20,        200,               25);

	//Initialize Shop Inventory
	vector<Weapon> merchantInventory{dagger, sword, gun, staff, bow};


	//Initialize Main Character
	string fName = "John";
	cout << "your First Name : ";
	cin >> fName;

	string LName = "Doe";
	cout << "your Last Name : ";
	cin >> LName;

	int race;
	cout << "choose from the available races : " << endl;

	DisplayRaces();

	cin >> race;

	/*while (race > 4)
	{
		cout << "try again dingus" << endl;
		cout << "choose from the available races : ";
		cin >> race;
	}*/


	int charaClass;
	cout << "choose from the available classes : ";

	DisplayClasses();

	cin >> charaClass;

	/*while (charaClass > 5)
	{
		cout << "try again dingus" << endl;
		cout << "choose from the available classes : ";
		cin >> charaClass;
	}*/

	///Character(string firstName, string lastName, string catchphrase, int money, int lifePoints, Race race, CharacterClass characterClass, weaponTypes weapon);
	Character player(fName,              LName,    "I am the dumbest!",    500,        100,       (Race)race, (CharacterClass)charaClass,   dagger);

	player.Introduce();

	//enemy NPC
	Character enemyNPC("Johnathan", "Richardson", "vewy stwong", 100, 100, Race::Human, CharacterClass::Warrior, sword);


	//Initialize Merchant
	///Merchant(string name, string shopName, string description,           string catchphrase, int money, vector<Weapon>&weapons);
	Merchant merchant("Bob", "Jim's Dump", "The only shop in the continent", "Come buy from Tom", 10000, merchantInventory);

	merchant.Introduce();

	merchant.DisplayShopInventory();

	/*
	while (player.GetLifePoints() > 0 || enemyNPC.GetLifePoints() < 0)
	{
		enemyNPC.UseWeapon(player);
		player.UseWeapon(enemyNPC);

		cout << player.GetFirstName() << " has " << player.GetLifePoints() << " LP left" << endl;
		cout << enemyNPC.GetFirstName() << " has " << enemyNPC.GetLifePoints() << " LP left" << endl;
	}

	if (enemyNPC.GetLifePoints() <= 0)
	{
		player.Loot(enemyNPC);
	}
	*/
}
