#include "resourceManager.h"

// Core Functions
void ResourceManager::depleteResource ( unsigned int& resource , unsigned int points , bool& isDepleted ){
    if( isDepleted || points <= 0 ) return;
    
    if( points <= resource ){
        resource -= points;
    }else{ // if resource is less than the passed points
        isDepleted = true; //since points is greater than resource, the resource is now depleted;
        resource = 0; //set the resource to have 0 points
    }
}

void ResourceManager::gainResource( unsigned int& resource , unsigned int points , bool& isDepleted ) {
    if( points <= 0 ) return;

    resource += points;
    isDepleted = false; // resource is no longer depleted as some points is added
}

// Accessors
// Getters
unsigned int& ResourceManager::getStamina() { return stamina; }
unsigned int& ResourceManager::getVigor() { return vigor; }
unsigned int& ResourceManager::getMana() { return mana; }
// Flag Getters
bool& ResourceManager::getIsStaminaDepleted() { return isStaminaDepleted; }
bool& ResourceManager::getIsVigorDepleted() { return isVigorDepleted; }
bool& ResourceManager::getIsManaDepleted() { return isManaDepleted; }

// Setters
void ResourceManager::setStamina(unsigned int amount) {
    stamina = amount;
    isStaminaDepleted = stamina > 0 && false;
}
void ResourceManager::setVigor(unsigned int amount) {
    vigor = amount;
    isVigorDepleted = vigor > 0 && false;
}
void ResourceManager::setMana(unsigned int amount) {
    mana = amount;
    isManaDepleted = mana > 0 && false;
}
// Flag Setters
void ResourceManager::setIsStaminaDepleted( bool flag ) { isStaminaDepleted = flag; }
void ResourceManager::setIsManaDepleted( bool flag ) { isManaDepleted = flag; }
void ResourceManager::setIsVigorDepleted( bool flag ) { isVigorDepleted = flag; }