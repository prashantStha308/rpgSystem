#include "../includes/assassin.h"
#include "../includes/colors.h"

Assassin::Assassin( std::string name ) : Character( name , "Assassin" , 70 ) {
    setStamina( 70 );
} 

void Assassin::displayStats() {

    std::cout<< "Stats of: " << color::WHITE << getName() << color::RESET << "\n"
        << color::GREEN << "\t - Health: " << health << " hp \n" << color::RESET
        << color::CYAN << "\t - Stamina: " << stamina << "sta" << color::RESET 
    << std::endl;
}

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
