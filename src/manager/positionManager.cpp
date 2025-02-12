#include "positionManager.h"
#include "colors.h"
#include<utility>
// namespaces
using namespace std;
using namespace color;

PositionManager::PositionManager( int x , int y ) : posX(x) , posY(y) {}

// Getters
int PositionManager::getPositionX() { return posX; }
int PositionManager::getPositionY() { return posY; }
Direction PositionManager::getFaceDirectionX() { return faceX; }
Direction PositionManager::getFaceDirectionY() { return faceY; }
pair< int , int > PositionManager::getPosition() { return { posX , posY }; }

// Setters
void PositionManager::setPosition( int x , int y ) {
    posX = x;
    posY = y;
}
void PositionManager::setPositionX( int x ) { posX = x; }
void PositionManager::setPositionY( int y ) { posY = y; }

// Actions
void PositionManager::moveFace( Direction vertical = STILL , Direction horizontal = STILL ){

    faceX = horizontal;
    faceY = vertical;
}