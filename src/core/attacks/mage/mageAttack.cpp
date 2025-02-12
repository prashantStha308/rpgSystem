#include<iostream>
#include<utility>
#include<chrono>
#include<thread>
#include<cmath>
#include<tuple>

#include "mageAttack.h"
#include "character.h"
#include "positionManager.h"
#include "resourceManager.h"
#include "colors.h"

using namespace std;
using namespace color;

using list = pair<int , int>;

MageAttack::MageAttack( Character& newOwner ) : owner(newOwner) , position(0,0) {}

void MageAttack::execute( Character& target ){
    int baseDmg = 45;

    if( rand() * 100 < 30 ){
        baseDmg *= 2;
    }

    cout << YELLOW << owner.getName() << " used execute on "
        << target.getName() << "!\n"
        << RESET;

    owner.depleteMana( 30 );
    target.takeDamage( baseDmg );
}

// Render objects
pair< int , int > MageAttack::getFireballPosition(){
    list atk_position = owner.getPosition();
    Direction faceX = position.getFaceDirectionX();
    Direction faceY = position.getFaceDirectionY();

    int posX , posY;
    int STEP_COUNT = 5;
    
    if( faceX == RIGHT ){
        posX = atk_position.first + STEP_COUNT;
    } else if( faceX == LEFT ){
        posX = atk_position.first - STEP_COUNT;
    }

    if( faceY == UP ){
        posY = atk_position.second + STEP_COUNT;
    }else if( faceY == DOWN ){
        posY = atk_position.second - STEP_COUNT;
    }
    
    return { posX , posY };
}

tuple<int , int , int> MageAttack::getNormalizedDirection( list targetPosition , list fireballPosition ){
    int dx = targetPosition.first - fireballPosition.first;
    int dy = targetPosition.second - fireballPosition.second;
    int distance = sqrt( dx * dx + dy * dy );
    // if distance IS NOT 0
    if( distance != 0  ) return { ( dx/distance ) , ( dy/distance ) , distance };

    // if distance IS 0
    return { 0 , 0 , 0 };
}

// Mage Attacks
void MageAttack::fireBall( Character& target ) {
    cout << YELLOW << " Summoning a fireball.. " << RESET << endl;
    // Fireball properties
    int radius = 40;
    int speed = 10;
    int MAX_RANGE = 120;
    int baseDmg = 50;
    bool gotHit = false;
    // Positions
    list targetPosition = target.getPosition();
    list fireballPosition = getFireballPosition();

    int fireX = fireballPosition.first;
    int fireY = fireballPosition.second;
    // storing current positions to check range
    int startPositionX = fireX;
    int startPositionY = fireY;

    tuple<int, int, int> normalizedDir = getNormalizedDirection(targetPosition, fireballPosition);
    int dx_normalized = get<0>(normalizedDir);
    int dy_normalized = get<1>(normalizedDir);
    int distance = get<2>(normalizedDir);

    while (distance > 0 && abs(fireX - startPositionX) <= MAX_RANGE && abs(fireY - startPositionY) <= MAX_RANGE) {
        fireX += dx_normalized * speed;
        fireY += dy_normalized * speed;

        // Update fireball position for distance calculation
        fireballPosition = {fireX, fireY};
        normalizedDir = getNormalizedDirection(targetPosition, fireballPosition);
        distance = get<2>(normalizedDir);

        if (distance <= radius) {
            // Apply damage based on distance
            if (distance <= 20) {
                baseDmg = 50; // Max damage at the center
            } else if (distance <= 32) {
                baseDmg = 45; // Reduced damage
            } else if (distance <= 40) {
                baseDmg = 30; // Minimum damage at the edge of the fireball
            }

            target.takeDamage(baseDmg);
            gotHit = true;
            break; // Stop the fireball after it hits the target
        }

        this_thread::sleep_for(chrono::microseconds(50));
    }

    if (gotHit) {
        cout << YELLOW << "Fireball hits " << target.getName() << RESET << endl;
    } else {
        cout << MEDIUM_RED << "Fireball missed " << RESET << endl;
    }
}
