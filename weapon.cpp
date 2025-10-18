#include "weapon.h"
#include <iostream>
using namespace std;

// Base Class: Weapon
Weapon::Weapon(const std::string& name, Rarity rarity, const std::string& material, int damage, int durability, int speed)
    : name(name), rarity(rarity), material(material), damage(damage), durability(durability), speed(speed) {
    //cout << "Weapon " << name << " created!" << endl;;
}

string Weapon::getRarityName() const {
    switch (rarity) {
        case Rarity::Common:    return "Common";
        case Rarity::Uncommon:  return "Uncommon";
        case Rarity::Rare:      return "Rare";
        case Rarity::Epic:      return "Epic";
        case Rarity::Legendary: return "Legendary";
        default:                return "Unknown";
    }
}

void Weapon::displayInfo() const {
    cout << "Name: " << name << endl;
    cout << "Rarity: " << getRarityName() << endl;
    cout << "Material: " << material << endl;
    cout << "Damage: " << damage << endl;
    cout << "Durability: " << durability << endl;
    cout << "Speed: " << speed << endl;
}

string Weapon::getName() const {
    cout << "Weapon Name: " << name << endl;
    return name;
}

int Weapon::getDamage() const { 
    return damage; 
}

void Weapon::setDamage(int damage) {
    this->damage = damage;
}

int Weapon::getDurability() const {
    return durability;
}

void Weapon::setDurability(int durability) {
    this->durability = durability;
}

int Weapon::getSpeed() const { 
    cout << "Getting Weapon: " << speed << endl;
    return speed; 
}

void Weapon::setSpeedValue(int value) { 
    speed = value;
}

void Weapon::buffSpeed() {
    faster(this);
}

Weapon& Weapon::operator=(const Weapon& other) {
    if (this != &other) {
        name      = other.name;
        rarity     = other.rarity;
        material   = other.material;
        damage     = other.damage;
        durability = other.durability;
        speed      = other.speed;
    }
    return *this;
}

string Weapon::getMaterial() const {
    return material;
}

Weapon::Weapon(const Weapon& other)
    : name(other.name),
      rarity(other.rarity),
      material(other.material),
      damage(other.damage),
      durability(other.durability),
      speed(other.speed) {}

bool Weapon::operator<(const Weapon& other) const {
    return damage < other.damage;
}

Weapon::~Weapon() {
    //cout << "Weapon " << name << " destroyed!" << endl;
}

// Derived Class: Sword
int Sword::swordCount = 0;

Sword::Sword(const std::string& name, Rarity rarity, const std::string& material, int damage, int durability, int speed,
             int bladeLength, int sharpness, int bleedChance)
    : Weapon(name, rarity, material, damage, durability, speed),
      bladeLength(bladeLength), sharpness(sharpness), bleedChance(bleedChance) {

    cout << "Sword " << name << " created!" << endl;
    swordCount++;
}

Sword::Sword(const Sword& other)
    : Weapon(other),
      bladeLength(other.bladeLength),
      sharpness(other.sharpness),
      bleedChance(other.bleedChance) {

    swordCount++;
    cout << "Sword " << name << " copied!" << endl;
}

int Sword::attack() const {
    cout << "Sword attack with damage: " << damage << endl;
    return damage;
}

void Sword::slash() const {
    cout << "Slashing the sword!" << endl;
}

void Sword::displayInfo() const {
    Weapon::displayInfo();
    cout << "Blade Length: " << bladeLength << endl;
    cout << "Sharpness: " << sharpness << endl;
    cout << "Bleed Chance: " << bleedChance << "%" << endl;
}

void Sword::increaseSpeed(Sword& sword) {
    faster(&sword);
}

string Sword::getRarityName() const {
    switch (rarity) {
        case Rarity::Common:    return "Common Sword";
        case Rarity::Uncommon:  return "Uncommon Sword";
        case Rarity::Rare:      return "Rare Sword";
        case Rarity::Epic:      return "Epic Sword";
        case Rarity::Legendary: return "Legendary Sword";
        default:                return "Unknown Sword";
    }
}

Sword& Sword::operator=(const Sword& other) {
    if (this != &other) {
        Weapon::operator=(other);
        bladeLength = other.bladeLength;
        sharpness   = other.sharpness;
        bleedChance = other.bleedChance;
    }
    return *this;
}

bool Sword::operator<(const Sword& other) const {
    return this->damage < other.damage;
}

int Sword::getSwordCount() {
    return swordCount;
}

Sword Sword::getBladeLengthByValue(Sword s) const { 
    cout << "Copy Blade Length by value is 5 shorter: " << bladeLength - 5 << endl;
    return s;
}

Sword Sword::getBladeLengthByReference(const Sword& s) const { 
    cout << "Copy Blade Length by reference is the same: " << bladeLength << endl;
    return s;
}

void Sword::printCount() {
    cout << "Number of Swords: " << swordCount << endl;
}

int Sword::getSpeed() const { 
    cout << "Getting Sword: " << speed << endl;
    return speed; 
};

Sword::~Sword() {
    cout << "Sword " << name << " destroyed!" << endl;
    swordCount--;
}

// Derived Class: Axe
int Axe::axeCount = 0;

Axe::Axe(const std::string& name, Rarity rarity, const std::string& material, int damage, int durability, int speed,
         int weight, int cleaveChance)
    : Weapon(name, rarity, material, damage, durability, speed),
      weight(weight), cleaveChance(cleaveChance) {

    cout << "Axe " << name << " created!" << endl;    
    axeCount++;
}

Axe::Axe(const Axe& other)
    : Weapon(other),
      weight(other.weight),
      cleaveChance(other.cleaveChance) {
    axeCount++;
}

int Axe::attack() const {
    cout << "Axe attack with damage: " << damage << endl;
    return damage;
}

void Axe::chop() const {
    cout << "Chopping with the axe!" << endl;
}

void Axe::displayInfo() const {
    Weapon::displayInfo();
    cout << "Weight: " << weight << endl;
    cout << "Cleave Chance: " << cleaveChance << "%" << endl;
}

string Axe::getRarityName() const {
    switch (rarity) {
        case Rarity::Common:    return "Common Axe";
        case Rarity::Uncommon:  return "Uncommon Axe";
        case Rarity::Rare:      return "Rare Axe";
        case Rarity::Epic:      return "Epic Axe";
        case Rarity::Legendary: return "Legendary Axe";
        default:                return "Unknown Axe";
    }
}

Axe& Axe::operator=(const Axe& other) {
    if (this != &other) {
        Weapon::operator=(other);
        weight = other.weight;
        cleaveChance = other.cleaveChance;
    }
    return *this;
}

bool Axe::operator<(const Axe& other) const {
    return damage < other.damage;
}

int Axe::getAxeCount() {
    return axeCount;
}

Axe::~Axe() {
    cout<< "Axe " << name << " destroyed!" << endl;
    axeCount--;
}

// Derived Class: SwordAxe. Combines Sword and Axe (Multiple Inheritance)
SwordAxe::SwordAxe(const std::string& name, Rarity rarity, const std::string& material, int damage, int durability, int speed,
                   int bladeLength, int sharpness, int bleedChance,
                   int weight, int cleaveChance)
    : Weapon(name, rarity, material, damage, durability, speed), // initialize virtual base
      Sword(name, rarity, material, damage, durability, speed, bladeLength, sharpness, bleedChance),
      Axe(name, rarity, material, damage, durability, speed, weight, cleaveChance) 
{
    cout << "SwordAxe " << name << " created!" << endl;
}

// Override attack to combine Sword and Axe attacks
int SwordAxe::attack() const {
    int swordDamage = Sword::attack(); // call Sword's attack
    int axeDamage   = Axe::attack();   // call Axe's attack
    int totalDamage = swordDamage + axeDamage;
    cout << "SwordAxe total damage: " << totalDamage << endl;
    return totalDamage;
}

// Override displayInfo to show info from both Sword and Axe
void SwordAxe::displayInfo() const {
    cout << name << " Info:" << endl;
    int swordDamage = Sword::attack(); // call Sword's attack
    int axeDamage   = Axe::attack();   // call Axe's attack
    int totalDamage = swordDamage + axeDamage;
    cout << "Rarity: " << getRarityName() << endl;
    cout << "Material: " << material << endl;
    cout << "Total Damage: " << totalDamage << endl; // combined damage
    cout << "Bleed Chance: " << Sword::bleedChance << "%" << endl;
    cout << "Cleave Chance: " << Axe::cleaveChance << "%" << endl;
}

SwordAxe::~SwordAxe() {
    cout << "SwordAxe " << name << " destroyed!" << endl;
}

// Non-member Functions
bool operator==(const Weapon& w1, const Weapon& w2) {
    return w1.getDamage() == w2.getDamage();
}

void displayArsenal(Weapon* const arsenal[], int size) {
    for (int i = 0; i < size; ++i) {
        arsenal[i]->displayInfo();
        cout << endl;
    }
}

void weaponBuffByValue(Sword weapon) {
    weapon.setDamage(weapon.getDamage() + 10);
}

void displayRarity(const Weapon& weapon) {
    cout << "Weapon Rarity: " << weapon.getRarityName() << endl;
}

void weaponBuffByReference(Sword& weapon) {
    weapon.setDamage(weapon.getDamage() + 10);
}

void getDurability(Weapon* weapon) {
    cout << "Weapon durability: " << weapon->getDurability() << endl;
}

void faster(Weapon* weapon) {
    weapon->setSpeedValue(weapon->getSpeed() + 10);
    cout << "Weapon speed increased to: " << weapon->getSpeed() << endl;
}

void useWeapon(void* obj) {
    Sword* swordPtr = static_cast<Sword*>(obj);
    swordPtr->slash();
}

void destroyWeapon(Weapon* weapon) {
    delete weapon;
}
