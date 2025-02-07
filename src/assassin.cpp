#include "../includes/assassin.h"

Assassin::Assassin( std::string name ) : Character( name , "Assassin" , 70 ) {}  // Assassin starts with 70 HP

unsigned int Assassin::getStamina() const {
    return stamina;
}

void Assassin::displayStats() {
        std::cout<< "Stats of: " << getName() << "\n\n" <<
        "\t - Health: " << health << " hp \n" <<
        "\t - Stamina: " << stamina << "mp \n"<<
        "\n"
    << std::endl;
}

void Assassin::attack( Character& target ) {
    std::cout << getName() << " stealthily strikes " << target.getName() << " from the shadows!\n";
    target.takeDamage( 25 ); // Stealth attack deals 25 damage
}

void Assassin::toggelStealth(){
    stealth = !stealth;

        std::cout<< getName() << " has activated stealth\n" << std::endl;
}

void Assassin::depleteStamina( unsigned int depleat ){
    depleteResource( stamina , depleat , depleted );
}