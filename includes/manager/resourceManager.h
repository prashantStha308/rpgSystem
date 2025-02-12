#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

class ResourceManager{

    protected:
        // Resources
        unsigned int mana = 0;
        unsigned int stamina = 0;
        unsigned int vigor = 0;
        // Resource flags
        bool isManaDepleted = false;
        bool isStaminaDepleted = false;
        bool isVigorDepleted = false;

    public:
        // Setters
        // Core functions
        void depleteResource( unsigned int& , unsigned int , bool& );
        void gainResource( unsigned int& , unsigned int , bool& );
        // Accessors
        // Getters
        unsigned int& getStamina();
        unsigned int& getVigor();
        unsigned int& getMana();
        // Flag Getters
        bool& getIsStaminaDepleted();
        bool& getIsVigorDepleted();
        bool& getIsManaDepleted();
        
        // Setters
        void setStamina(unsigned int amount);
        void setVigor(unsigned int amount);
        void setMana(unsigned int amount);
        // Flag Setters
        void setIsStaminaDepleted( bool );
        void setIsManaDepleted( bool );
        void setIsVigorDepleted( bool );        

};

#endif