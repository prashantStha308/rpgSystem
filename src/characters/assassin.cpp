#include "../../includes/assassin.h"
#include "../../includes/colors.h"

Assassin::Assassin( std::string name ) : Character( name , "Assassin" , 70 ) {
    setStamina( 70 );
} 

void Assassin::displayStats() {

    std::cout<< "Stats of: " << color::WHITE << getName() << color::RESET << "\n"
        << color::GREEN << "\t - Health: " << health << " hp \n" << color::RESET
        << color::CYAN << "\t - Stamina: " << stamina << "sta" << color::RESET 
    << std::endl;
}
