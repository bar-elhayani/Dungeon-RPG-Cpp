#pragma once
#include "Player.h"

/**
 * @brief Represents a sorcerer, a type of player in the game.
 */
class Sorcerer : public Player {
protected:
    int rounds_counter;
    int original_damage;
    bool is_ability_active;
public:
    /**
     * @brief Constructor for creating a sorcerer.
     * @param name Name of the sorcerer.
     * @param max_life Maximum life points.
     * @param curr_life Current life points.
     * @param damage Damage value.
     */
    Sorcerer(const std::string &name, int max_life, int curr_life, int damage);
    /**
    * @brief Destructor for the sorcerer.
    */
    ~Sorcerer() override;
    /**
    * @brief Executes a sorcerer's turn in the game.
    * Manages the special ability and regular actions.
    * @param is_battle Indicates if the turn is during a battle.
    */
    void turn(bool is_battle) override;
    /**
     * @brief Activates the sorcerer's special ability.
     * Doubles the damage for a limited number of turns.
     */
    void special_ability();
    /**
     * @brief fighter between monster and a sorcerer, calls to the monster's attack sorcerer function.
     * Reduces the monster's life based on the sorcerer's damage.
     * @param monster Reference to the monster being attacked.
     */
    void attack_monster(Monster &monster) override;
    /**
     * @brief Prints sorcerer details.
     * @param os Output stream to print to.
     */
    void print(std::ostream& os) const override;
    /**
     * @brief Reduces the sorcerer's current life points.
     * @param damage Damage to reduce from current life.
     */
    void reduce_life(int damage) override;
    /**
     * @brief Calculates damage dealt to the rival.
     * @param damage Damage value.
     * @return Calculated damage.
     */
    int rival_damage(int damage) override;

    bool operator>(const Monster& monster) const override;

    bool operator==(const Monster& monster) const override;

};