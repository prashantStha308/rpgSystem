#include "../includes/fighter.h"

Fighter::Fighter( std::string name ) : Character( name , "Fighter" , 100) {}  // Fighter starts with 100 HP

void Fighter::attack(Character& target) {
    std::cout << name << " swings a sword at " << target.getName() << "!\n";
    target.takeDamage( 28 );
}
