#include "../includes/mage.h"
#include "../includes/colors.h"

Mage::Mage( std::string name ) : Character( name , "Mage" ,  80 ) {} 

void Mage::attack(Character& target) {

    std::cout << color::YELLOW << name << " strkes "
        << target.getName() << "! with a lightning bolt\n"
    << color::RESET;

    depleteMana( 30 );
    target.takeDamage(30);
}

unsigned int Mage::getMana() const {
    return mana;
}

void Mage::displayStats() {
    std::cout<< "Stats of: " << color::WHITE << getName() << color::RESET << "\n"
        << color::GREEN << "\t - Health: " << health << " hp \n" << color::RESET
        << color::CYAN << "\t - Mana: " << mana << "mp"<< color::RESET
    << std::endl;
}

void Mage::depleteMana ( unsigned int deplete ){
    depleteResource( mana , deplete , depleated );
    std::cout << color::BLUE << getName() << " consumed " << deplete << " mana." << color::RESET << std::endl;
}

void Mage::gainMana( unsigned int gains ){
    mana += gains;
    std::cout << color::GREEN << getName() << " gained " << gains << " mana!" << color::RESET << std::endl;
}