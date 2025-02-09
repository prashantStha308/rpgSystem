#include "assassin.h"
#include "colors.h"

// Actions
void Assassin::attack( Character& target ) {
    if( !stealth ) toggelStealth();

    std::cout << color::YELLOW << getName() 
        << " strikes "
        << target.getName()
    << " from the shadows!\n" << color::RESET;
    
    depleteStamina( 10 );
    target.takeDamage( 25 );
    if( stealth ) toggelStealth();
}

// Skill actions
void Assassin::toggelStealth(){

    if( !stealth ){
        std::cout << color::BLUE << getName()
            << " is activating stealth" << color::RESET
        << std::endl;

        depleteStamina(5);
    }
    stealth = !stealth;
}