#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;

class Weapon; // Using for self referencing. Keep getting out of scope errors without it

enum class Rarity {

    Common,
    Uncommon,
    Rare,
    Epic,
    Legendary
};

void faster(Weapon* weapon);

class Weapon { //Parent class + thinking of making it an abstract class
private: 
friend void getDurability(Weapon* weapon); // Friend function to access private members

protected: //Ideas of states. Liklely to be changed to protected
    Rarity rarity;
    string material;
    int damage;
    int speed; 
    int durability; // may need to make private and use friend function to access it

public: //Ideas of Methods
    Weapon(Rarity rarity, string material, int damage, int durability, int speed)
    : rarity(rarity), material(material), damage(damage), durability(durability), speed(speed) {
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

    virtual void displayInfo() const {
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

    int getSpeed() const { 
        cout << "Weapon speed: " << speed << endl;
        return speed; 
    }

    void setSpeedValue(int value) { 
        speed = value;
    }

    void buffSpeed() {
        faster(this);
    }

    virtual Weapon& operator=(const Weapon& other) {
    if (this != &other) {
        this->rarity     = other.rarity;
        this->material   = other.material;   // std::string deep-copies itself
        this->damage     = other.damage;
        this->durability = other.durability;
        this->speed      = other.speed;
    }
    return *this;
    }

    Weapon(const Weapon& other) 
        : rarity(other.rarity), material(other.material), damage(other.damage), durability(other.durability), speed(other.speed) {
            // Copy constructor
        }

    virtual bool operator<(const Weapon& other) const {
    return damage < other.damage;
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
        static int swordCount; // Static member to count attacks
    public:
        Sword(Rarity rarity, string material, int damage, int durability, int speed, int bladeLength, int sharpness, int bleedChance)
            : Weapon(rarity, material, damage, durability, speed), bladeLength(bladeLength), sharpness(sharpness), bleedChance(bleedChance) {
                //cout << material << " Sword created!" << endl; // May add names to the weapons later. Wee can the sayt "Excalibur created".
                swordCount++;
            }

        Sword (const Sword& other) 
            : Weapon(other), 
              bladeLength(other.bladeLength), sharpness(other.sharpness), bleedChance(other.bleedChance) {
                cout << "Sword copied!" << endl;
                swordCount++;
            }

        virtual int attack() const {
            cout << "Sword attack with damage: " << damage << endl;
            return damage;
        }

        void slash() const {
            std::cout << "Slashing the sword!" << std::endl;
        }

        
        void displayInfo() const override{
            Weapon::displayInfo(); // Call parent method to display common info
            cout << "Blade Length: " << bladeLength << endl;
            cout << "Sharpness: " << sharpness << endl;
            cout << "Bleed Chance: " << bleedChance << "%" << endl;
        }

        string getRarityName() const {
            switch (rarity) {
                case Rarity::Common:    return "Common Sword";
                case Rarity::Uncommon:  return "Uncommon Sword";
                case Rarity::Rare:      return "Rare Sword";
                case Rarity::Epic:      return "Epic Sword";
                case Rarity::Legendary: return "Legendary Sword";
                default:                return "Unknown Sword";
            }
        }

        Sword& operator=(const Sword& other) {
        if (this != &other) {
            // Copy base part (Weapon)
            this->rarity     = other.rarity;
            this->material   = other.material;   // std::string deep-copies itself
            this->damage     = other.damage;
            this->durability = other.durability;
            this->speed      = other.speed;

            // Copy derived part (Sword)
            this->bladeLength = other.bladeLength;
            this->sharpness   = other.sharpness;
            this->bleedChance = other.bleedChance;
        }
        return *this;
        }

        bool operator<(const Sword& other) const {
        return damage < other.damage;
        }

        int getSwordCount() const {
            return swordCount;
        }

        Sword getBladeLengthbyValue(Sword s) const { 
            cout << "Copy Blade Length by value is 5 shorter: " << bladeLength - 5 << endl;
            return s;
        };

        Sword getBladeLengthbyReference(const Sword& s) const { 
            cout << "Copy Blade Length by reference is the same: " << bladeLength << endl;
            return s;
        };

        static void printCount() { // Static member function
        cout << "Number of Swords: " << swordCount << endl;
        }

        ~Sword(){
            //cout << material << " Sword destroyed" << endl;
            swordCount--;
        }; // destructor
    };

class Axe : public Weapon {
    private:
        int weight;
        int cleaveChance;
        static int axeCount; // Static member to count attacks
    public:
        Axe(Rarity rarity, string material, int damage, int durability, int speed, int weight, int cleaveChance)
            : Weapon(rarity, material, damage, durability, speed), weight(weight), cleaveChance(cleaveChance) {
                //cout << material << " Axe created!" << endl; // May add names to the weapons later. Wee can the sayt "Excalibur created".
            }

        Axe (const Axe& other) 
            : Weapon(other), 
              weight(other.weight), cleaveChance(other.cleaveChance) {
                // Copy constructor
            }

        virtual int attack() const override {
            cout << "Axe attack with damage: " << damage << endl;   
            return damage;
        }   

        void chop() const {
            std::cout << "Chopping with the axe!" << std::endl;
        }

        void displayInfo() const override{
            Weapon::displayInfo(); // Call parent method to display common info
            cout << "Weight: " << weight << endl;
            cout << "Cleave Chance: " << cleaveChance << "%" << endl;
        }

        string getRarityName() const {
            switch (rarity) {
                case Rarity::Common:    return "Common Axe";
                case Rarity::Uncommon:  return "Uncommon Axe";
                case Rarity::Rare:      return "Rare Axe";
                case Rarity::Epic:      return "Epic Axe";
                case Rarity::Legendary: return "Legendary Axe";
                default:                return "Unknown Axe";
            } // May not need to repeat this function. Can inherit from Weapon then name it Axe where needed. Make it abstract in Weapon.
        }

        Axe operator=(const Axe& other) {
        if (this != &other) {
            // Copy base part (Weapon)
            this->rarity     = other.rarity;
            this->material   = other.material;   // std::string deep-copies itself
            this->damage     = other.damage;
            this->durability = other.durability;
            this->speed      = other.speed;

            // Copy derived part (Axe)
            this->weight      = other.weight;
            this->cleaveChance = other.cleaveChance;
            } 
            return *this;
        }

        int getAxeCount() const {
            return axeCount;
        }

        ~Axe(){
            //cout << material << " Axe destroyed" << endl;
        }; // destructor

};

class SwordAxe : public Sword, public Axe { // Example of multiple inheritance
    

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

void faster(Weapon* weapon) {
    weapon->setSpeedValue(weapon->getSpeed() + 10);
    cout << "Weapon speed increased to: " << weapon->getSpeed() << endl;
}

void useWeapon(void* obj) {
    // Cast the void* back to Sword* using static_cast
    Sword* swordPtr = static_cast<Sword*>(obj);
    // Now you can call Sword methods
    swordPtr->slash();
}

void destroyWeapon(Weapon* weapon) {
    delete weapon; // Polymorphic call to the appropriate destructor
}

// I am thinking of implemeenting Operator Overloading by doing a double attack function.
// This will allow the player to do two attacks in one turn.

// I am thinking of implementing Enumweapon types to determine the rarity of  the weapon.
// May make it multiplier for the stats of the weapon.

int Sword::swordCount = 0;

int main() {
    // Creating instances of Sword
    Sword Tin =  Sword(Rarity::Common, "Tin", 15, 30, 25, 15, 10, 5);
    Sword *Iron = new Sword(Rarity::Epic, "Iron", 100, 200, 40, 90, 25, 50); 
    Sword *Wood = new Sword(Rarity::Uncommon, "Wood", 20, 50, 30, 10, 5, 5);
    Sword *Diamond = new Sword(Rarity::Legendary, "Diamond", 200, 500, 50, 100, 50, 60);

    Sword ike = Sword(Rarity::Rare, "Iron", 80, 150, 35, 85, 20, 40);
    Sword marth = Sword(Rarity::Rare, "Wood", 40, 20,70, 85, 5, 1);

    Sword copyOfIke = ike; // Calls copy constructor
    //copyOfIke.displayInfo();
    //Explain copy constructor -> Pass by value creates a copy of the object
    //Explain pass by reference -> Pass by reference uses the original object without creating a copy
    Sword roy = ike.getBladeLengthbyValue(ike); // Pass by value -> original is unchanged
    //ike.getBladeLengthbyReference(ike); // Pass by reference -> original can be changed
    //roy.displayInfo();

    //Weapon *weaponPtr = &Tin; 
    //weaponPtr->displayInfo(); // Virtual call to Sword's displayInfo
    //cout << weaponPtr->getRarityName() << endl; // Non-virtual call to Weapon's getRarityName

    //Iron->buffSpeed(); // Increase speed by 10

    //Iron->displayInfo();
    //getDurability(Iron);
    //Iron->getDamage();
    //weaponbuffbyvalue(*Iron); // This won't change the original Iron sword
    //weaponbuffbyreference(*Iron); // This will change the original Iron sword
    //Iron->getDamage();

    Iron->printCount(); // Static method call

    shared_ptr<Sword> chrom = make_shared<Sword>(Rarity::Legendary, "Chrom's Sword", 250, 600, 60, 110, 60, 70);
    cout << "chrom use_count: " << chrom.use_count() << endl; // 1
    //So chrom is a smart Sword pointer to a sword namedchroms sword. 
    //Then we make another smart Sword pointer named lucina which is also pointing to chroms sword.  
    //Now there is two smart pointers pointing to chroms sword. 
    //When chrom and lucina go out of scope they automatically get deleted.

    shared_ptr<Sword> lucina = chrom; // Shared ownership
    cout << "chrom use_count after lucina copy: " << chrom.use_count() << endl; // 2
    cout << "lucina use_count: " << lucina.use_count() << endl;

    {
        shared_ptr<Sword> robin = chrom;
        cout << "chrom use_count: " << chrom.use_count() << endl; // 3
        cout << "robin use_count: " << robin.use_count() << endl; // 3
    } // robin goes out of scope here so back to 2

    vector<void*> inventory; // Vector to hold void pointers
    inventory.push_back(static_cast<void*>(Iron));
    inventory.push_back(static_cast<void*>(Wood));
    inventory.push_back(static_cast<void*>(Diamond));

    sort(inventory.begin(), inventory.end());

    for (void* item : inventory) {
        useWeapon(item); // Use each weapon in the inventory
    }

    Weapon* Arsenal[3] = {Iron, Wood, Diamond}; // Array of weapon pointers

    for (Weapon*& ptr : Arsenal) {
        destroyWeapon(ptr); // Polymorphic call
    }
    return 0;
}