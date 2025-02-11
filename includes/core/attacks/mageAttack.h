#ifndef MAGEATTACK_H
#define MAGEATTACK_H

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

        // Attack essentials
        unsigned int baseDmg = 0;
    public:
        MageAttack( Character& );

        void execute( Character& ) override;

        // Mage Attacks
        void fireBall();
        void thunderBelt();
        void phenoxForce();

};

#endif