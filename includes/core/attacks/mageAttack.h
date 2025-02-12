#ifndef MAGEATTACK_H
#define MAGEATTACK_H

#include<utility>
#include<tuple>

#include "attack.h"
#include "character.h"
#include "positionManager.h"
#include "resourceManager.h"


class MageAttack : public Attack {
    protected:
        // Class's instances
        Character& owner;
        // Position
        PositionManager position;
        // Resources
        ResourceManager resource;

    public:
        MageAttack( Character& );

        void execute( Character& ) override;

        /*
        Fireball should give damage of 45hp, at an area of radius 15
        Fireball itself should have a radius of 40.
        0 - 20 : 45
        21 - 32 : 30
        33 - 40 : 20
        Inputs: target's current position. 
        and : current location of fireball = position of mage, considering it's faceDirection add/subtract an offset of 5
        Steps:
        1. Calculate direction vector: 
            dx = targetPositionX - firePositionX;
            dy = targetPositionY - firePositionY;
        2. Find Distance: 
            distance = sqrt( x^2 + y^2 ) //euclidian formula for finding distance in 2D plane
            dx_normalized = dx/distance
            dy_normalized = dy/distance
        3. Move towards the target
            new_x = x1(prev_x) + ( dx_normalized * speed );
            x1 = new_x;
            new_y = y1(prev_y) + ( dy_normalized * speed );
            y1 = new_y;
        4. Stop moving and destroy fireball if( distance <= speed )
        */
        // Fireball Helpers
        // Returns the position of fireball after accounting for offset from owner's position
        std::pair< int , int > getFireballPosition();
        // Generate normalized x and y for fireball
        std::tuple<int,int,int > getNormalizedDirection( std::pair<int, int> , std::pair<int, int> );

        // Mage Attacks
        void fireBall( Character& );
        void thunderBelt();
        void phenoxForce();

};

#endif