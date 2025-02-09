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
    if( !stealth ) toggelStealth();

    cout << YELLOW << getName() 
        << " strikes " << target.getName()
        << " from the shadows!\n" << RESET;
    
    depleteStamina( 10 );
    target.takeDamage( 25 );
    if( stealth ) toggelStealth();
}

// Skill actions
void Assassin::toggelStealth(){

    if( !stealth ){
        cout << BLUE << getName()
            << " is activating stealth" << RESET
            << endl;

        depleteStamina(5);
    }
    stealth = !stealth;
}