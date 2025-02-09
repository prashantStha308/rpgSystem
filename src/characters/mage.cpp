#include "../../includes/mage.h"
#include "../../includes/colors.h"

Mage::Mage( std::string name ) : Character( name , "Mage" ,  80 ) {
    setMana( 300 );
} 

void Mage::attack(Character& target) {

    std::cout << color::YELLOW << name << " strkes "
        << target.getName() << "! with a lightning bolt\n"
    << color::RESET;

    depleteMana( 30 );
    target.takeDamage(30);
}

void Mage::displayStats() {
    std::cout<< "Stats of: " << color::WHITE << getName() << color::RESET << "\n"
        << color::GREEN << "\t - Health: " << health << " hp \n" << color::RESET
        << color::CYAN << "\t - Mana: " << getMana() << "mp"<< color::RESET
    << std::endl;
}
