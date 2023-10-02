#pragma once
#include <iostream>
#include <string>
using namespace std;

enum WeaponTypes
{
    Sword,
    Dagger,
    Bow,
    Staff,
    Gun
};

string WeaponToStr(WeaponTypes weapon)
{
	switch (weapon)
	{
	case WeaponTypes::Sword:
		return "Sword";

	case WeaponTypes::Dagger:
		return "Dagger";

	case WeaponTypes::Bow:
		return "Bow";

	case WeaponTypes::Staff:
		return "Staff";

	case WeaponTypes::Gun:
		return "Gun";
	}
}