#ifndef MAGE_H
#define MAGE_H

#include "character.h"

class Mage : public Character {
    private:
        unsigned int mana = 100;
        bool depleated = false;
    public:
        Mage(std::string name);
        // getters
        /**
         * @brief `Returns the amount of mana remaining`
         * @returns unsigned int mana;
         */
        unsigned int getMana() const;
        void displayStats() override ;

        void attack(Character& target) override;

        void depleteMana( unsigned int );
        void gainMana( unsigned int );
};

#endif
