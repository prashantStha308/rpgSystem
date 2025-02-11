#include<iostream>
#include<string>
// custom
#include "mage.h"
#include "colors.h"
// namespaces
using namespace std;
using namespace color;

Mage::Mage( string name ) : Character( name , "Mage" ,  80 ) , mage_attack(*this) {
    resource.setMana( 300 );
} 

void Mage::displayStats() {
    cout<< "Stats of: " << WHITE << getName() << RESET << "\n"
        << GREEN << "\t - Health: " << health << " hp \n" << RESET
        << CYAN << "\t - Mana: " << resource.getMana() << "mp"<< RESET
        << endl;
}
