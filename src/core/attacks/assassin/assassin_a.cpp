#include<iostream>
#include<string>
// custom
#include "assassin.h"
#include "colors.h"
// namespaces
using namespace std;
using namespace color;

// Actions
void Assassin::attack( Character& target ) {
    if( !assassin_attack.getStealth() ) toggelStealth();

    cout << YELLOW << getName() 
        << " strikes " << target.getName()
        << " from the shadows!\n" << RESET;

    assassin_attack.execute( target );
}

// Skill actions
void Assassin::toggelStealth(){

    if( !assassin_attack.getStealth() ){
        cout << BLUE << getName()
            << " is activating stealth" << RESET
            << endl;

        depleteStamina(5);
    }
    assassin_attack.toggleStealth();
}