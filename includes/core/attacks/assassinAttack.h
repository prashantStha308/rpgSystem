#ifndef ASSASSINATTACK_H
#define ASSASSINATTACK_H

#include "attack.h"
#include "character.h"

class AssassinAttack : public Attack {
    protected:

        unsigned int baseDmg;
        bool stealth = false;

    public:
        void execute( Character& , Character& ) override;

        // Stealth
        void setStealth(bool);
        bool& getStealth();
        void toggleStealth();

        // Skills
        void shadowStep(); //teleport to a direction
        void showerDagger(); //throws multiple daggers at a direction. in an arc khalko
        

};

#endif