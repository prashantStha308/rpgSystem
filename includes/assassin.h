#ifndef ASSASSIN_H
#define ASSASSIN_H

#include "character.h"

class Assassin : public Character {
    private:
        bool stealth;
        bool depleted;
        unsigned int stamina;
    public:
        Assassin(std::string name);
        
        // Getters:
        unsigned int getStamina() const;
        void displayStats() override;

        void attack(Character& target) override;
        void toggelStealth();

        void depleteStamina( unsigned int );
        void gainStamina( unsigned int );
};

#endif
