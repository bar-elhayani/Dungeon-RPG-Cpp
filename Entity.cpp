#include "Entity.h"
#include <cctype>

//initialize the fields of Entity who entered
Entity::Entity(const std::string &name, int max_life, int curr_life, int damage) : name(name), max_life(max_life), curr_life(curr_life), damage(damage) {
}
//Destructor to Entity
Entity::~Entity() {}

//-= operator who subtract a life from entity based on the amount of damage of another entity
Entity& Entity::operator-=(const Entity& entity) {
    this->curr_life -= entity.damage;
    if(curr_life < 0) {
        curr_life = 0;
    }
    return *this;
}

//function who prints a details about entity
std::ostream& operator<<(std::ostream& os, const Entity& entity) {
    entity.print(os);
    return os;
}

//returns if 2 different entities are equal based on their curr life and damage
bool Entity::operator==(const Entity& entity) const {
    return (this->curr_life * this->damage) == (entity.curr_life * entity.damage);
}

//returns if entity is bigger than other based on their curr life and damage
bool Entity::operator>(const Entity& entity) const {
    if ((this->curr_life * this->damage) > (entity.curr_life * entity.damage)) {
        return true;
    }
    return false;
}

//returns entity damage
int Entity::get_damage()const {
    return this->damage;
}

//returns entity current life
int Entity::get_curr_life()const {
    return this->curr_life;
}

//returns entity max life
int Entity::get_max_life()const {
    return this->max_life;
}

//function who prints the details about the entitty
void Entity::print(std::ostream& os) const {
    os <<  this->name << " (" << this->curr_life << "/" << this->max_life << ") - " << this->damage;
}
//function who return the name of the entity
std::string Entity::get_name()const {
    std::string lower_name = this->name;
    if (!lower_name.empty() && std::isupper(lower_name[0])) {
        lower_name[0] = std::tolower(lower_name[0]);
    }
    return lower_name;
}
