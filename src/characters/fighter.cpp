#include "../../includes/fighter.h"
#include "../../includes/colors.h"

Fighter::Fighter( std::string name ) : Character( name , "Fighter" , 100) {
    setVigor( 100 );
}

void Fighter::displayStats() {
    std::cout<< "Stats of: " << color::WHITE << getName() << "\n" << color::RESET
        << color::GREEN << "\t - Health: " << health << " hp \n" << color::RESET
        << color::CYAN << "\t - Vigor: " << vigor << "vig"<< color::RESET
    << std::endl;
}