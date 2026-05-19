#include "Sorcerer.h"
#include <iostream>
#include "Monster.h"

//constructor of a sorcerer who heir from player
Sorcerer::Sorcerer(const std::string &name, int max_life, int curr_life, int damage) : Player(name, max_life, curr_life, damage),rounds_counter(0),
                                                                                       is_ability_active(false),original_damage(damage){}
//destructor of a sorcerer
Sorcerer::~Sorcerer() {
}

//function who represents a round in the game of sorcerer and checks if he has a special ability available
void Sorcerer::turn(bool is_battle) {
    if (this->rounds_counter > 0 && !this->is_ability_active) {
        this->rounds_counter--;
    }
    if (is_ability_active == true && is_battle == true) {
        damage = this->original_damage;
        is_ability_active = false;
    }
    if (this->rounds_counter == 0 && !is_ability_active) {
        special_ability();
    }
}

//function who activate the special ability of a sorcerer which is double damage for a round
void Sorcerer:: special_ability() {
    if (!is_ability_active) {
        this->damage *= 2;
        this->rounds_counter = 4;
        is_ability_active = true;
    }
}

//function that helps monster to attack player and discover that it attacks a sorcerer
void Sorcerer::attack_monster(Monster &monster) {
    monster.attack_sorcerer();
}

//function who prints the details of a sorcerer
void Sorcerer::print(std::ostream& os) const {
    os << this->name << " (" << this->curr_life << "/" << this->max_life << ") - " << this->original_damage;
}

//function who reduce the life of a sorcerer after monster attacked him
void Sorcerer::reduce_life(int damage) {
    this->curr_life -= damage;
    if(this->curr_life < 0) {
        this->curr_life = 0;
    }
}

//function who return the amount of damage that monster caused to a sorcerer
int Sorcerer::rival_damage(int damage){
    return damage;
}

bool Sorcerer::operator>(const Monster& monster) const {
    if ((this->curr_life * this->original_damage) > (monster.get_curr_life() * monster.get_damage())) {
        return true;
    }
    return false;
}

//returns if 2 different entities are equal based on their curr life and damage
bool Sorcerer::operator==(const Monster& monster) const {
    return (this->curr_life * this->original_damage) == (monster.get_curr_life() * monster.get_damage());
}
