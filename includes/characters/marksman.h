#ifndef MARKSMAN_H
#define MARKSMAN_H

#include "./character.h"

class Marksman : public Character {
    private:
    public:
        Marksman( std::string name );

        void displayStats() override;
        void attack( Character& ) override;

};


#endif