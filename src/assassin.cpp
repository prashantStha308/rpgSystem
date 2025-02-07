#include "../includes/assassin.h"
#include "../includes/colors.h"

Assassin::Assassin( std::string name ) : Character( name , "Assassin" , 70 ) {} 

// Getters
unsigned int Assassin::getStamina() const {
    return stamina;
}

void Assassin::displayStats() {

    std::cout<< "Stats of: " << color::WHITE << getName() << color::RESET << "\n"
        << color::GREEN << "\t - Health: " << health << " hp \n" << color::RESET
        << color::CYAN << "\t - Stamina: " << stamina << "sta" << color::RESET 
    << std::endl;
}

// Setters
void Assassin::setStamina( unsigned int sta ){
    if( sta >= 0 ){
        stamina = sta;
    }
}

// Actions
void Assassin::attack( Character& target ) {

    std::cout << color::YELLOW << getName() 
        << " strikes "
        << target.getName()
    << " from the shadows!\n" << color::RESET;

    depleteStamina( 10 );
    target.takeDamage( 25 );
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

void Assassin::depleteStamina( unsigned int deplete ){
    depleteResource( stamina , deplete , depleted );

    std::cout << color::BLUE << getName() << " consumed "
        << deplete << " stamina points." << color::RESET
    << std::endl;
}

void Assassin::gainStamina( unsigned int gains ){
    stamina += gains;

    std::cout << color::GREEN << getName() << " gained "
        << gains << " stamina!" << color::RESET
    << std::endl;
}