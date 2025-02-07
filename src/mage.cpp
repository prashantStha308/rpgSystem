#include "../includes/mage.h"

Mage::Mage( std::string name ) : Character( name , "Mage" ,  80 ) {}  // Mage starts with 80 HP

void Mage::attack(Character& target) {
    std::cout << name << " casts a fireball at " << target.getName() << "!\n";
    target.takeDamage(30);
}

unsigned int Mage::getMana() const {
    return mana;
}

void Mage::displayStats() {
    std::cout<< "Stats of: " << getName() << "\n\n" <<
        "\t - Health: " << health << " hp \n" <<
        "\t - Mana: " << mana << "mp \n"<<
        "\n"
    << std::endl;
}

void Mage::depleteMana ( unsigned int depleat ){
    depleteResource( mana , depleat , depleated );
}

void Mage::gainMana( unsigned int gain ){
    mana += gain;
}