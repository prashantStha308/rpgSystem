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
    // Returns Position on X axis
    int getPositionX();
    // Returns Position on Y axis
    int getPositionY();
    // Returns face direction on X axis.
    Direction getFaceDirectionX();
    // Returns face direction on Y axis.
    Direction getFaceDirectionY();
    // returns position as pair of int.
    std::pair< int , int > getPosition();

    // Setters
    // Sets up position.
    void setPosition( int x , int y );
    // Sets up position on x axis.
    void setPositionX( int x );
    // Sets up position on y axis.
    void setPositionY( int y );

    // Actions
    void moveFace( Direction , Direction );

};

#endif