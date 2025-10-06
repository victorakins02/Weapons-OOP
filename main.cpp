#include <iostream>
using namespace std;

class Weapon { //Parent class + thinking of making it an abstract class
private: //Ideas of states. Liklely to be changed to protected
    string rarity;
    string material;
    int damage;
    int durability;

public: //Ideas of Methods
    Weapon(string rarity, string material, int damage, int durability)
        : rarity(rarity), material(material), damage(damage), durability(durability) {
            // Weapon created/Constructor
        }

    void attack() {
        // Attack or Damage + may leave this abstract for child classes
    }

    void repair() {
        // Repair weapon + may not do this
    }

    void displayInfo() {
        cout << "Rarity: " << rarity << endl;
        cout << "Material: " << material << endl;
        cout << "Damage: " << damage << endl;
        cout << "Durability: " << durability << endl;
        cout << endl;
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
            // Sword created/Constructor
        }

    void slash() {
        // Slash attack
    }

    void parry() {
        // Parry attack
    }

    void displayInfo() {
        Weapon::displayInfo(); // Call parent method to display common info
        cout << "Blade Length: " << bladeLength << endl;
        cout << "Sharpness: " << sharpness << endl;
        cout << "Bleed Chance: " << bleedChance << "%" << endl;
        cout << endl;
    }

    ~Sword(){
        // Maybe message when sword is destroyed
    }; // destructor
};

int main() {
    Weapon myWeapon("Epic", "Steel", 50, 100);
    myWeapon.displayInfo();

    Sword *sword = new Sword("Legendary", "Mythril", 100, 200, 40, 90, 25); 
    sword->displayInfo();
    
    delete sword; 
    return 0;
}