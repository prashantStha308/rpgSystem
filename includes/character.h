#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
/**
 * @brief `Enumeration for direction`
 * @param Direction Up -> Move up
 * @param Direction DOWN -> Move down
 * @param Direction LEFT -> Move to left
 * @param Direction RIGHT -> Move to right
 * @param Direction STILL -> Stay till in an axis 
 */
enum Direction{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    STILL
};

class Character {
protected:
    std::string name;
    std::string _class;
    unsigned int health;
    int dx , dy; // Directions
    // nature powers
    unsigned int stamina = 0;
    unsigned int vigor = 0;
    unsigned int mana = 0;
    // nature flags
    bool isManaDepleted = false;
    bool isStaminaDepleted = false;
    bool isVigorDepleted = false;

public:

    Character(std::string name , std::string _class , unsigned int hp);

    // Pure Virtual Functions
    virtual void attack(Character& target) = 0;
    virtual void displayStats() = 0;

    // Getters
    std::string getName() const;
    std::string getClass() const;
    unsigned int getMana() const;
    unsigned int getStamina() const;
    unsigned int getVigor() const;

    // Setters
    void setPosition( int x , int y );
    void setMana( unsigned int );
    void setStamina( unsigned int );
    void setVigor( unsigned int );

    // nature points manipulators
    /**
     * @param unsigned_int - resource ( Mana , Stamina , Vigor )
     * @param unsiged_int deplete - int to be depleted from resource
     * @param bool - isDepleted?--> isManaDepleted, isVigorDepleted....
     */
    void depleteResource( unsigned int& , unsigned int , bool& );
    void gainResource( unsigned int& , unsigned int , bool& );
    void depleteMana( unsigned int );
    void depleteStamina( unsigned int );
    void depleteVigor( unsigned int );
    void gainMana( unsigned int );
    void gainStamina( unsigned int );
    void gainVigor( unsigned int );

    // Actions
    virtual void takeDamage( unsigned int );
    /**
     * @param Direction horizontal = LEFT , RIGHT or STILL
     * @param Direction vertical = UP , DOWN or STILL
     * @param int x updates position on x axis
     * @param int y updates position on y axis
     */
    void move( Direction , Direction , int , int );


    virtual ~Character() {}
};

#endif
