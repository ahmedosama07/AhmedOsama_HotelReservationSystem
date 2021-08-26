#include "Guest.h"
#include <iostream>
#include <string>

using namespace std;

int Guest::guests = 0;

string Guest::get_id() {
	return this->id;
}

void Guest::set_name() {
	cout << "Enter your name: ";
	cin >> this->name;
}

string Guest::get_name() {
	return this->name;
}

void Guest::reserve_room() {
	cout << "How many rooms?" << endl;
	cin >> this->new_rooms;
	reserved_rooms += new_rooms;
	cout << "How many nights?" << endl;
	cin >> this->new_nights;
	reserved_nights += new_nights;
}

void Guest::extend_reservation() {
	cout << "How many nights?" << endl;
	cin >> this->new_nights;
	reserved_nights += new_nights;
}

void Guest::addetional_service() {
	int choice;
	cout << "1. Dry cleaning\n2. Spa" << endl;
	cin >> choice;
	if (choice == 1)
		cout << "Dry cleaning reserved" << endl;
	if (choice == 2)
		cout << "Spa reserved" << endl;
}

void Guest::cancel_regestration() {
	char choice;
	cout << "Are you sure you want to cancel the whole regestration?\n(Y/N)? ";
	cin >> choice;
	if (tolower(choice) == 'y') {
		reserved_rooms = 0;
		reserved_nights = 0;
	}
}

int Guest::get_reserved_rooms() {
	return reserved_rooms;
}

int Guest::get_reserved_nights() {
	return reserved_nights;
}

int Guest::get_available() {
	return available_rooms;
}

int Guest::get_total_cost()
{
	return this->total_cost;
}

int Guest::get_occupied() {
	return occupied_rooms;
}

void Guest::get_info() {
	cout << "Username: " << this->name << "\t" << "ID: " << this->id << endl;
}