#include "../includes/fighter.h"
#include "../includes/colors.h"

Fighter::Fighter( std::string name ) : Character( name , "Fighter" , 100) {}

unsigned int Fighter::getVigor() const{
    return vigor;
}

void Fighter::attack(Character& target) {
    std::cout << color::YELLOW << getName() << " swings a sword at " << target.getName() << "!\n" << color::RESET;
    target.takeDamage( 28 );
}

void Fighter::displayStats() {
    std::cout<< "Stats of: " << color::WHITE << getName() << "\n" << color::RESET
        << color::GREEN << "\t - Health: " << health << " hp \n" << color::RESET
        << color::CYAN << "\t - Vigor: " << vigor << "vig"<< color::RESET
    << std::endl;
}

void Fighter::depleteVigor( unsigned int deplete){
    depleteResource( vigor , deplete , depleted );
    std::cout << color::BLUE << getName() << " consumed " << deplete << " vigor." << color::RESET << std::endl;
}

void Fighter::gainVigor( unsigned int gains ){
    vigor += gains;
    std::cout << color::GREEN << getName() << " gained " << gains << " vigor!" << color::RESET << std::endl;
}