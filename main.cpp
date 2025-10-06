#include <iostream>
using namespace std;

class Weapon { //Parent class + thinking of making it an abstract class
protected: //Ideas of states. Liklely to be changed to protected
    string rarity;
    string material;
    int damage;
    int durability;

public: //Ideas of Methods
    Weapon(string rarity, string material, int damage, int durability)
        : rarity(rarity), material(material), damage(damage), durability(durability) {
            // Weapon created/Constructor
        }

    virtual int attack() = 0; // Pure virtual function making this an abstract class

    void repair() {
        // Repair weapon + may not do this
    }

    void displayInfo() {
        cout << "Rarity: " << rarity << endl;
        cout << "Material: " << material << endl;
        cout << "Damage: " << damage << endl;
        cout << "Durability: " << durability << endl;
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
    Sword(string rarity, string material, int damage, int durability, int bladeLength, int sharpness, int bleedChance)
        : Weapon(rarity, material, damage, durability), bladeLength(bladeLength), sharpness(sharpness), bleedChance(bleedChance) {
            cout << material << " Sword created!" << endl; // May add names to the weapons later. Wee can the sayt "Excalibur created".
        }

    virtual int attack() {
        cout << "Sword attack with damage: " << damage << endl;
        return damage;
    }

    void parry() {
        // Parry attack
    }

    void displayInfo() {
        Weapon::displayInfo(); // Call parent method to display common info
        cout << "Blade Length: " << bladeLength << endl;
        cout << "Sharpness: " << sharpness << endl;
        cout << "Bleed Chance: " << bleedChance << "%" << endl;
    }

    ~Sword(){
        cout << material << " Sword destroyed" << endl;
    }; // destructor
};

void destroyWeapon(Weapon* weapon) {
    delete weapon; // Polymorphic call to the appropriate destructor
}

// I am thinking implementing a pass by refernece function to upgrade the weapons. 
// The rarity will determine the upgrade level and upgrade on stats. 


// I am thinking of implemeenting Operator Overloading by doing a double attack function.
// This will allow the player to do two attacks in one turn.

// I am thinking of implementing Enumweapon types to determine the rarity of  the weapon.
// May make it multiplier for the stats of the weapon.


int main() {
    // Creating instances of Sword
    Sword *Iron = new Sword("Epic", "Iron", 100, 200, 40, 90, 25); 
    Sword *Wood = new Sword("Common", "Wood", 20, 50, 30, 10, 5);
    Sword *Diamond = new Sword("Legendary", "Diamond", 200, 500, 50, 100, 50);
    
    Weapon* Arsenal[3] = {Iron, Wood, Diamond}; // Array of weapon pointers

    for (Weapon*& ptr : Arsenal) {
        destroyWeapon(ptr); // Polymorphic call
    }
    return 0;
}