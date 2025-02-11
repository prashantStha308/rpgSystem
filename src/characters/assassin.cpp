#include<iostream>
#include<string>

#include "assassin.h"
#include "colors.h"
// namespaces
using namespace std;
using namespace color;

Assassin::Assassin(string name) 
    : Character(name, "Assassin", 70), assassin_attack(*this) {
    resource.setStamina(70);
}

// Getters
bool& Assassin::getStealth() { return assassin_attack.getStealth(); }

// Setters
void Assassin::setStealth( bool state ){ assassin_attack.setStealth( state ); }


void Assassin::displayStats() {

    cout<< "Stats of: " << WHITE << getName() << RESET << "\n"
        << GREEN << "\t - Health: " << health << " hp \n" << RESET
        << CYAN << "\t - Stamina: " << resource.getStamina() << "sta" << RESET 
        << endl;
}
