#include "marksman.h"
#include "colors.h"

void Marksman::attack( Character& target ){
        std::cout << color::YELLOW << getName() 
        << " strikes "
        << target.getName()
    << " with a bow!\n" << color::RESET;

    depleteStamina( 10 );
    depleteVigor( 20 );
    target.takeDamage( 40 );
}