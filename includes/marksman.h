#ifndef MARKSMAN_H
#define MARKSMAN_H

#include "./character.h"

class Marksman : public Character {
    private:
        unsigned int vigor = 50;
        unsigned int stamina = 50;
    public:
        Marksman( std::string name );

        // Getters
        unsigned int getVigor() const;
        unsigned int getStamina() const;
        void displayStats() override;

        void attack() override;

        void depleteVigor();
        void depleteStamina();

        void gainVigor();
        void gainStamina();
}


#endif