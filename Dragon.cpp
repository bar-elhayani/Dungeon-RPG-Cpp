#include "Dragon.h"
#include <iostream>
#include <cmath>

//constructor of Dragon who is a heir of an Monster
Dragon::Dragon(const std::string &name, int max_life, int curr_life, int damage) : Monster(name, max_life, curr_life, damage) {}

//destructor of a dragon
Dragon::~Dragon() {
}

//function who calculate the amount of damage that dragon cause to fighter
void Dragon::attack_fighter()  {
    calculated_damage  = std::round(static_cast<double>(this->damage) / 2);
}

//function who calculate the amount of damage that dragon cause to sorcerer
void Dragon::attack_sorcerer()  {
    calculated_damage  = std::round(static_cast<double>(this->damage) * 2);
}

//function that prints the details of a dragon
void Dragon::print(std::ostream& os) const {
    os << this->name << " (" << this->curr_life << "/" << this->max_life << ") - " << this->damage;
}


