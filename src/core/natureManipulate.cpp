#include "../../includes/character.h"
#include "../../includes/colors.h"

// nature points manipulators
void Character::depleteResource ( unsigned int& resource , unsigned int points , bool& isDepleted ){
    if( isDepleted || points <= 0 ) return;
    
    if( points <= resource ){
        resource -= points;
    }else{ // if resource is less than the passed points
        isDepleted = true; //since points is greater than resource, the resource is now depleted;
        resource = 0; //set the resource to have 0 points
    }
}

void Character::gainResource( unsigned int& resource , unsigned int points , bool& isDepleted ) {
    if( points <= 0 ) return;

    resource += points;
    isDepleted = false; // resource is no longer depleted as some points is added
}

// depletes mana
void Character::depleteMana( unsigned int points ){
    depleteResource( mana , points , isManaDepleted );

    std::cout << color::BLUE << getName() << " consumed "
        << points << " mana." << color::RESET
    << std::endl;

}
// depletes stamina
void Character::depleteStamina( unsigned int points ){
    depleteResource( stamina , points , isStaminaDepleted );

    std::cout << color::BLUE << getName() << " consumed "
        << points << " stamina points." << color::RESET
        << std::endl;
}
// depletes vigor
void Character::depleteVigor( unsigned int points ){
    depleteResource( vigor , points , isVigorDepleted );

    std::cout << color::BLUE << getName() << " consumed "
        << points << " vigor." << color::RESET
        << std::endl;
}

// gains mana
void Character::gainMana( unsigned int points ){
    gainResource( mana , points , isManaDepleted );

    std::cout << color::GREEN << getName() << " gained "
        << points << " mana!" << color::RESET
        << std::endl;
}
// gains stamina
void Character::gainStamina( unsigned int points ){
    gainResource( stamina , points , isStaminaDepleted );

    std::cout << color::GREEN << getName() << " gained "
        << points << " stamina!" << color::RESET
        << std::endl;
}
// gains vigor
void Character::gainVigor( unsigned int points ){
    gainResource( vigor , points , isVigorDepleted );

    std::cout << color::GREEN << getName() << " gained "
        << points << " vigor!" << color::RESET
        << std::endl;
}