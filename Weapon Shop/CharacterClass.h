#pragma once
#include <iostream>
#include <string>
using namespace std;

enum CharacterClass
{
	Archer,
	Warrior,
	Priest,
	Paladin,
	Artificer
};

string ClassToStr(CharacterClass charaClass)
{
	switch (charaClass)
	{
	case CharacterClass::Archer:
		return "Archer";

	case CharacterClass::Warrior:
		return "Warrior";

	case CharacterClass::Priest:
		return "Priest";

	case CharacterClass::Paladin:
		return "Paladin";

	case CharacterClass::Artificer:
		return "Artificer";
	}
}