#pragma once
#include "Entity.h"

class Player;
/**
 * @brief Represents a monster in the game, inheriting from Entity.
 */
class Monster : public Entity {
protected:
    //the damage the monster done to the player
    int calculated_damage;
public:
    /**
     * @brief Constructor for creating a monster.
     * @param name Name of the monster.
     * @param max_life Maximum life points.
     * @param curr_life Current life points.
     * @param damage Damage value.
     */
    Monster(const std::string &name, int max_life, int curr_life, int damage);
    /**
    * @brief Destructor for the monster.
    */
    ~Monster() override;
    /**
     * @brief Attacks a player and reduces their life points.
     * @param player Reference to the player being attacked.
     */
    virtual void attack_player(Player& player);
    /**
    * @brief Attacks a fighter and reduces their life points.
    */
    virtual void attack_fighter() = 0;
    /**
    * @brief Attacks a sorcerer and reduces their life points.
    */
    virtual void attack_sorcerer() = 0;
    /**
     * @brief Prints monster details.
     * @param os Output stream to print to.
     */
    virtual void print(std::ostream& os) const = 0;
    /**
    * @brief calculate the damage the monster done to the player
    */
    virtual int get_calculated_damage()const;

};