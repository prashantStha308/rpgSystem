#include<iostream>

#include "mageAttack.h"
#include "character.h"
#include "positionManager.h"
#include "resourceManager.h"
#include "colors.h"

using namespace std;
using namespace color;

MageAttack::MageAttack( Character& newOwner ) : owner(newOwner) , position(0,0) {}

void MageAttack::execute( Character& target ){
    baseDmg = 45;

    if( rand() * 100 < 30 ){
        baseDmg *= 2;
    }

    cout << YELLOW << owner.getName() << " used execute on "
        << target.getName() << "!\n"
        << RESET;

    owner.depleteMana( 30 );
    target.takeDamage( baseDmg );
}