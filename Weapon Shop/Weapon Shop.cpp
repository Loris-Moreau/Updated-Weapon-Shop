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
	//Weapon(string name, string description, weaponTypes type, double weight, int damage, int buyingCost, double durability);
	Weapon dagger("dagger", "small dagger", weaponTypes::Dagger, 2, 5, 5, 10);
	Weapon sword("Sword", "a sturdy sword", weaponTypes::Sword, 10, 20, 10, 10);
	Weapon gun("Gun", "good ol' reliable", weaponTypes::Gun, 6, 200, 500, 75);
	Weapon staff("Staff", "good for Bonking", weaponTypes::Staff, 7, 30, 100, 50);
	Weapon bow("Bow", "pew pew pew pew", weaponTypes::Bow, 4, 20, 20, 20);
	
	//Initialize chara
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
	//Character(string firstName, string lastName, string catchphrase, int money, int lifePoints, Race race, CharacterClass characterClass, weaponTypes weapon);
	Character player(fName, LName, "I am the dumbest!", 500, 100, (Race)race, (CharacterClass)charaClass, dagger);

	player.Introduce();

	//enemy NPC
	Character enemyNPC("Johnathan", "Richardson", "vewy stwong", 100, 100, Race::Human, CharacterClass::Warrior, sword);

	//Initialize merchant/shop
	vector<Weapon> merchantInventory{dagger, sword, gun, staff, bow};
	//Merchant(string name, string shopName, string description, string catchphrase, int money, vector<Weapon>&weapons);
	Merchant merchant("Bob", "Jim's Dump", "The only shop in the continent", "Come buy from Tom !", 10000, merchantInventory);

	merchant.Introduce();

	merchant.DisplayShopInventory();
}
