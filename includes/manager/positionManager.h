#ifndef POSITIONMANAGER_H
#define POSITIONMANAGER_H

#include<utility>

enum Direction {
    LEFT,
    RIGHT,
    UP,
    DOWN,
    STILL
};

class PositionManager{
    protected:
        int posX;
        int posY;
        
        Direction faceX = RIGHT;
        Direction faceY = STILL;

    public:
    PositionManager( int , int );

    // Getters
    int getPositionX();
    int getPositionY();
    Direction getFaceDirectionX();
    Direction getFaceDirectionY();
    /**
     * @brief Returns a pair of int Usages:
     * ```
     * pair<int , int> pos = position.getPosition();
     * OR
     * auto pos = position.getPosition();
     * ```
     */
    std::pair< int , int > getPosition();

    // Setters
    void setPosition( int x , int y );
    void setPositionX( int x );
    void setPositionY( int y );

    // Actions
    void moveFace( Direction , Direction );

};

#endif