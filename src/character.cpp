#include "../includes/character.h"
#include "../includes/colors.h"

Character::Character(std::string name = "unnamed nomad" , std::string _class = "peasent" , unsigned int hp = 100) : name(name), _class(_class) , health(hp) {}

// Getters
std::string Character::getName() const { 
    return name;
}

std::string Character::getClass() const {
    return _class;
}

unsigned int Character::getMana() const {
    return mana;
}

unsigned int Character::getStamina() const {
    return stamina;
}

unsigned int Character::getVigor() const {
    return vigor;
}

// Setters
void Character::setPosition( int x , int y  ){
    dx = x;
    dy = y;

    std::cout << color::MAGENTA << name <<" has moved to:"
        << "( " << dx << " , " << dy << " )"
    << color::RESET << std::endl;
}

void Character::setMana( unsigned int points ){
    mana = points;
}

void Character::setStamina( unsigned int points ){
    stamina = points;
}

void Character::setVigor( unsigned int points ){
    vigor = points;
}


// Actions
void Character::takeDamage(unsigned int damage) {
    // Decrease from already existing health
    if (damage >= health) {
        health = 0; 
    } else {
        health -= damage;
    }

    std::cout << color::CYAN << getName() << color::RESET
        << " takes " << color::RED << damage << " damage"
        << color::RESET << std::endl;

    displayStats();
}
void Character::move( Direction horizontal , Direction vertical , int x , int y){

    if ( (vertical == UP && horizontal == DOWN) || (vertical == DOWN && horizontal == UP) ||
        (horizontal == LEFT && horizontal == RIGHT) ) {
        std::cout << color::DEEP_RED << "Invalid move! You can't move both vertically or horizontally in opposite directions.\n" << color::RESET;
        return;
    }

    if( vertical == UP ){
        dy -= y;
    }else{
        dy += y;
    }

    if( horizontal == LEFT ){
        dx -= x;
    }else{
        dx += x;
    }
    setPosition( dx , dy );
}