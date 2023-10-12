#include "Merchant.h"

Merchant::Merchant(string name, string shopName, string description, string catchphrase, int money, vector<Weapon>& weapons)
    : _merchantName(name), _shopName(shopName), _description(description), _merchantCatchphrase(catchphrase), _shopMoney(money), _weapons(weapons)
{

}

void Merchant::Introduce() const
{
    cout << "Shopkeeper : Welcome to " << _shopName << ", " << _description << " ! I am " << _merchantName << endl;
    //cout << "Catchphrase : " << _merchantCatchphrase << endl;
    cout << "Money : " << _shopMoney << " coins" << endl;

    cout << endl;
}

void Merchant::DisplayShopInventory() const
{
    cout << _merchantName << " : take a look : " << endl;

    int i = 1;
    for (Weapon weapon : _weapons)
    {
        cout << i << "- " << weapon.GetName() /* << ", Type : " << weapon.GetType() */ << " --> " << weapon.GetDescription() << ", Weight : " << weapon.GetWeight()
            << ", Damage : " << weapon.GetDamage() << ", Durability : " << weapon.GetDurability() 
            << ", for " << weapon.GetPrice() * (0.2 + (weapon.GetDurability()/100)) << " coins" << endl;
    
        i++;
    }

    cout << endl;
}

void Merchant::BuyWeapon(Character& character, string weaponName, double durabilityModifier)
{
    Weapon* weaponToBuy = nullptr;

    for (Weapon& weapon : _weapons)
    {
        if (weapon.GetName() == weaponName)
        {
            int buyingCost = (int)(weapon.GetPrice() * (0.2 + (weapon.GetDurability()/100) * durabilityModifier));

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

    cout << endl;
}

void Merchant::SellWeapon(Character& character, string weaponName, double durabilityModifier)
{
    Weapon* weaponToSell = character.GetWeapon();

    if (weaponToSell && weaponToSell->GetName() == weaponName)
    {
        int sellingCost = (int)(weaponToSell->GetPrice() * (weaponToSell->GetDurability() * durabilityModifier));

        character.SetWeapon(nullptr);
        character.SetMoney(character.GetMoney() + sellingCost);

        _shopMoney -= sellingCost;
        cout << character.GetFirstName() << " sold " << weaponToSell->GetName() << " for " << sellingCost << " coins to " << _shopName << "'s shop." << endl;
    }
    else
    {
        cout << character.GetFirstName() << " does not have " << weaponName << " to sell." << endl;
    }

    cout << endl;
}
