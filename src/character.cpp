#include "../includes/character.h"
#include "../includes/colors.h"

// Getters
std::string Character::getName() const {
    return name;
}

std::string Character::getClass() const {
    return _class;
}

void Character::depleteResource ( unsigned int& resource , unsigned int deplete , bool& isDepleted ){
    if( isDepleted ) return;
    if( resource < deplete ){
        resource = 0;
        isDepleted = true;
    }else{
        resource -= deplete;
    }
}
// Display the stats of the character
void Character::displayStats(){
    std::cout<< "Stats of: " << getName() << "\n\n" <<
        color::GREEN << "\t - Health: " << health << " hp" << color::RESET
    << std::endl;
}

// The character takes damage
void Character::takeDamage( unsigned int damage ) {
    // decrease from already existing health
    health -= damage;
    if (health < 0) {
        health = 0;
    }
    std::cout<< color::CYAN << this->getName() << color::RESET << " takes " << color::RED << damage << " damage" << color::RESET << std::endl;
    this->displayStats();
}

void Character::setPosition( int x , int y  ){
    dx = x;
    dy = y;

    std::cout << color::MAGENTA << name <<" has moved to:"
        << "( " << dx << " , " << dy << " )"
    << color::RESET << std::endl;
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