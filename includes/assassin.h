#ifndef ASSASSIN_H
#define ASSASSIN_H

#include "character.h"

class Assassin : public Character {
    private:
        bool stealth = false;
    public:
        Assassin(std::string name);
        
        void displayStats() override;
        void attack(Character& target) override;
        /**
         * @brief toggels the value of stealth.
         * @note activating stealth costs 5 stamina
         */
        void toggelStealth();

};

#endif
