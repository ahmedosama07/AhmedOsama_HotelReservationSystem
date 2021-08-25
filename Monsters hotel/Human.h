#pragma once
#include "Guest.h"
class Human :
    public Guest
{
private:
    static int humans;
	static int occupied_rooms;
	static int available_rooms;

    string id;
	const int room_price = 500;
	const int dry_cleaning = 70;
	const int spa = 100;
	int new_rooms;
	int new_nights;
	int reserved_rooms = 0;
	int reserved_nights = 0;
	int total_cost = 0;

public:
	Human() : id("Human" + to_string(humans)) { humans++; };

	string get_id();

	void reserve_room();
	void extend_reservation();
	void addetional_service();
	void cancel_regestration();

	int get_reserved_rooms();
	int get_reserved_nights();

	int get_occupied();
	int get_available();

	int get_total_cost();

	void get_info();
};

