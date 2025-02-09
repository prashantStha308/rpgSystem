#include "positionManager.h"
#include "colors.h"
// namespaces
using namespace std;
using namespace color;

PositionManager::PositionManager( int x , int y ) : posX(x) , posY(y) {}

// Getters
int PositionManager::getPositionX() { return posX; }
int PositionManager::getPositionY() { return posY; } 
// Setters
void PositionManager::setPosition( int x , int y ) {
    posX = x;
    posY = y;
}
void PositionManager::setPositionX( int x ) { posX = x; };
void PositionManager::setPositionY( int y ) { posY = y; };
