#include "Game.h"
#include <iostream>
#include <fstream>
#include "Entity.h"
#include "Dragon.h"
#include "Exceptions.h"
#include "Goblin.h"
#include "Player.h"
#include "Monster.h"

// Constructor for the Game class, initializing member variables.
Game::Game(Player* player) : first_room(nullptr), player(player), all_Rooms(nullptr), num_Rooms(0), capacity_Rooms(0) {}

// Destructor for the Game class.
Game::~Game() {
    delete this->player;
}

// Adds a new room to the game based on the given string identifier.
// Expands the room array if needed and links rooms according to the string identifier.
void Game::add_room(const std::string& w, Room* new_room) {
    if (new_room == nullptr) {
        this->end_game();
        throw MemoryProblemException();
    }
    try {
        // If all_Rooms is null, initialize it with capacity 1 and add the first room.
        if (this->all_Rooms == nullptr) {
            this->capacity_Rooms = 1;
            this->all_Rooms = new Room*[capacity_Rooms];
            this->num_Rooms = 0;
            this->all_Rooms[this->num_Rooms] = new_room;
            this->num_Rooms ++;
            return;
        }
        // If the number of rooms equals the capacity, increase the capacity.
        if (this->num_Rooms == this->capacity_Rooms) {
            Room** new_rooms = new Room*[this->capacity_Rooms +1];
            // Copy existing rooms to the new array.
            for (int i = 0; i < this->num_Rooms; i++) {
                new_rooms[i] = this->all_Rooms[i];
            }
            delete[] this->all_Rooms;
            this->all_Rooms = new_rooms;
            this->capacity_Rooms = this->capacity_Rooms +1;
        }
        // Add the new room to the array and increment the room count.
        this->all_Rooms[this->num_Rooms] = new_room;
        this->num_Rooms ++;
    } catch (std::bad_alloc& e) {
        throw MemoryProblemException();
    }
    // Link the new room in the dungeon based on the string identifier.
    Room* curr_room = this->first_room;
    int number_of_digit = w.length();
    try {
        for (int i = 0; i < number_of_digit-1; i++) {
            int index = w[i] - '0';
            // If there is no room at the given index, return without adding.
            if ((*curr_room)[index] == nullptr) {
                throw InvalidRoomException();
            }
            curr_room = (*curr_room)[index];
        }
        // Add the new room at the last index in the identifier.
        int lastIndex = w[w.length() - 1] - '0';
        (*curr_room)[lastIndex] = new_room;
    } catch (InvalidRoomException& e) {
        this->end_game();
        throw;
    }
}

// Cleans up all dynamically allocated memory for rooms and resets the game state.
void Game::end_game() {
    if (this->all_Rooms != nullptr) {
        // Delete each room in the array.
        for (int i = 0; i < this->num_Rooms; i++) {
            delete this->all_Rooms[i];
            this->all_Rooms[i] = nullptr;
        }
        delete[] this->all_Rooms;
        this->all_Rooms = nullptr;
    }
    // Reset room count and capacity.
    this->num_Rooms = 0;
    this->capacity_Rooms = 0;
}

// Reads the dungeon configuration from a file and initializes the rooms.
int Game::read_configuration(const std::string& configuration_File) {
    std::ifstream file(configuration_File);
    // Return 1 if the file could not be opened.
    if (!file.is_open()) {
        return 2;
    }
    try {
        // Initialize the first room and add it to the game.
        Room* first_room_to_add = new Room(0,0,0,"N");
        this->first_room = first_room_to_add;
        add_room("0", first_room_to_add);
        std::string w,mon;
        int x,y,z;
        // Read room data from the file and add rooms accordingly.
        while (file >> w >> x >> mon) {
            if (mon == "N") {
                y = z = 0;
            } else {
                file >> y >> z;
            }
            //checks if some of the arguments entered is negative
            if (x < 0 || y < 0 || z < 0) {
                throw InvalidValueException();
            }
            //create new room and add it to the corridor
            Room* new_room = new Room(x,y,z,mon);
            add_room(w,new_room);
        }
        file.close();
        return 0;
    } catch (InvalidRoomException& e) {
        this->end_game();
        return 1;
    } catch (InvalidValueException& e) {
        this->end_game();
        return 2;
    } catch (std::bad_alloc& e) {
        this->end_game();
        throw MemoryProblemException();
    }
}

// Simulates a battle between the player and a monster.
// Returns 0 if the player wins, 1 if the player loses, and 2 for an error.
int Game::battle(Player* player, Monster* monster) {
    if (player == nullptr || monster == nullptr) {
        this->end_game();
        throw MemoryProblemException();
    }
    // Continue the battle until either the player or the monster has 0 life.
    while (player->get_curr_life()!= 0 || monster->get_curr_life() != 0) {
        *monster -= *player;
        std::cout << "You deal " << player->get_damage() << " damage to the " << monster->get_name() << " and leave it with " << monster->get_curr_life() << " health" << std::endl;
        this->player->turn(true);
        // If the monster's life reaches 0, the player wins.
        if (monster->get_curr_life() == 0) {
            std::cout << "You defeat the " << monster->get_name() << " and go on with your journey" << std::endl;
            return 0;
        }
        monster->attack_player(*player);
        int status = player->rival_damage(monster->get_calculated_damage());
        std::cout << "The " << monster->get_name() << " deals " << status << " damage to you and leaves you with " << player->get_curr_life() << " health" << std::endl;
        // If the player's life reaches 0, the player loses.
        if (player->get_curr_life() == 0) {
            return 1;
        }
    }
    return 2;
}

int Game::what_room_to_go(Room* curr_room) {
    if (curr_room == nullptr) {
        this->end_game();
        throw MemoryProblemException();
    }
    // Handle corridors and player choices.
    int num_of_options = curr_room->get_next_Rooms_size();
    if (num_of_options == 0) {
        std::cout << "The room continues and opens up to the outside. You won against the dungeon" << std::endl;
        return -1;
    }
    //there is only one room available
    if (num_of_options == 1) {
        std::cout << "You see a single corridor ahead of you labeled " << num_of_options - 1 << std::endl;
        int choice;
        std::cin >> choice;
        return choice;
    }
    //there is more than one room available
    if (num_of_options > 1) {
        std::cout << "You see corridors labeled from 0 to " << num_of_options - 1 << ". Which one will you choose?"<< std::endl;
        int choice;
        std::cin >> choice;
        return choice;
    }
    return -2;
}

// Runs the main game loop, allowing the player to explore rooms and encounter monsters.
void Game::run_game() {
    Room* curr_room = this->first_room;
    // Continue the game until the player exits or loses.
    while (curr_room != nullptr) {
        std::cout << *player << std::endl;
        // Heal the player if there is a campfire in the room.
        if (curr_room->get_fire() > 0 ) {
            std::cout << "You sit by the campfire and heal " << curr_room->get_fire() << " health" << std::endl;
            *this->player += curr_room->get_fire();
            this->player->turn(false);
        }
        // Handle empty rooms.
        if (curr_room->get_fire() == 0 && curr_room->get_monster_life() == 0) {
            std::cout << "You arrive to an empty room" << std::endl;
        }
        // Handle rooms with monsters.
        if (curr_room->get_monster_life() > 0) {
            Monster* monster = nullptr;
            try {
                if (curr_room->get_monster() == "D") {
                    monster = new Dragon("Dragon", curr_room->get_monster_life(),curr_room->get_monster_life(),curr_room->get_monster_damage());
                } else if (curr_room->get_monster() == "G") {
                    monster = new Goblin("Goblin", curr_room->get_monster_life(),curr_room->get_monster_life(),curr_room->get_monster_damage());
                }
            } catch (std::bad_alloc& e) {
                this->end_game();
                throw MemoryProblemException();
            }
            // Compare the player and monster to determine their relative strength.
            if (*this->player > *monster) {
                std::cout << "You encounter a smaller "<< monster->get_name() << std::endl;
            }
            else if (*this->player == *monster) {
                std::cout << "You encounter a equally sized " << monster->get_name() << std::endl;
            }
            else {
                std::cout << "You encounter a larger " << monster->get_name() << std::endl;
            }
            std::cout << *monster << std::endl;
            int status = this->battle(player, monster);
            delete monster;
            // Handle the outcome of the battle.
            if (status == 1) {
                std::cout << "You lost to the dungeon" << std::endl;
                this->end_game();
                break;
            }
            if (status == 2) {
                this->end_game();
                throw MemoryProblemException();
            }
        }
        // Handle corridors and player choices.
        int choice = what_room_to_go(curr_room);
        if (choice == -2 || choice == -1) {
            this->end_game();
            break;
        }
        this->player->turn(false);
        curr_room = (*curr_room)[choice];
        continue;
    }
}