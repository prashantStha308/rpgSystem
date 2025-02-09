#include<iostream>
#include<string>
// custom
#include  "marksman.h"
#include "colors.h"
// namespaces
using namespace std;
using namespace color; //color::RED, MAGENTA , RESET.....

Marksman::Marksman( string name ) : Character( name , "Marksman" , 75 ) {
    resource.setVigor( 50 );
    resource.setStamina( 50 );
}

void Marksman::displayStats() {

    cout<< "Stats of: " << WHITE << getName() << RESET << "\n"
        << GREEN << "\t - Health: " << health << " hp \n" << RESET
        << CYAN << "\t - Stamina: " << resource.getStamina() << "sta \n" << RESET
        << CYAN << "\t - Vigor: " << resource.getVigor() << "vig \n" << RESET
        << endl;
}
