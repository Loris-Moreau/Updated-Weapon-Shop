#include "Character.h"

Character::Character(string firstName, string lastName, string catchphrase, int money, int lifePoints, Race race, CharacterClass characterClass, Weapon weapon)
    : _charaFirstName(firstName), _charaLastName(lastName), _charaCatchphrase(catchphrase), _charaMoney(money), _charaLifePoints(lifePoints),
    _race(race), _characterClass(characterClass), _weapon(nullptr)
{

}

void Character::Introduce() const
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
        cout << "Weapon : WAH" << endl;
    }
}

void Character::UseWeapon(Character& target)
{
    if (_weapon)
    {
        int damage = _weapon->GetDamage();
        target.ReceiveDamage(damage);
        _weapon->ReduceDurability(0.2);

        cout << _charaFirstName << " used " << _weapon->GetName() << " to deal " << damage << " damage to " << target.GetFirstName() << endl <<
            _weapon->GetName() << " durability reduced to " << _weapon->GetDurability() << endl;

        if (_weapon->GetDurability() < 0)
        {
            SetWeapon(nullptr);
            cout << _weapon << " broke" << endl;
        }
        cout << target.GetFirstName() << " has " << target.GetLifePoints() << " HP left " << endl;
    }
    else
    {
        cout << "No weapon equipped" << endl;

        int damage = 6;
        target.ReceiveDamage(damage);
        ReceiveDamage(damage / 3);
        cout << _charaFirstName << " used their bare fists to deal " << damage << " damage to " << target.GetFirstName() << " and has received " << damage / 3 << " damage" << endl;

        cout << target.GetFirstName() << " has " << target.GetLifePoints() << " HP left " << endl;
        cout << GetFirstName() << " has " << GetLifePoints() << " HP left " << endl;

    }
}

void Character::ReceiveDamage(int damage)
{
    _charaLifePoints -= damage;

    if (_charaLifePoints < 0)
    {
        _charaLifePoints = 0;
    }
}

void Character::Loot(Character& defeatedCharacter)
{
    _charaMoney += defeatedCharacter.GetMoney() / 2;
    Weapon* weapon = defeatedCharacter.GetWeapon();

    if (weapon)
    {
        _weapon = weapon;
        defeatedCharacter.SetWeapon(nullptr);

        cout << _charaFirstName << " looted " << weapon->GetName() << " and " <<
            defeatedCharacter.GetMoney() / 2 << " coins from " << defeatedCharacter.GetFirstName() << endl;
    }
    else
    {
        cout << _charaFirstName << " looted " << defeatedCharacter.GetMoney() / 2 << " coins from " << defeatedCharacter.GetFirstName() << endl;
    }
}

string Character::GetFirstName()
{
    return _charaFirstName;
}

string Character::GetLastName()
{
    return _charaLastName;
}

string Character::GetRace()
{
    return RaceToStr(_race);
}

string Character::GetCharacterClass()
{
    return ClassToStr(_characterClass);
}

int Character::GetMoney() const
{
    return _charaMoney;
}

void Character::SetMoney(int money)
{
    _charaMoney = money;
}

int Character::GetLifePoints() const
{
    return _charaLifePoints;
}

Weapon* Character::GetWeapon() const
{
    return _weapon;
}

void Character::SetWeapon(Weapon* weapon)
{
    _weapon = weapon;
}
