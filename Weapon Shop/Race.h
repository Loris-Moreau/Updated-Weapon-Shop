#pragma once
#include <iostream>
#include <string>

using namespace std;

enum Race
{
	Elf,
	Orc,
	Goblin,
	Human
};

inline string RaceToStr(Race races)
{
	switch (races)
	{
	case Race::Elf:
		return "Elf";

	case Race::Orc:
		return "Orc";

	case Race::Goblin:
		return "Goblin";

	case Race::Human:
		return "Human";

	default:
		return "N/A";
	}
}

void DisplayRaces()
{
	for (int i = 1; i < 4; i++)
	{
		cout << i << ") " << RaceToStr((Race)i) << endl;
	}
}
