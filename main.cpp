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
            // Weapon created
        }

    void attack() {
        // Attack or Damage
    }

    void repair() {
        // Repair weapon
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

int main() {
    Weapon myWeapon("Epic", "Steel", 50, 100);
    myWeapon.displayInfo();

    Weapon *sword = new Weapon("Legendary", "Mythril", 100, 200);
    sword->displayInfo();
    
    delete sword; 
    return 0;
}