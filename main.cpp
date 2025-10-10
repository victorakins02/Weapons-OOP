#include <iostream>
#include <string>
using namespace std;

enum class Rarity {
    Common,
    Uncommon,
    Rare,
    Epic,
    Legendary
};

class Weapon { //Parent class + thinking of making it an abstract class
private: 
friend void getDurability(Weapon* weapon); // Friend function to access private members

protected: //Ideas of states. Liklely to be changed to protected
    Rarity rarity;
    string material;
    int damage;
    int durability; // may need to make private and use friend function to access it

public: //Ideas of Methods
    Weapon(Rarity rarity, string material, int damage, int durability)
    : rarity(rarity), material(material), damage(damage), durability(durability) {
        // Maybe message when weapon is created
    }

    


    virtual int attack() const = 0; // Pure virtual function making this an abstract class

    void repair() {
        // Repair weapon + may not do this
    }

    string getRarityName() const {
        switch (rarity) {
            case Rarity::Common:    return "Common";
            case Rarity::Uncommon:  return "Uncommon";
            case Rarity::Rare:      return "Rare";
            case Rarity::Epic:      return "Epic";
            case Rarity::Legendary: return "Legendary";
            default:                return "Unknown";
        }
    }

    void displayInfo() const {
        cout << "Rarity: " << getRarityName() << endl;
        cout << "Material: " << material << endl;
        cout << "Damage: " << damage << endl;
        cout << "Durability: " << durability << endl;
    }

    int getDamage() const { 
        cout << "Weapon damage: " << damage << endl;
        return damage; 
    }

    

    int setDamage(int damage){
        this->damage = damage;
        return damage;
    }

    int setDurability(int durability){
        this->durability = durability;
        return durability;
    }

    virtual ~Weapon(){
        // Maybe message when weapon is destroyed
    }; // destructor


};

class Sword : public Weapon {
private:
    int bladeLength;
    int sharpness;
    int bleedChance;
public:
    Sword(Rarity rarity, string material, int damage, int durability, int bladeLength, int sharpness, int bleedChance)
        : Weapon(rarity, material, damage, durability), bladeLength(bladeLength), sharpness(sharpness), bleedChance(bleedChance) {
            //cout << material << " Sword created!" << endl; // May add names to the weapons later. Wee can the sayt "Excalibur created".
        }

    virtual int attack() const {
        cout << "Sword attack with damage: " << damage << endl;
        return damage;
    }

    void displayInfo() const {
        Weapon::displayInfo(); // Call parent method to display common info
        cout << "Blade Length: " << bladeLength << endl;
        cout << "Sharpness: " << sharpness << endl;
        cout << "Bleed Chance: " << bleedChance << "%" << endl;
    }

    ~Sword(){
        //cout << material << " Sword destroyed" << endl;
    }; // destructor
};

bool operator == (const Weapon& w1, const Weapon& w2) {
    // Compare based on damage
    return w1.attack() == w2.attack();
}

void weaponbuffbyvalue(Sword weapon) {
    // This function won't modify the original weapon
    weapon.setDamage(weapon.getDamage() + 10); 
}

void weaponbuffbyreference(Sword& weapon) {
    // This function can modify the original weapon
    weapon.setDamage(weapon.getDamage() + 10); 
}

void getDurability(Weapon* weapon) { 
    cout << "Weapon durability: " << weapon->durability << endl;
}

void destroyWeapon(Weapon* weapon) {
    delete weapon; // Polymorphic call to the appropriate destructor
}

// I am thinking of implemeenting Operator Overloading by doing a double attack function.
// This will allow the player to do two attacks in one turn.

// I am thinking of implementing Enumweapon types to determine the rarity of  the weapon.
// May make it multiplier for the stats of the weapon.


int main() {
    // Creating instances of Sword
    Sword Tin =  Sword(Rarity::Common, "Tin", 15, 30, 25, 15, 10);
    Sword *Iron = new Sword(Rarity::Epic, "Iron", 100, 200, 40, 90, 25); 
    Sword *Wood = new Sword(Rarity::Uncommon, "Wood", 20, 50, 30, 10, 5);
    Sword *Diamond = new Sword(Rarity::Legendary, "Diamond", 200, 500, 50, 100, 50);

    Iron->displayInfo();
    getDurability(Iron);
    //Iron->getDamage();
    //weaponbuffbyvalue(*Iron); // This won't change the original Iron sword
    //weaponbuffbyreference(*Iron); // This will change the original Iron sword
    //Iron->getDamage();
    
    Weapon* Arsenal[3] = {Iron, Wood, Diamond}; // Array of weapon pointers

    for (Weapon*& ptr : Arsenal) {
        destroyWeapon(ptr); // Polymorphic call
    }
    return 0;
}