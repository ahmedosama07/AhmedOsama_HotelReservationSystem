#pragma once
#include "Guest.h"
class Monster :
    public Guest
{
private:
	static int monsters;
	static int occupied_rooms;
	static int available_rooms;

	string id;
	const int room_price = 200;
	const int dry_cleaning = 30;
	const int spa = 50;
	int new_rooms;
	int new_nights;
	int reserved_rooms = 0;
	int reserved_nights = 0;
	double total_cost = 0;

public:
	Monster() : id("Monster" + to_string(monsters)) { monsters++; };

	string get_id();

	void reserve_room();
	void extend_reservation();
	void addetional_service();
	void cancel_regestration();
	
	int get_reserved_rooms();
	int get_reserved_nights();

	int get_occupied();
	int get_available();

	double get_total_cost();

	void get_info();
};

