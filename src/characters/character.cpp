#include <iostream>
#include<string>
// custom
#include "character.h"
#include "colors.h"
#include "positionManager.h"

// namespaces
using namespace std; // std::cout<<...
using namespace color; // color::RED....

// Constructor
Character::Character(std::string name, std::string _class, unsigned int hp, int posX, int posY)
    : name(name), _class(_class), health(hp), position(posX, posY), resource() {}

// Getters
string Character::getName() const { return name; }
string Character::getClass() const { return _class; }
unsigned int Character::getHealth() const { return health; }
// Setters
void Character::setPosition( int x , int y  ){
    position.setPosition( x , y );

    cout << MAGENTA << name <<" has moved to:"
        << "( " << position.getPositionX() << " , " << position.getPositionY() << " )"
        << RESET << endl;
}

// Virtual functions
void Character::attack( Character& target ){
    cout << YELLOW << getName() 
        << " attacked " << target.getName()
        << "\n" << RESET;
}

void Character::displayStats(){
    cout<< "Stats of: " << WHITE << getName() << "\n" << RESET
        << GREEN << "\t - Health: " << health << " hp \n" << RESET
        << endl;
}

// Resources
// depletes mana
void Character::depleteMana( unsigned int points ){

    resource.depleteResource( resource.getMana() , points , resource.getIsManaDepleted() );

    cout << BLUE << getName() << " consumed "
        << points << " mana." << RESET
        << endl;
}
// depletes stamina
void Character::depleteStamina( unsigned int points ){

    resource.depleteResource( resource.getStamina() , points , resource.getIsStaminaDepleted() );

    cout << BLUE << getName() << " consumed "
        << points << " stamina points." << RESET
        << endl;
}
// depletes vigor
void Character::depleteVigor( unsigned int points ){

    resource.depleteResource( resource.getVigor() , points , resource.getIsVigorDepleted() );

    cout << BLUE << getName() << " consumed "
        << points << " vigor." << RESET
        << endl;
}

// gains mana
void Character::gainMana( unsigned int points ){

    resource.gainResource( resource.getMana() , points , resource.getIsManaDepleted() );

    cout << GREEN << getName() << " gained "
        << points << " mana!" << RESET
        << endl;
}
// gains stamina
void Character::gainStamina( unsigned int points ){
    resource.gainResource( resource.getStamina() , points , resource.getIsStaminaDepleted() );

    cout << GREEN << getName() << " gained "
        << points << " stamina!" << RESET
        << endl;
}
// gains vigor
void Character::gainVigor( unsigned int points ){
    resource.gainResource( resource.getVigor() , points , resource.getIsVigorDepleted() );

    cout << GREEN << getName() << " gained "
        << points << " vigor!" << RESET
        << endl;
}


// Actions
void Character::takeDamage(unsigned int damage) {
    // Decrease from already existing health
    if (damage >= health) {
        health = 0; 
    } else {
        health -= damage;
    }

    cout << CYAN << getName() << RESET
        << " takes " << RED << damage << " damage"
        << RESET << endl;

    displayStats();
}
