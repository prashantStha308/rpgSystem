#include "positionManager.h"
#include "colors.h"
// namespaces
using namespace std;
using namespace color;

PositionManager::PositionManager( int x , int y ) : posX(x) , posY(y) {}

// Getters
int PositionManager::getPositionX() { return posX; }
int PositionManager::getPositionY() { return posY; }
Direction PositionManager::getFaceDirectionX() { return faceX; }
Direction PositionManager::getFaceDirectionY() { return faceY; }

// Setters
void PositionManager::setPosition( int x , int y ) {
    posX = x;
    posY = y;
}
void PositionManager::setPositionX( int x ) { posX = x; };
void PositionManager::setPositionY( int y ) { posY = y; };

// Actions
void PositionManager::move( Direction vertical = STILL , Direction horizontal = STILL ){

    if( vertical == UP ){
        faceY = UP;
    }else if( vertical == DOWN ){
        faceY = DOWN;
    }else{
        faceY = STILL;
    }

    if( horizontal == LEFT ){
        faceX = LEFT;
    }else if( horizontal == RIGHT ){
        faceX = RIGHT;
    }else{
        faceX = STILL;
    }

}