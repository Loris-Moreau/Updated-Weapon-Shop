#pragma once
#include <iostream>
#include <string>
#include<vector>

#include "Weapon.h"
#include "Race.h"
#include "CharacterClass.h"

using namespace std;

class Character
{
public:
    Character(string firstName, string lastName, string catchphrase, int money, int lifePoints, Race race, CharacterClass characterClass, Weapon weapon);

    void Introduce() const;

    //void DisplayRaces() const;

    //void DisplayClasses() const;

    void UseWeapon(Character& target);

    void ReceiveDamage(int damage);

    void Loot(Character& defeatedCharacter);

    string GetFirstName();

    string GetLastName();

    string GetRace();

    string GetCharacterClass();

    int GetMoney() const;

    void SetMoney(int money);

    int GetLifePoints() const;

    Weapon* GetWeapon() const;

    void SetWeapon(Weapon* weapon);

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
