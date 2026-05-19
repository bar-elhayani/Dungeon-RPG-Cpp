#include "Player.h"
#include <iostream>
#include "Monster.h"

class Monster;
//constructor of Player who is a heir of an entity
Player::Player(const std::string& name, int max_life, int curr_life, int damage)
    : Entity(name, max_life, curr_life, damage) {}

//destructor of player
Player::~Player() {}

//+= operator who add amount of life to the curr_life of the entity
Player& Player::operator+=(int life_to_add) {
    this->curr_life += life_to_add;
    if(curr_life > max_life) {
        curr_life = max_life;
    }
    return *this;
}

//returns if entity is bigger than other based on their curr life and damage
bool Player::operator>(const Monster& monster) const {
    if ((this->curr_life * this->damage) > (monster.get_curr_life() * monster.get_damage())) {
        return true;
    }
    return false;
}

//returns if 2 different entities are equal based on their curr life and damage
bool Player::operator==(const Monster& monster) const {
    return (this->curr_life * this->damage) == (monster.get_curr_life() * monster.get_damage());
}