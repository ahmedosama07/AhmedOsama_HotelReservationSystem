#include "Human.h"
#include <iostream>

using namespace std;

int Human::humans = 0;
int Human::occupied_rooms = 0;
int Human::available_rooms = 5;

string Human::get_id() {
	return this->id;
}

void Human::reserve_room() {
label:
	cout << "How many rooms?" << endl;
	cin >> this->new_rooms;

	if (new_rooms <= available_rooms && new_rooms > 0) {
		reserved_rooms += new_rooms;

		available_rooms -= new_rooms;
		occupied_rooms += new_rooms;
	}
	else {
		cout << "There is only " << available_rooms << " rooms available" << endl;
		goto label;
		return;
	}
	
	cout << "How many nights?" << endl;
	cin >> this->new_nights;
	this->reserved_nights += new_nights;

	this->total_cost = this->total_cost + room_price * new_nights * new_rooms;
	cout << "Total cost: $" << this->total_cost << endl;
}

void Human::extend_reservation() {
	cout << "How many nights?" << endl;
	cin >> this->new_nights;
	reserved_nights += new_nights;

	this->total_cost = total_cost + room_price * new_nights * this->reserved_rooms;
	cout << "Total cost: $" << this->total_cost << endl;
}

void Human::addetional_service() {
	int choice;
	cout << "1. Dry cleaning\n2. Spa" << endl;
	cin >> choice;

	if (choice == 1) {
		cout << "Dry cleaning successfully reserved" << endl;
		this->total_cost += dry_cleaning;
	}
	else if (choice == 2) {
		cout << "Spa successfully reserved" << endl;
		this->total_cost += spa;
	}
	cout << "Total cost: $" << this->total_cost << endl;
}

void Human::cancel_regestration() {
	char choice;
	cout << "Are you sure you want to cancel the whole regestration?\n(Y/N)? ";
	cin >> choice;
	if (tolower(choice) == 'y') {
		available_rooms += reserved_rooms;
		occupied_rooms -= reserved_rooms;
		reserved_rooms = 0;
		reserved_nights = 0;
	}
}

int Human::get_reserved_rooms()
{
	return this->reserved_rooms;
}

int Human::get_reserved_nights()
{
	return this->reserved_nights;
}

int Human::get_available() {
	return available_rooms;
}

int Human::get_total_cost()
{
	return this->total_cost;
}

int Human::get_occupied() {
	return occupied_rooms;
}

void Human::get_info() {
	cout << "Username: " << this->get_name() << "\tID: " << this->id << endl;
}