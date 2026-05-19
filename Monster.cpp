#include "Monster.h"
#include <iostream>
#include "Player.h"

//constructor of a monster who heir of an entity
Monster::Monster(const std::string& name, int max_life, int curr_life, int damage)
    : Entity(name, max_life, curr_life, damage),calculated_damage(-1) {}

//destructor of a monster
Monster::~Monster() {}

//function who helps monster attac a player and discover what player it attacks
void Monster::attack_player(Player& player) {
    player.attack_monster(*this);
    //after finding which player the monster attacked and calculated the amount of damage, reduce it from the player's life
    player.reduce_life(calculated_damage);
}
//function who returns the amount of the monster reduce to the player
int Monster::get_calculated_damage()const {
    return calculated_damage;
}
