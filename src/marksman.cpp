#include  "../includes/marksman.h"
#include "../includes/colors.h"

Marksman::Marksman( std::string name ) : Character( name , "Marksman" , 75 ) {}

void Marksman::displayStats() {

    std::cout<< "Stats of: " << color::WHITE << getName() << color::RESET << "\n"
        << color::GREEN << "\t - Health: " << health << " hp \n" << color::RESET
        << color::CYAN << "\t - Stamina: " << stamina << "sta \n" << color::RESET
        << color::CYAN << "\t - Vigor: " << vigor << "vig \n" << color::RESET
    << std::endl;
}

void Marksman::attack( Character& target ){
        std::cout << color::YELLOW << getName() 
        << " strikes "
        << target.getName()
    << " with a bow!\n" << color::RESET;

    depleteStamina( 10 );
    depleteVigor( 20 );
    target.takeDamage( 40 );
}
