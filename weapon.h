#pragma once
#include <string>

enum class Rarity {
    Common,
    Uncommon,
    Rare,
    Epic,
    Legendary
};


// Base Class: Weapon (3. Abstract Class)
class Weapon {
private:
    friend void getDurability(Weapon* weapon); // Friend function to access private members

protected:
    std::string name; 
    Rarity rarity;
    std::string material;
    int damage;
    int speed;
    int durability;


public:
    // Constructors
    Weapon(const std::string& name, Rarity rarity, const std::string& material, int damage, int durability, int speed);
    Weapon(const Weapon& other);

    // Virtual Destructor
    virtual ~Weapon();

    // Abstract Method
    virtual int attack() const = 0;

    // Methods
    virtual void displayInfo() const;
    std::string getName() const; 
    virtual std::string getRarityName() const;
    std::string getMaterial() const;

    int getDamage() const;
    void setDamage(int damage);

    int getDurability() const;
    void setDurability(int durability);

    int getSpeed() const;
    void setSpeedValue(int value);
    void buffSpeed();

    // Operators
    virtual Weapon& operator=(const Weapon& other);
    virtual bool operator<(const Weapon& other) const;
};

// Derived Class: Sword (1. Inheritance, 2. Access Specifiers)
class Sword : public virtual Weapon {
private:
    int bladeLength;
    static int swordCount; // Static member to count attack
protected:
    int sharpness;
    int bleedChance;
public:
    // Constructors
    Sword(const std::string& name, Rarity rarity, const std::string& material, int damage, int durability, int speed,
          int bladeLength, int sharpness, int bleedChance);
    Sword(const Sword& other);

    // Destructor
    ~Sword();

    // Methods
    int attack() const override;
    void slash() const;
    void displayInfo() const override;
    std::string getRarityName() const;
    void increaseSpeed(Sword& sword); // Example method to increase speed
    int getSpeed() const;
    

    // Operators
    Sword& operator=(const Sword& other);
    bool operator<(const Sword& other) const;

    // Static
    static int getSwordCount();
    static void printCount();

    // Example methods using value/reference
    Sword getBladeLengthByValue(Sword s) const;
    Sword getBladeLengthByReference(const Sword& s) const;
};

// Derived Class: Axe
class Axe : public virtual Weapon {
private:
    static int axeCount; // Static member to count attacks  
protected:
    int weight;
    int cleaveChance;
public:
    // Constructors
    Axe(const std::string& name, Rarity rarity, const std::string& material, int damage, int durability, int speed,
        int weight, int cleaveChance);
    Axe(const Axe& other);

    // Destructor
    ~Axe();

    // Methods
    int attack() const override;
    void chop() const;
    void displayInfo() const override;
    std::string getRarityName() const;

    // Operators
    Axe& operator=(const Axe& other);
    bool operator<(const Axe& other) const;

    // Static tracking
    static int getAxeCount();
};

class SwordAxe : public Sword, public Axe {
public:
    // Constructor
    SwordAxe(const std::string& name, Rarity rarity, const std::string& material, int damage, int durability, int speed,
             int bladeLength, int sharpness, int bleedChance,
             int weight, int cleaveChance);

    // Override attack to combine Sword and Axe damage
    int attack() const override;

    // Override displayInfo to show both Sword and Axe info
    void displayInfo() const override;

    // Resolve ambiguity of Weapon::getRarityName
    std::string getRarityName() const override {
        // Option 1: combine both parent names
        return Sword::getRarityName() + " & " + Axe::getRarityName();

        // Option 2: pick one parent (uncomment if preferred)
        // return Sword::getRarityName();
        // return Axe::getRarityName();
    }
    ~SwordAxe();
};



// Non-member Function
void faster(Weapon* weapon);
void getDurability(Weapon* weapon);
void displayRarity(const Weapon& weapon);
void displayArsenal(Weapon* const arsenal[], int size);
void useWeapon(void* obj);
void destroyWeapon(Weapon* weapon);
bool operator==(const Weapon& w1, const Weapon& w2);
void weaponBuffByValue(Sword weapon);
void weaponBuffByReference(Sword& weapon);
