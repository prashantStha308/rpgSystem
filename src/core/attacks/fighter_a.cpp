#include "fighter.h"
#include "colors.h"

void Fighter::attack(Character& target) {

    std::cout << color::YELLOW << getName()
        << " swings a sword at " << target.getName()
    << "!\n" << color::RESET;

    depleteVigor( 10 );
    target.takeDamage( 28 );
}