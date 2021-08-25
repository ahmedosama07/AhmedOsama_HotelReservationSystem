// Monsters hotel.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//including header files
#include <iostream>
#include <map>

//including classes
#include "Guest.h"
#include "Human.h"
#include "Monster.h"
#include "Receptionsist.h"

using namespace std;

int main()
{
    //initializing a pointer for the parent class to be used when creating new objects of the child classes
    Guest* guest = nullptr;
    //making a map of objects where their IDs are the keys
    map <string, Guest*> guests;
    //object for the receptionist class
    Receptionsist receptionist;
    
    
    string current_id;
    int choice;
    
    //the main program
    do
    {
        cout << "1. New user\n2. Old user\n3. Receptionist" << endl;
        cin >> choice;

        if (choice == 1) {
            cout << "What is your class?" << endl;
            cout << "1. Human\n2. Monster" << endl;
            cin >> choice;
            if (choice == 1) {
                //creating a new human object
                guest = new Human;
                current_id = guest->get_id();
                guests[current_id] = guest;
                cout << "Welcome to the hotel" << endl;
                guests[current_id]->set_name();

                //printing some information for the user about the number of rooms
                guests[current_id]->get_info();
                cout << "Occupied : " << guests[current_id]->get_occupied() << "\tAvailable : " << guests[current_id]->get_available() << endl;
                
                //reserving a room
                guests[current_id]->reserve_room();
            }
            else if (choice == 2) {
                //creating a new monster object
                guest = new Monster;
                current_id = guest->get_id();
                guests[current_id] = guest;
                cout << "Welcome to the hotel" << endl;
                guests[current_id]->set_name();

                //printing some information for the user about the number of rooms
                guests[current_id]->get_info();
                cout << "Occupied : " << guests[current_id]->get_occupied() << "\tAvailable : " << guests[current_id]->get_available() << endl;
                
                //reserving a room
                guests[current_id]->reserve_room();
            }
        }
        else if (choice == 2) {
            //reading id from the user to search for
            cout << "Enter your ID: ";
            cin >> current_id;

            if (guests.find(current_id) == guests.end()) {
                //not found
                cout << "Not found" << endl;
            }
            else {
                //found
                
                //printing user account info
                guests[current_id]->get_info();
                cout << "Occupied : " << guests[current_id]->get_occupied() << "\tAvailable : " << guests[current_id]->get_available() << endl;
                cout << "\n1. New reservation\n2. Extend reservation\n3. Additional services\n4. Cancel reservation" << endl;
                cin >> choice;
                if (choice == 1) {
                    //reserve room
                    guests[current_id]->reserve_room();
                }
                else if (choice == 2) {
                    //extend reservation
                    guests[current_id]->extend_reservation();
                }
                else if (choice == 3) {
                    //addetional services
                    guests[current_id]->addetional_service();
                }
                else if (choice == 4) {
                    //cancel reservation
                    guests[current_id]->cancel_regestration();
                }
            }

            
        }
        else if (choice == 3) {
            //receptionist
            cout << "1. Show human rooms\n2. Show monster rooms\n3. Show all users data" << endl;
            cin >> choice;

            if (choice == 1) {
                //human users data
                receptionist.show_human_data();
            }
            else if (choice == 2) {
                //monster users data
                receptionist.show_monster_data();
            }
            else if (choice == 3) {
                //all data
                for (auto it = guests.cbegin(); it != guests.cend(); ++it)
                {
                    it->second->get_info();
                    cout << "Reserved : " << it->second->get_reserved_rooms() << "\t" << "Nights : " << it->second->get_reserved_nights() << "\t"
                        << "Total cost : $" << it->second->get_total_cost() << endl;
                }
            }
        }

        //wait for keypress
        system("pause");
        //clear console
        system("CLS");
    } while (choice != 0);
    
}