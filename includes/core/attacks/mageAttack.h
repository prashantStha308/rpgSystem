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
        // Fireball Helpers
        std::pair< int , int > getFireballPosition();
        std::tuple<int,int,int > getNormalizedDirection( std::pair<int, int> , std::pair<int, int> );

        // Mage Attacks
        void fireBall( Character& );
        void thunderBelt( Character& );
        void phenoxForce();

};

#endif