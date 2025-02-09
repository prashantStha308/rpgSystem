#include<iostream>
#include "assassinAttack.h"
#include "character.h"

// Base execute attack function
void AssassinAttack::execute( Character& attacker , Character& target ) {
    baseDmg = 30;

    if( rand() * 100 < 30 ){
        baseDmg *= 2;
    }
    target.takeDamage(baseDmg);
}
// Stealth
void AssassinAttack::setStealth( bool state ) { stealth = state; }
bool& AssassinAttack::getStealth() { return stealth; }
void AssassinAttack::toggleStealth() { stealth = !stealth; }