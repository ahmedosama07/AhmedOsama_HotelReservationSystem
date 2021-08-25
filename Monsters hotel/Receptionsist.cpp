#include "Receptionsist.h"
#include <iostream>

using namespace std;

void Receptionsist::show_human_data()
{
	human_available_rooms = Human::get_available();
	human_occupied_rooms = Human::get_occupied();

	cout << "Human rooms: " << endl;
	cout << "Occupied: " << human_occupied_rooms << "\tAvailable: " << human_available_rooms << endl;
}

void Receptionsist::show_monster_data()
{
	monster_available_rooms = Monster::get_available();
	monster_occupied_rooms = Monster::get_occupied();

	cout << "Monster rooms: " << endl;
	cout << "Occupied: " << monster_occupied_rooms << "\tAvailable: " << monster_available_rooms << endl;
}
