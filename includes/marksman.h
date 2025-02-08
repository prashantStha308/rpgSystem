#ifndef MARKSMAN_H
#define MARKSMAN_H

#include "./character.h"

class Marksman : public Character {
    private:
        unsigned int vigor = 50;
        unsigned int stamina = 50;
    public:
        Marksman( std::string name );

        void displayStats() override;
        void attack( Character& ) override;

};


#endif