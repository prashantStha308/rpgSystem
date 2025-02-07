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
    unsigned int maxSpeed = 20;
    std::string name;
    std::string _class;
    unsigned int health;
    int dx , dy; //Direction x and Direction y

public:

    Character(std::string name = "unnamed nomad" , std::string _class = "peasent" , unsigned int hp = 100) : name(name), _class(_class) , health(hp) {}

    // Pure Virtual Functions
        /**
     * @param Character& - target
     * @brief `Attacks the target`
     * Example:
     * ```
     * Assassin ezio("Ezio");
     * Mage gandalf("Gandalf");
     * cout<< ezio.attack(gandalf)<<endl;
     * ```
     * Output: " Ezio stealthily strikes Gandalf form the shadow "
     */
    virtual void attack(Character& target) = 0;

    /**
     * @brief `Displays the status of a character`
     * @brief Example:
     * ```
     * Mage mage("Gandalf");
     * mage->displayStats();
     * ```
     */
    virtual void displayStats() = 0;

    // Getters
    /**
     * @brief Get the name of the character.
     * Example:
     *```cpp
     * Character* enemy = new Assassin("Shadow");
     * std::cout << enemy->getName(); // Output: Shadow
     * ```
     * @return std::string The name of the character.
     * 
     * @note This function is a getter for the `name` member variable.
     */
    std::string getName() const;
    /**
     * @brief Get the class of the character.
     * Example:
     *```cpp
     * Character* enemy = new Assassin("Shadow");
     * std::cout << enemy->getClass(); // Output: "Assassin"
     * ```
     * @return std::string The name of the character.
     * 
     * @note This function is a getter for the `_class` member variable.
     */
    std::string getClass() const;

    

    // Actions
    /**
     * @param unsigned int - resource ( Mana , Stamina , Vigor )
     * @param unsiged int deplete - int to be depleted from resource
     * @param bool - isDepleted?
     * @brief
     * Example:
     * ```
     * void attack(){
     * depleteResource( mana , 10 , depleted )
     * }
     * ```
     */
    void depleteResource( unsigned int& resource , unsigned int deplete , bool& isDepleted );

    // Actions
    /**
     * @brief ` adds @param int amount of damage `
     * @param int damage
     */
    virtual void takeDamage( unsigned int );
    
    /**
     * @brief `Sets position of the Character on x and y axis`
     * @param int x - edits postion at x-axis
     * @param int y - edits postion at y-axis
     */
    void setPosition( int x , int y );

    /**
     * @param Direction horizontal = LEFT , RIGHT or STILL
     * @param Direction vertical = UP , DOWN or STILL
     * @param int x updates position on x axis
     * @param int y updates position on y axis
     * @brief 
     * Example:
     * ```
     * Assassin assassin("Ezio");
     * assassin.move( UP , LEFT , x , y );
     * ```
     */
    void move( Direction , Direction , int , int );

    virtual ~Character() {}
};

#endif
