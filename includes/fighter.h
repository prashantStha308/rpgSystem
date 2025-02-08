#ifndef FIGHTER_H
#define FIGHTER_H

#include "character.h"

class Fighter : public Character {
    private:

    public:
        Fighter( std::string name );
        
        void displayStats() override;
        void attack(Character& target) override;;
};

#endif
