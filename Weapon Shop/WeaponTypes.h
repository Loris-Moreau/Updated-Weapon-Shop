#pragma once
#include <iostream>
#include <string>

using namespace std;

enum weaponTypes
{
	none,
    Sword,
    Dagger,
    Bow,
    Staff,
    Gun
};

inline string WeaponToStr(weaponTypes weapon)
{
	switch (weapon)
	{
	case weaponTypes::none:
		return "None";

	case weaponTypes::Sword:
		return "Sword";

	case weaponTypes::Dagger:
		return "Dagger";

	case weaponTypes::Bow:
		return "Bow";

	case weaponTypes::Staff:
		return "Staff";

	case weaponTypes::Gun:
		return "Gun";
	default:
		return "N/A";
	}
}