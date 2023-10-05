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

inline string ClassToStr(CharacterClass charaClass)
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

	default:
		return "N/A";
	}
}

void DisplayClasses()
{
	for (int i = 1; i < 5; i++)
	{
		cout << i << ") " << ClassToStr((CharacterClass)i) << endl;
	}
}
