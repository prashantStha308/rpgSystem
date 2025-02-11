#include<iostream>
#include<string>

#include "mage.h"
#include "colors.h"
// namespaces
using namespace std;
using namespace color;

void Mage::attack(Character& target) {
    mage_attack.execute( target );
}