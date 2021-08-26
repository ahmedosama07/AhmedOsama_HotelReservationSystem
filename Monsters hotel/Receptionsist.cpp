#include "Receptionsist.h"
#include <iostream>

using namespace std;

void Receptionsist::show_all_data(map<string, Guest*> guests)
{
	cout << "Human guests: " << endl;
	for (auto it = guests.cbegin(); it != guests.cend(); ++it)
	{
		if (it->first.find("Human") == 0) {
			it->second->get_info();
			cout << "Reserved : " << it->second->get_reserved_rooms() << "\t" << "Nights : " << it->second->get_reserved_nights() << "\t"
				<< "Total cost : $" << it->second->get_total_cost() << "\n" << endl;
		}
	}

	cout << "\nTotal ";

	show_human_data();

	cout << endl << "----------------------" << endl;

	cout << "Monster guests: " << endl;
	for (auto it = guests.cbegin(); it != guests.cend(); ++it)
	{
		if (it->first.find("Monster") == 0) {
			it->second->get_info();
			cout << "Reserved : " << it->second->get_reserved_rooms() << "\t" << "Nights : " << it->second->get_reserved_nights() << "\t"
				<< "Total cost : $" << it->second->get_total_cost() << "\n" << endl;
		}
	}

	cout << "\nTotal ";

	show_monster_data();
}

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
