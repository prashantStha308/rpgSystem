#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include<utility>

#include "resourceManager.h"
#include "positionManager.h"

class Character {
protected:
    // Character Details
    std::string name;
    std::string _class;
    unsigned int health;
    // Positoin / Face Direction
    PositionManager position; //handel position
    // Resources
    ResourceManager resource; //to handel resources

public:

    Character(std::string name, std::string _class, unsigned int hp, int posX = 0, int posY = 0);

    // Pure Virtual Functions
    virtual void attack(Character& target);
    virtual void displayStats();

    // Getters
    std::string getName() const;
    std::string getClass() const;
    unsigned int getHealth() const;
    std::pair< int , int > getPosition();

    // Setters
    void setPosition( int x , int y );
    // Resources
    void depleteMana( unsigned int );
    void depleteStamina( unsigned int );
    void depleteVigor( unsigned int );
    void gainMana( unsigned int );
    void gainStamina( unsigned int );
    void gainVigor( unsigned int );

    // Actions
    virtual void takeDamage( unsigned int );


    virtual ~Character() {}
};

#endif
