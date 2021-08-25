#pragma once
#include <string>

using namespace std;

class Guest
{
private:
	static int guests;

	string id;
	string name;
	int new_rooms;
	int new_nights;
	int reserved_rooms = 0;
	int reserved_nights = 0;
	int total_cost = 0;

	int available_rooms = 0;
	int occupied_rooms = 0;

public:
	Guest() : id("Guest" + to_string(guests)) { guests++; };
	
	virtual string get_id();

	void set_name();
	string get_name();

	virtual void reserve_room();
	virtual void extend_reservation();
	virtual void addetional_service();
	virtual void cancel_regestration();

	virtual int get_reserved_rooms();
	virtual int get_reserved_nights();

	virtual int get_occupied();
	virtual int get_available();

	virtual int get_total_cost();

	virtual void get_info();
};
