#ifndef ASSASSINATTACK_H
#define ASSASSINATTACK_H

#include "attack.h"
#include "character.h"
#include "positionManager.h"
#include "resourceManager.h"

class AssassinAttack : public Attack {
    protected:
        // Class's instances
        Character& owner;
        // Position
        PositionManager position;
        // Resources
        ResourceManager resource;
        // Attack essentials
        unsigned int baseDmg;
        bool stealth = false;
    public:
        AssassinAttack( Character& );
        /**
         * @brief
         * execute( Character& target )
         */
        void execute( Character& ) override;

        // Stealth
        void setStealth(bool);
        bool& getStealth();
        void toggleStealth();

        // Skills
        void shadowStep(); //teleport to a direction
        void showerDagger(); //throws multiple daggers at a direction. in an arc khalko
        

};

#endif