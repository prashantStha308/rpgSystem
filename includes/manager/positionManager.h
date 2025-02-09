#ifndef POSITIONMANAGER_H
#define POSITIONMANAGER_H

class PositionManager{
    protected:
        int posX;
        int posY;
    public:
    PositionManager( int , int );

    // Getters
    int getPositionX();
    int getPositionY();

    // Setters
    void setPosition( int x , int y );
    void setPositionX( int x );
    void setPositionY( int y );

};

#endif