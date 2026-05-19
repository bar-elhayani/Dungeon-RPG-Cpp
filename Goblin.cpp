#include "Goblin.h"
#include <iostream>
#include <cmath>

//constructor of Goblin who is a heir of an Monster
Goblin::Goblin(const std::string &name, int max_life, int curr_life, int damage) : Monster(name, max_life, curr_life, damage){}

//destructor of a goblin
Goblin::~Goblin() {
}

//function who calculate the amount of damage that goblin cause to fighter
void Goblin::attack_fighter()  {
    calculated_damage = std::round(static_cast<double>(this->damage) * 2);
}

//function who calculate the amount of damage that goblin cause to sorcerer
void Goblin::attack_sorcerer()  {
    calculated_damage = std::round(static_cast<double>(this->damage) / 2);
}

//function who prints the details of a goblin
void Goblin::print(std::ostream& os) const {
    os << this->name << " (" << this->curr_life << "/" << this->max_life << ") - " << this->damage;
}

