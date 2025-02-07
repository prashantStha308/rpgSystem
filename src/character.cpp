#include "../includes/character.h"

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

void Character::displayStats(){
    std::cout<< "Stats of: " << getName() << "\n\n" <<
        "\t - Health: " << health << " hp" << "\n\n"
    << std::endl;
}

void Character::takeDamage(int damage) {
    // decrease from already existing health
    health -= damage;
    if (health < 0) {
        health = 0;
    }
    this->displayStats();
}

void Character::setPosition( int x , int y  ){
    dx = x;
    dy = y;

    std::cout << name <<" has moved to ( " << dx << " , " << dy << " )\n" << std::endl;
}

void Character::move( Direction horizontal , Direction vertical , int x , int y){

    if ( (vertical == UP && horizontal == DOWN) || (vertical == DOWN && horizontal == UP) ||
        (horizontal == LEFT && horizontal == RIGHT) ) {
        std::cout << "Invalid move! You can't move both vertically or horizontally in opposite directions.\n";
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