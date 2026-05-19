#pragma once
#include "Monster.h"
#include <cmath>

/**
 * @brief Represents a dragon, a type of monster in the game.
 */
class Dragon : public Monster {
public:
    /**
     * @brief Constructor for creating a dragon.
     * @param name Name of the dragon.
     * @param max_life Maximum life points.
     * @param curr_life Current life points.
     * @param damage Damage value.
     */
    Dragon(const std::string &name, int max_life, int curr_life, int damage);
    /**
    * @brief Destructor for the dragon.
    */
    ~Dragon() override;
    /**
     * @brief Attacks a fighter player.
     * Reduces the fighter's life based on the dragon's damage.
     */
    virtual void attack_fighter() ;
    /**
    * @brief Attacks a sorcerer player.
    * Reduces the sorcerer's life based on the dragon's damage.
    */
    virtual void attack_sorcerer() ;
    /**
     * @brief Prints dragon details.
     * @param os Output stream to print to.
     */
    virtual void print(std::ostream& os) const;

};