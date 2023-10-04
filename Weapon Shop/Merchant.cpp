#include "Merchant.h"

void Merchant::Introduce() const
{
    cout << "Name : " << _merchantName << "Welcome to " << _shopName << " " << _description << endl;
    //cout << "Catchphrase : " << _merchantCatchphrase << endl;
    cout << "Money : " << _shopMoney << " coins" << endl;
}

void Merchant::DisplayShopInventory() const
{
    cout << "Welcome to " << _shopName << "! I am " << _merchantName << " and here are the weapons available for sale :" << endl;

    for (Weapon weapon : _weapons)
    {
        cout << "- Name : " << weapon.GetName() << ", Type : " << weapon.GetType() << ", Description : " << weapon.GetDescription() << ", Weight : " << weapon.GetWeight()
            << ", Damage : " << weapon.GetDamage() << ", Buying Cost : " << weapon.GetPrice() << ", Durability : " << weapon.GetDurability() << endl;
    }
}


// Function to add a weapon to the merchant's inventory
void AddWeapon(Weapon& weapon)
{
    cout << "no";
    //weapon.push_back(weapon);
}


void Merchant::BuyWeapon(Character& character, const string& weaponName, double durabilityModifier)
{
    Weapon* weaponToBuy = nullptr;

    for (Weapon& weapon : _weapons)
    {
        if (weapon.GetName() == weaponName)
        {
            int buyingCost = (int)(weapon.GetPrice() / (1 - weapon.GetDurability() * durabilityModifier));

            if (character.GetMoney() >= buyingCost)
            {
                character.SetWeapon(new Weapon(weapon));
                character.SetMoney(character.GetMoney() - buyingCost);
                _shopMoney += buyingCost;
                cout << character.GetFirstName() << " bought " << weapon.GetName() << " for " << buyingCost << " coins from " << _merchantName << "'s shop." << endl;
                return;
            }
            else
            {
                cout << "Not enough money to buy " << weapon.GetName() << " from " << _merchantName << "'s shop." << endl;
                return;
            }
        }
    }
    cout << weaponName << " is not available in " << _merchantName << "'s shop." << endl;
}

void Merchant::SellWeapon(Character& character, const string& weaponName, double durabilityModifier)
{
    Weapon* weaponToSell = character.GetWeapon();

    if (weaponToSell && weaponToSell->GetName() == weaponName)
    {
        int sellingCost = (int)(weaponToSell->GetPrice() * (0.2 + weaponToSell->GetDurability() * durabilityModifier));

        character.SetWeapon(nullptr);
        character.SetMoney(character.GetMoney() + sellingCost);

        _shopMoney -= sellingCost;
        cout << character.GetFirstName() << " sold " << weaponToSell->GetName() << " for " << sellingCost << " coins to " << _shopName << "'s shop." << endl;
    }
    else
    {
        cout << character.GetFirstName() << " does not have " << weaponName << " to sell." << endl;
    }
}