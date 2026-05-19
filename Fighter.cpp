#include "Fighter.h"
#include <iostream>
#include "Monster.h"

//constructor of a fighter who heir from player
Fighter::Fighter(const std::string &name, int max_life, int curr_life, int damage) : Player(name, max_life, curr_life, damage),
                                                                                    is_ability_available(0), is_ability_active(false){}

//destructor of a fighter
Fighter::~Fighter() {
}

//function who represents a round in the game of fighter and checks if he has a special ability available
void Fighter::turn(bool is_battle) {
    if (this->is_ability_available > 0) {
        this->is_ability_active = false;
        this->is_ability_available--;
    }
}

//function that helps monster to attack player and discover that it attacks a fighter
void Fighter::attack_monster(Monster &monster) {
    monster.attack_fighter();
}

//function who prints the details of a fighter
void Fighter::print(std::ostream& os) const {
    os << this->name << " (" << this->curr_life << "/" << this->max_life << ") - " << this->damage;
}

//function who reduce the life of a fighter after monster attacked him
void Fighter::reduce_life(int damage) {
    if (this->is_ability_available == 0) {
        this->is_ability_active = true;
        this->is_ability_available = 4;
    }
    else {
        this->curr_life -= damage;
        if(this->curr_life < 0) {
            this->curr_life = 0;
        }
    }
}

//function who return the amount of damage that monster caused to a fighter
//returns 0 if the special ability of a fighter is on
int Fighter::rival_damage(int damage){
    if (this->is_ability_active == true) {
        return 0;
    }
    return damage;
}