#include<iostream>
#include<string>
// custom
#include "fighter.h"
#include "colors.h"

// namespaces
using namespace std;
using namespace color;

Fighter::Fighter( string name ) : Character( name , "Fighter" , 100) {
    resource.setVigor( 100 );
}

void Fighter::displayStats() {
    cout<< "Stats of: " << WHITE << getName() << "\n" << RESET
        << GREEN << "\t - Health: " << health << " hp \n" << RESET
        << CYAN << "\t - Vigor: " << resource.getVigor() << "vig"<< RESET
        << endl;
}