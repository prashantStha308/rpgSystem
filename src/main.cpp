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

#include "../includes/mage.h"
#include "../includes/fighter.h"
#include "../includes/assassin.h"
#include <vector>
#include "../includes/colors.h"

int main() {
    Mage mage("Gandalf");
    Fighter fighter("Conan");
    Assassin assassin("Ezio");

    std::vector<Character*> characters = {&mage, &fighter, &assassin};
    characters[0]->setPosition( 12 , 98 );
    characters[1]->setPosition( 20 , 85 );
    characters[2]->setPosition( 17 , 92 );

    std::cout << color::RED << "Bringing forth the War!! "<< color::RESET << "\n\n";

    for (auto* attacker : characters) {
        if( Assassin* targetAssassin = dynamic_cast<Assassin*>(attacker) ){
            targetAssassin->toggelStealth();
        }
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
