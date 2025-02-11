#ifndef ASSASSIN_H
#define ASSASSIN_H

#include "character.h"
#include "assassinAttack.h"

class Assassin : public Character {
    private:
        AssassinAttack assassin_attack;
    public:
        Assassin(std::string name);

        // Getters
        bool& getStealth();

        // Setters
        void toggelStealth();
        void setStealth( bool );
        
        void displayStats() override;
        void attack(Character& target) override;


};

#endif
