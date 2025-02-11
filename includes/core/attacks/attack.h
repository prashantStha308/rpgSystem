#ifndef ATTACK_H
#define ATTACK_H

#include "character.h"

class Attack{
    public:
    virtual void execute( Character& ) = 0;
    ~Attack() {}
};

#endif