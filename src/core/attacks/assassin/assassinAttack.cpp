#include<iostream>
#include "assassinAttack.h"
#include "character.h"
#include "colors.h"

// Constructor
AssassinAttack::AssassinAttack( Character& newOwner ) : owner( newOwner ) , position( 0 , 0  ) {}

// Base execute attack function
void AssassinAttack::execute( Character& target ) {
    baseDmg = 30;

    if( rand() * 100 < 30 ){
        baseDmg *= 2;
    }
    owner.depleteStamina( 10 );
    target.takeDamage( baseDmg );
    if( stealth ) toggleStealth();
}
// Stealth
void AssassinAttack::setStealth( bool state ) { stealth = state; }
bool& AssassinAttack::getStealth() { return stealth; }
void AssassinAttack::toggleStealth() { stealth = !stealth; }

// Skills
void AssassinAttack::shadowStep(){
    // Get current face direction
    Direction faceX = position.getFaceDirectionX();
    Direction faceY = position.getFaceDirectionY();
    // Get the current position in plane
    int posX = position.getPositionX();
    int posY = position.getPositionY();

    unsigned int STEP_COUNT = 10;

    // set position accordingly
    if( faceX == LEFT ){
        posX -= STEP_COUNT;
    }else if( faceX == RIGHT ){
        posX += STEP_COUNT;
    }

    if( faceY == UP ){
        posY += STEP_COUNT;
    }else if( faceY == DOWN ){
        posY -= STEP_COUNT;
    }
    owner.depleteStamina( 25 ); //deduct 25 points on use
    position.setPosition( posX , posY );
}