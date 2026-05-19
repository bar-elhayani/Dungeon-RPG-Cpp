#pragma once
#include <string>
#include "Room.h"
#include "Entity.h"
#include "Player.h"

class Game {
private:
    Room* first_room;
    Player* player;
    Room** all_Rooms;
    int num_Rooms;
    int capacity_Rooms;

public:
    /**
 * @brief Constructor that initializes the Game with a player entity.
 *
 * @param player Pointer to the player's Entity object.
 */
    Game(Player* player);
    /**
     * @brief Destructor that cleans up allocated resources.
     */
    ~Game();
    /**
     * @brief Adds a new room to the game using a specified string identifier.
     *
     * This function manages memory allocation and dynamic resizing of the internal
     * room storage, and it links rooms according to the provided identifier string.
     *
     * @param w A string representing the path identifier for the new room.
     * @param new_room Pointer to the new Room object to be added.
     */
    void add_room(const std::string& w, Room* new_room);
    /**
     * @brief Reads the dungeon configuration from a file and sets up rooms accordingly.
     *
     * This function reads room data from a file and adds rooms to the game using add_room().
     * The file is expected to contain room information in a specific format.
     *
     * @param configuration_File Path to the configuration file.
     * @return int Returns 0 on success, 1 if the file could not be opened.
     */
    int read_configuration(const std::string& configuration_File);
    /**
     * @brief Simulates a battle between the player and a monster.
     *
     * The function performs a turn-based battle where both the player and the monster
     * attack each other until one of them is defeated. It outputs battle details to the console.
     *
     * @param player Pointer to the player's Entity object.
     * @param monster Pointer to the monster's Entity object.
     * @return int Returns 0 if the player wins, 1 if the monster wins, 2 if an error occurs.
     */
    int battle(Player* player, Monster* monster);
    /**
      * @brief asking from the user what room he wants to continue.
      *
      * The function checks how options of rooms the player has to move in the next stemp.
      * @param curr_room Pointer to the the current room the layer in.
      * @return int Returns -2 if something wrong happened, return -1 if the player wins,or the index of the next room the player chose.
      */
    int what_room_to_go(Room* curr_room);
    /**
     * @brief Ends the game by deallocating all dynamically allocated rooms.
     */
    void end_game();
    /**
     * @brief Runs the main game loop.
     *
     * This function controls the flow of the game, handling player actions,
     * room traversal, battles, and game events until the game ends.
     */
    void run_game();
};
