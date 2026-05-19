#include "Game.h"
#include <iostream>
#include <string>
#include "Player.h"
#include "Exceptions.h"
#include "Fighter.h"
#include "Sorcerer.h"

/**
 * @brief The main entry point for the game.
 *
 * This function initializes the game by parsing command-line arguments, creating
 * the player and game objects, reading the configuration file, and running the game.
 * It ensures proper error handling and cleanup in case of failures during the
 * initialization or runtime.
 *
 * @param argc The number of command-line arguments (should be 5).
 * @param argv The array of command-line arguments:
 *        - argv[1]: Player type ("F" for Fighter, "S" for Sorcerer).
 *        - argv[2]: Initial player life (integer).
 *        - argv[3]: Initial player damage (integer).
 *        - argv[4]: Path to the configuration file (string).
 *
 * @return int Returns 0 on successful execution.
 *             Returns 1 if an error occurs, including:
 *             - Invalid input values (e.g., negative life or damage).
 *             - Memory allocation issues.
 *             - Errors in the configuration file (invalid or corrupted data).
 *
 * @exception InvalidValueException Thrown if invalid arguments or configuration values are provided.
 * @exception MemoryProblemException Thrown if memory allocation fails during object creation.
 * @exception InvalidRoomException Thrown if an invalid room structure is detected in the configuration file.
 *
 * @details
 * - The program validates all inputs and ensures the proper creation of objects.
 * - If an error occurs during initialization, all allocated resources are deallocated before exiting.
 * - The player and game objects are created dynamically to manage their lifetimes explicitly.
 * - Exception handling ensures the program exits gracefully with proper error messages in case of issues.
 *
 */

int main(int argc, char *argv[]) {
    try {
        //checks that we received all the args we expected for
        if (argc != 5) {
            throw InvalidValueException();
        }
        //initialize the player's type, life and damage amounts
        std::string player_type = argv[1];
        int player_life = std::stoi(argv[2]);
        int player_damage = std::stoi(argv[3]);
        std::string configuration_file = argv[4];
        //in case we received negative parameters throw an exception
        if (player_life < 0 || player_damage < 0) {
            throw InvalidValueException();
        }
        //created new player based on the type of the player
        Player* player = nullptr;
        try {
            if (player_type == "F") {
                player = new Fighter("Fighter", player_life,player_life,player_damage);
            } else if (player_type == "S") {
                player = new Sorcerer("Sorcerer", player_life,player_life,player_damage);
            } else {
                throw InvalidValueException();
            }
        } catch (std::bad_alloc& e) {                   //in case the creation of the player failed throw a exception of memoty problem
            throw MemoryProblemException();
        }
        //create new Game
        Game* new_game = nullptr;
        try {
            new_game = new Game(player);
        } catch (std::bad_alloc& e) {                       //in case the creation of the game failed throw a exception of memoty problem and delete the player we created
            delete player;
            throw MemoryProblemException();
        }
        try {
            //read the configuration file and initialize the game
            int read_status = new_game->read_configuration(configuration_file);
            //in case one of the rooms path was invalid
            if (read_status == 1) {
                throw InvalidRoomException();
            }
            //in case one of the fields of the rooms in the configuration file is invalid (negative)
            if (read_status == 2) {
                throw InvalidValueException();
            }
            //run the function who runs the game and start it
            new_game->run_game();
            //checks if some exceptions threw in the run of the game, in that case - delete the game, print a message and return 1
        } catch (InvalidRoomException& e) {
            std::cout << e.what() << std::endl;
            delete new_game;
            return 1;
        } catch (MemoryProblemException& e) {
            std::cout << e.what() << std::endl;
            delete new_game;
            return 1;
        } catch (InvalidValueException& e) {
            std::cout << e.what() << std::endl;
            delete new_game;
            return 1;
        }
        //delete the memory allocated to the player and the game if everything works good
        delete new_game;
        //if it catch some of the next exceptions here, it means that it doesnt threw from the game so it means there are nothing to delete, just print a message and return 1
    } catch (InvalidValueException& e) {
        std::cout << e.what() << std::endl;
        return 1;
    } catch (MemoryProblemException& e) {
        std::cout << e.what() << std::endl;
        return 1;
    } catch (InvalidRoomException& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    //returns 0 if everything works good
    return 0;
}