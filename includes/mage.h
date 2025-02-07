#ifndef MAGE_H
#define MAGE_H

#include "character.h"

class Mage : public Character {
    private:
        unsigned int mana = 100;
        bool depleated = false;
    public:
        Mage( std::string name );
        // getters
        /**
         * @brief `Returns the amount of mana remaining`
         * @returns unsigned int mana;
         */
        unsigned int getMana() const;
        void displayStats() override ;

        // Actions
        void attack(Character& target) override;

        /**
         * @param unsigned int x
         * @brief Depleats x amount of mana from the existing mana
         */
        void depleteMana( unsigned int );

        /**
         * @param unsigned int x
         * @brief ` Adds x amount of mana to existing mana `
         */
        void gainMana( unsigned int );
};

#endif
