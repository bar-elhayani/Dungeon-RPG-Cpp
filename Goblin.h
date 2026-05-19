#pragma once
#include "Monster.h"
#include <cmath>

/**
 * @brief Represents a goblin, a type of monster in the game.
 */
class Goblin : public Monster {
public:
    /**
     * @brief Constructor for creating a goblin.
     * @param name Name of the goblin.
     * @param max_life Maximum life points.
     * @param curr_life Current life points.
     * @param damage Damage value.
     */
    Goblin(const std::string &name, int max_life, int curr_life, int damage);
    /**
    * @brief Destructor for the goblin.
    */
    ~Goblin() override;
    /**
     * @brief Attacks a fighter player.
     * Reduces the fighter's life based on the goblin's damage.
     */
    virtual void attack_fighter() ;
    /**
     * @brief Attacks a sorcerer player.
     * Reduces the sorcerer's life based on the goblin's damage.
     */
    virtual void attack_sorcerer() ;
    /**
     * @brief Prints goblin details.
     * @param os Output stream to print to.
     */
    virtual void print(std::ostream& os) const;

};