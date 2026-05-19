#pragma once
#include <iostream>


class Room {
private:
    std::string mon;
    int fire;
    int monster_life;
    int monster_damage;
    Room** next_Rooms;
    int next_Rooms_size;
    int capacity_next_rooms;
public:
    /**
 * @brief Constructor for the Room class.
 * @param fire The fire level of the room.
 * @param monster_life The initial life of the monster in the room.
 * @param monster_damage The damage dealt by the monster in the room.
 */
    Room(int fire, int monster_life, int monster_damage, const std::string &mon);
    /**
     * @brief Destructor for the Room class. Frees dynamically allocated memory for next rooms.
     */
    ~Room();

    /**
 * @brief Overloads the subscript operator for accessing next rooms by index.
 * @param index The index of the next room to access.
 * @return Reference to the Room at the specified index.
 */
    Room*& operator[](int index);

    /**
 * @brief Overloads the subscript operator for constant access to next rooms by index.
 * @param index The index of the next room to access.
 * @return Constant reference to the Room at the specified index.
 */
    Room* operator[](int index) const;

    /**
 * @brief Adds a new room to the array of next rooms at a specified index.
 * If the index exceeds the current capacity, the array is resized.
 * @param new_room Pointer to the new room to add.
 * @param index The index where the new room should be added.
 */
    void addRoomtoarray(int index);

   /**
 * @brief Gets the fire level of the room.
 * @return The fire level as an integer.
 */
    int get_fire()const;

   /**
 * @brief Gets the monster's initial life in the room.
 * @return The monster's life as an integer.
 */
    int get_monster_life()const;

   /**
 * @brief Gets the damage dealt by the monster in the room.
 * @return The monster's damage as an integer.
 */
    int get_monster_damage()const;

   /**
 * @brief Gets the current number of next rooms.
 * @return The size of the next rooms array.
 */
    int get_next_Rooms_size()const;

   std::string get_monster()const;

};