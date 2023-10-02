#pragma once
#include <iostream>
#include <string>

#include "Weapon.h"
#include "Race.h"
#include "CharacterClass.h"

using namespace std;

class Character
{
public :
    Character(string firstName, string lastName, string catchphrase, int money, int lifePoints, Race race, CharacterClass characterClass)
        : _charaFirstName(firstName), _charaLastName(lastName), _charaCatchphrase(catchphrase), _charaMoney(money), _charaLifePoints(lifePoints), 
        _race (race), _characterClass (characterClass), _weapon(nullptr)
    {

    }

    void Introduce() const 
    {
        cout << "Name : " << _charaFirstName << " " << _charaLastName << endl;
        cout << "Catchphrase : " << _charaCatchphrase << endl;
        cout << "Race : " << _race << endl;
        cout << "Class : " << _characterClass << endl;
        cout << "Money : " << _charaMoney << " coins" << endl;
        cout << "Life Points : " << _charaLifePoints << endl;

        if (_weapon)
        {
            cout << "Weapon : " << _weapon->GetName() << " (Durability : " << _weapon->GetDurability() << ")" << endl;
        }
        else
        {
            cout << "Weapon : None" << endl;
        }
    }

    string GetFirstName()     
    {
        return _charaFirstName;
    }

    string GetLastName() 
    {
        return _charaLastName;
    }

    string GetRace() 
    {
        return 0;
    }

    string GetCharacterClass() 
    {
        return 0;
    }

    int GetMoney() const
    {
        return _charaMoney;
    }

    void SetMoney(int money)
    {
        _charaMoney = money;
    }

    int GetLifePoints() const
    {
        return _charaLifePoints;
    }

    Weapon* GetWeapon() const
    {
        return _weapon;
    }

    void SetWeapon(Weapon* weapon)
    {
        _weapon = weapon;
    }

private:
	string _charaFirstName;
	string _charaLastName;
	string _charaCatchphrase;
	int _charaMoney;
	int _charaLifePoints;
	
    Weapon* _weapon;

	Race _race;

	CharacterClass _characterClass;
};

