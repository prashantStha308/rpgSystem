#ifndef MAGE_H
#define MAGE_H

#include "character.h"

class Mage : public Character {
    private:
    
    public:
        Mage( std::string name );

        void displayStats() override ;
        void attack(Character& target) override;
};

#endif
