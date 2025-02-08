/*
RPG charcter system

Player will make a character, of type ---> Mage , Fighter , Assassin, Marksman , Healer

Character will be the parent to all these.
Assissin will have some property of both mage and fighter, as well as it's own unique sets of charcters.
Healer will have some property of Mage. As healing is done thruogh magic.

Well actually, magic is an integral part of everyone, all classes. Hence magic is child of the Character class
and everything else is magic's children?



Class Levels:

Character---> [ Mage , Assassin , Fighter , Marksman ]

// Tala ko chai banauna baki xa
<<<<<<<<<<< Power Nature Mechanics >>>>>>>>>>>

Magic ---> [ ...character ]

Stamina ---> [ Assassin , Marksman ]

Vigor ---> [ Fighter , Marksman ]

*/

// C++ headers
#include <vector>

// character classes
#include "../includes/mage.h"
#include "../includes/fighter.h"
#include "../includes/assassin.h"
#include "../includes/marksman.h"
#include "../includes/colors.h"

int main() {
    Mage mage("Gandalf");
    Fighter fighter("Conan");
    Assassin assassin("Ezio");
    Marksman marksman("Legolas");

    std::vector<Character*> characters = { &mage, &fighter, &assassin , &marksman };
    characters[0]->setPosition( 12 , 98 );
    characters[1]->setPosition( 20 , 85 );
    characters[2]->setPosition( 17 , 92 );
    characters[3]->setPosition( 22 , 83 );

    int i = 1;

    std::cout << color::RED << "Bringing forth the War!! "<< color::RESET << "\n\n";

    for (auto* attacker : characters) {
        std::cout << color::MEDIUM_RED << " \tMatch - " << i++ << "!!" << color::RESET << std::endl;
        for (auto* target : characters) {
            if (attacker != target) {
                attacker->attack(*target);
                attacker->move( UP , LEFT , 10 , 5 );
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
