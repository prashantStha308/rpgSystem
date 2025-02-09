#include<iostream>
#include<string>
// custom
#include "fighter.h"
#include "colors.h"

// namespaces
using namespace std;
using namespace color;

void Fighter::attack(Character& target) {

    cout << YELLOW << getName()
        << " swings a sword at " << target.getName()
    << "!\n" << RESET;

    depleteVigor( 10 );
    target.takeDamage( 28 );
}