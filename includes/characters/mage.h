#ifndef MAGE_H
#define MAGE_H

#include "character.h"
#include "mageAttack.h"

class Mage : public Character {
    private:
        MageAttack mage_attack;
    public:
        Mage( std::string name );

        void displayStats() override ;
        void attack(Character& target) override;
};

#endif
