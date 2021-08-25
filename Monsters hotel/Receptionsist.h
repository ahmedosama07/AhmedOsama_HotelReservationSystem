#pragma once
#include "Guest.h"
#include "Human.h"
#include "Monster.h"
class Receptionsist :
    public Guest, public Human, public Monster
{
private:
    int human_occupied_rooms;
    int human_available_rooms;

    int monster_occupied_rooms;
    int monster_available_rooms;

public:
    void show_all_data();
    void show_human_data();
    void show_monster_data();
};

