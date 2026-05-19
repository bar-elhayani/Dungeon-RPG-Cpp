#pragma once
#include "Entity.h"
class Monster;

/**
 * @brief Represents a player in the game, inheriting from Entity.
 */
class Player : public Entity {
public:
    /**
     * @brief Constructor for creating a player.
     * @param name Name of the player.
     * @param max_life Maximum life points.
     * @param curr_life Current life points.
     * @param damage Damage value.
     */
    Player(const std::string &name, int max_life, int curr_life, int damage);
    /**
     * @brief Destructor for the player.
     */
    ~Player() override;
    /**
     * @brief Performs actions for a player's turn in the game.
     * @param is_battle Indicates if the turn is during a battle.
     */
    virtual void turn(bool is_battle) = 0;
    /**
     * @brief Allows the player to and monster to have a fight.
     * @param monster Reference to the monster for fight.
     */
    virtual void attack_monster(Monster& monster) = 0;
    /**
     * @brief Prints player details.
     * @param os Output stream to print to.
     */
    virtual void print(std::ostream& os) const = 0;
    /**
     * @brief Increases the current life points of the entity.
     *        Ensures that current life does not exceed maximum life.
     * @param life_to_add Amount of life points to add.
     * @return Reference to the updated Entity object.
     */
    virtual Player& operator+=(int life_to_add);
    /**
     * @brief Reduces the player's current life points.
     * @param damage Damage to reduce from current life.
     */
    virtual void reduce_life(int damage) = 0;
    /**
     * @brief Calculates damage dealt to the rival.
     * @param damage Damage value.
     * @return Calculated damage.
     */
    virtual int rival_damage(int damage) = 0;

    virtual bool operator>(const Monster& monster) const;
    /**
     * @brief Compares two monsters for equality based on their life and damage product.
     * @param monster The monster to compare with.
     * @return True if the entities are equal, false otherwise.
     */
    virtual bool operator==(const Monster& monster) const;


};