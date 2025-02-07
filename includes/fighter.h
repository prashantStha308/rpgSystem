#ifndef FIGHTER_H
#define FIGHTER_H

#include "character.h"

class Fighter : public Character {
public:
    Fighter( std::string name );
    void attack(Character& target) override;
};

#endif
