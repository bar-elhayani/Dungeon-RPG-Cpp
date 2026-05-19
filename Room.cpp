#include "Room.h"
#include "Exceptions.h"

// Constructor to initialize a Room object with fire level, monster life, and monster damage.
// Initializes next_Rooms to nullptr and sets the size and capacity of next rooms to zero.
Room::Room(int fire, int monster_life, int monster_damage, const std::string &mon)
: fire(fire), monster_life(monster_life), monster_damage(monster_damage), mon(mon), next_Rooms(nullptr), next_Rooms_size(0), capacity_next_rooms(0) {
}

// Destructor to clean up dynamically allocated memory for next_Rooms.
Room::~Room() {
    if (next_Rooms != nullptr) {
        delete[] next_Rooms;
        next_Rooms = nullptr;
    }
}

// Adds a new room at a specific index in the next_Rooms array.
// If the index exceeds the current capacity, it reallocates memory to fit the new index.
void Room::addRoomtoarray(int index) {
    try {
        // Check if the index exceeds the current capacity.
        if (index >= capacity_next_rooms) {
            // Allocate a new array with size index + 1.
            Room** new_rooms = new Room*[index +1];
            // Copy existing rooms to the new array.
            for (int i = 0; i < capacity_next_rooms; i++) {
                new_rooms[i] = next_Rooms[i];
            }
            // Initialize remaining entries in the new array to nullptr.
            for (int i = capacity_next_rooms; i < index + 1; i++) {
                new_rooms[i] = nullptr;
            }
            // Delete old array and update next_Rooms to point to the new array.
            delete[] this->next_Rooms;
            this->next_Rooms = new_rooms;
            capacity_next_rooms = index + 1;
        }
    } catch (std::bad_alloc e) {
        throw MemoryProblemException();
    }
}

// Overloaded subscript operator to access the next room by index (non-const version).
Room*& Room::operator[](int index) {
    if (index >= this->capacity_next_rooms) {
        addRoomtoarray(index);
    }
    // Add the new room at the specified index if it's not already set.
    if (next_Rooms[index] == nullptr) {
        next_Rooms_size++;
    }
    return next_Rooms[index];
}

// Overloaded subscript operator to access the next room by index (const version).
Room* Room::operator[](int index) const {
    return next_Rooms[index];
}

// Getter for fire level in the room.
int Room ::get_fire() const{
    return this->fire;
}

// Getter for the monster's life in the room.
int Room ::get_monster_life()const {
    return this->monster_life;
}

// Getter for the monster's damage in the room.
int Room ::get_monster_damage()const {
    return this->monster_damage;
}

// Getter for the number of next rooms connected to this room.
int Room ::get_next_Rooms_size()const {
    return this->next_Rooms_size;
}

std::string Room::get_monster()const {
    return this->mon;
}

