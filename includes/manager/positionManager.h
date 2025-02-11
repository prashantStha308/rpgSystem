#ifndef POSITIONMANAGER_H
#define POSITIONMANAGER_H

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

    // Setters
    /**
     * @brief
     * `setPosition( int x , int y ) - Sets the position of character`
     * 
     */
    void setPosition( int x , int y );
    void setPositionX( int x );
    void setPositionY( int y );

    // Actions
    void move( Direction , Direction );

};

#endif