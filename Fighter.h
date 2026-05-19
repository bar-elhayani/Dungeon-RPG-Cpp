#pragma once
#include "Player.h"

/**
 * @brief Represents a fighter, a type of player in the game.
 */
class Fighter : public Player {
    protected:
    int is_ability_available;
    bool is_ability_active;
public:
    /**
     * @brief Constructor for creating a fighter.
     * @param name Name of the fighter.
     * @param max_life Maximum life points.
     * @param curr_life Current life points.
     * @param damage Damage value.
     */
    Fighter(const std::string &name, int max_life, int curr_life, int damage);

    /**
     * @brief Destructor for the fighter.
     */
    ~Fighter() override;

    /**
     * @brief Executes a fighter's turn in the game.
     * The fighter performs actions based on game state.
     * @param is_battle Indicates if the turn is during a battle.
     */
    void turn(bool is_battle) override;

    /**
     * @brief fighter between monster and fighter.
     * calls the monster's fight function against fighter.
     * @param monster Reference to the monster we fight.
     */
    void attack_monster(Monster &monster) override;

    /**
     * @brief Prints fighter details.
     * @param os Output stream to print to.
     */
    void print(std::ostream& os) const override;

    /**
     * @brief Reduces the fighter's current life points.
     * @param damage Damage to reduce from current life.
     */
    void reduce_life(int damage) override;

    /**
     * @brief Calculates damage dealt to the rival.
     * @param damage Damage value.
     * @return Calculated damage.
     */
    int rival_damage(int damage) override;

};