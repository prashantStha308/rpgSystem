#ifndef FIGHTER_H
#define FIGHTER_H

#include "character.h"

class Fighter : public Character {
    private:
        unsigned int vigor = 100;
        bool depleted = false;
    public:
        Fighter( std::string name );

        // Getters:
        /**
         * @returns Remaining vigor of the character 
         * @returns an **unsigned int**
         */
        unsigned int getVigor () const;
        /**
         * @brief Displays the stats of a character
         */
        void displayStats() override;

        /**
         * @brief `Displays the status of a character`
         * @brief Example:
         * ```
         * Fighter fighter("Conan");
         * fighter->displayStats();
         * ```
         */
        void attack(Character& target) override;

        /**
         * @param unsigned int x
         * @brief Depelets existing vigor by x amount
         */
        void depleteVigor( unsigned int );
        /**
         * @param unsigned int x
         * @brief Adds x amount to vigor to existing vigor
         */
        void gainVigor( unsigned int );
};

#endif
