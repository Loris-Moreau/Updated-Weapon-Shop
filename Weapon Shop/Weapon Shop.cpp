//Weapon Shop.cpp : This file contains the 'main' function. Program execution begins and ends there.

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
	Weapon dagger("Dagger", "small dagger", weaponTypes::Dagger, 2, 5, 100, 10);
	Weapon sword("Sword", "a sturdy sword", weaponTypes::Sword, 10, 20, 275, 10);
	Weapon gun("Gun", "good ol' reliable", weaponTypes::Gun, 6, 200, 700, 70);
	Weapon staff("Staff", "good for Bonking", weaponTypes::Staff, 7, 30, 450, 50);
	Weapon bow("Bow", "pew pew pew pew", weaponTypes::Bow, 4, 20, 200, 25);

	//Initialize Shop Inventory
	vector<Weapon> merchantInventory{dagger, sword, gun, staff, bow};


	//Initialize Main Character
	string fName = "John";
	cout << "your First Name : ";
	cin >> fName;

	string LName = "Doe";
	cout << "your Last Name : ";
	cin >> LName;

	cout << endl;

	int race;
	cout << "choose from the available races : " << endl;

	cout << "1- Elf" << endl <<
		"2- Orc" << endl <<
		"3- Goblin" << endl <<
		"4- Human" << endl;
	cout << fName << " : ";
	cin >> race;
	race = race - 1;

	/*while (race > 4)
	{
		cout << "try again dingus" << endl;
		cout << "choose from the available races : ";
		cin >> race;
	}*/

	int charaClass;
	cout << "choose from the available classes : " << endl;
	cout << "1- Archer" << endl <<
		"2- Warrior" << endl <<
		"3- Priest" << endl <<
		"4- Paladin" << endl <<
		"5- Artificer" << endl;

	cout << fName << " : ";
	cin >> charaClass;
	charaClass = charaClass - 1;

	/*while (charaClass > 5)
	{
		cout << "try again dingus" << endl;
		cout << "choose from the available classes : ";
		cin >> charaClass;
	}*/

	cout << endl;

	///Character(string firstName, string lastName, string catchphrase, int money, int lifePoints, Race race, CharacterClass characterClass, weaponTypes weapon);
	Character player(fName, LName, "I am the dumbest!", 1000, 100, (Race)race, (CharacterClass)charaClass, dagger);

	player.Introduce();

	//enemy NPC
	Character enemyNPC("Johnathan", "Richardson", "vewy stwong", 100, 100, Race::Human, CharacterClass::Paladin, sword);


	//Initialize Merchant
	///Merchant(string name, string shopName, string description,           string catchphrase, int money, vector<Weapon>&weapons);
	Merchant merchant("Bob", "Jim's Dump", "The only shop in the continent", "Come buy from Tom", 10000, merchantInventory);

	merchant.Introduce();


	string answer = " ";
	cout << "do you want to buy something ? (Y/N)" << endl;
	cin >> answer;
	if (answer == "Y" || answer == "y" || answer == "Yes" || answer == "yes")
	{
		merchant.DisplayShopInventory();

		string buyChoice;
		cout << "wich one ? : ";
		cin >> buyChoice;
		//buyChoice = buyChoice - 1;
		merchant.BuyWeapon(player, buyChoice);
	}
	else
	{
		if (answer == "N" || answer == "n" || answer == "No" || answer == "no")
		{
			cout << "alright then moving on" << endl;
			exit;
		}
	}

	cout << endl;

	answer = " ";
	cout << "There is an Enemy ahead do you wish to fight them ? : ";
	cin >> answer;
	if (answer == "Y" || answer == "y" || answer == "Yes" || answer == "yes")
	{
		enemyNPC.Introduce();

		while (player.GetLifePoints() > 0 || enemyNPC.GetLifePoints() > 0)
		{
			if (player.GetLifePoints() <= 0 || enemyNPC.GetLifePoints() <= 0)
			{
				exit;
			}

			enemyNPC.UseWeapon(player);
			player.UseWeapon(enemyNPC);
		}

		if (player.GetLifePoints() <= 0)
		{
			cout << "You Died";
			return 0;
		}

		if (enemyNPC.GetLifePoints() <= 0)
		{
			player.Loot(enemyNPC);
		}
	}
	else
	{
		if (answer == "N" || answer == "n" || answer == "No" || answer == "no")
		{
			cout << "ok" << endl;
			exit;
		}
	}
}
