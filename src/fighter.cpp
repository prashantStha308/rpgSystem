#include "../includes/fighter.h"
#include "../includes/colors.h"

Fighter::Fighter( std::string name ) : Character( name , "Fighter" , 100) {
    setVigor( 100 );
}

void Fighter::attack(Character& target) {

    std::cout << color::YELLOW << getName()
        << " swings a sword at " << target.getName()
    << "!\n" << color::RESET;

    depleteVigor( 10 );
    target.takeDamage( 28 );
}

void Fighter::displayStats() {
    std::cout<< "Stats of: " << color::WHITE << getName() << "\n" << color::RESET
        << color::GREEN << "\t - Health: " << health << " hp \n" << color::RESET
        << color::CYAN << "\t - Vigor: " << vigor << "vig"<< color::RESET
    << std::endl;
}