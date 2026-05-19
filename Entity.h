#pragma once
#include <string>
#include <iostream>
#include <cctype>


/**
 * @class Entity
 * @brief Represents a game entity with life, damage, and a name.
 * name represents the name odf the entity
 * curr_life represents the current amount of lise of the entity
 * damage represents the damage the entity can make to another one
 */

class Entity {
protected:
    std::string name;
    int max_life;
    int curr_life;
    int damage;
public:
    /**
     * @brief Constructs an Entity with specified name, maximum life, current life, and damage.
     * @param name The name of the entity.
     * @param max_life The maximum life points.
     * @param curr_life The current life points.
     * @param damage The damage dealt by the entity.
     */
    Entity(const std::string& name, int max_life, int curr_life, int damage);

    /**
     * @brief Destructor for the Entity class.
     */
    virtual ~Entity();

    /**
     * @brief Decreases the current life points by the damage of another entity.
     *        Ensures that current life does not fall below zero.
     * @param entity The entity whose damage will be subtracted.
     * @return Reference to the updated Entity object.
     */
    virtual Entity& operator-=(const Entity& entity);


    /**
     * @brief Outputs the entity's details to an output stream.
     * @param os The output stream.
     * @param entity The entity to be displayed.
     * @return Reference to the output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const Entity& entity);

    /**
     * @brief Compares two entities for equality based on their life and damage product.
     * @param entity The entity to compare with.
     * @return True if the entities are equal, false otherwise.
     */
    virtual bool operator==(const Entity& entity) const;

    /**
     * @brief Compares two entities to determine if the current entity is "greater" based on life and damage product.
     * @param entity The entity to compare with.
     * @return True if the current entity is greater, false otherwise.
     */
    virtual bool operator>(const Entity& entity) const;

    /**
     * @brief Gets the damage dealt by the entity.
     * @return The damage value.
     */
    virtual int get_damage()const;

    /**
     * @brief Gets the current life points of the entity.
     * @return The current life value.
     */
    virtual int get_curr_life()const;

    /**
     * @brief Gets the maximum life points of the entity.
     * @return The maximum life value.
     */
    virtual int get_max_life()const;
    /**
     * @brief Gets the entity's name.
     * @return Name of the entity.
     */
    virtual std::string get_name()const;
    /**
     * @brief Prints entity details.
     * @param os Output stream to print to.
     */
    virtual void print(std::ostream& os) const = 0;
};