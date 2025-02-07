#ifndef ASSASSIN_H
#define ASSASSIN_H

#include "character.h"

class Assassin : public Character {
    private:
        bool stealth = false;
        bool depleted = false;
        unsigned int stamina = 100;
    public:
        Assassin(std::string name);
        
        // Getters:
        unsigned int getStamina() const;
        /**
         * @brief `Displays the status of a character`
         * @brief Example:
         * ```
         * Mage mage('Gandalf);
         * mage->displayStats();
         * ```
         */
        void displayStats() override;

        // Setters

        void setStamina( unsigned int );

        // Actions
        /**
         * @brief Attacks a character
         * @param Character target
         */
        void attack(Character& target) override;
        /**
         * @brief toggels the value of stealth.
         * @brief stealth is a bool value 
         * @note activating stealth costs 5 stamina
         */
        void toggelStealth();

        /**
         * @param unsigned int x
         * @brief Depelets existing stamina by x amount
         */
        void depleteStamina( unsigned int );
        /**
         * @param unsigned int x
         * @brief Adds x amount to stamina to existing stamina
         */
        void gainStamina( unsigned int );
};

#endif
