#include "weapon.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;

int main() {
    // Creating instances of Sword (5. Dynamic Memory (new))
    Sword Tin =  Sword(Rarity::Common, "Tin", 15, 30, 25, 15, 10, 5);
    Sword *Iron = new Sword(Rarity::Epic, "Iron", 100, 200, 40, 90, 25, 50); 
    Sword *Wood = new Sword(Rarity::Uncommon, "Wood", 20, 50, 30, 10, 5, 5);
    Sword *Diamond = new Sword(Rarity::Legendary, "Diamond", 200, 500, 50, 100, 50, 60);
    Sword *Steel = new Sword(Rarity::Rare, "Steel", 70, 120, 38, 80, 15, 20);

    //Sword ike = Sword(Rarity::Rare, "Iron", 80, 150, 35, 85, 20, 40);
    //Sword marth = Sword(Rarity::Rare, "Wood", 40, 20,70, 85, 5, 1);

    //Sword copyOfIke = ike; // Calls copy constructor
    //copyOfIke.displayInfo();
    //Explain copy constructor -> Pass by value creates a copy of the object
    //Explain pass by reference -> Pass by reference uses the original object without creating a copy
    //Sword roy = ike.getBladeLengthbyValue(ike); // Pass by value -> original is unchanged
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

    //Iron->printCount(); // Static method call
    //(7.Smart Pointers)
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

    cout << "chrom use_count after robin scope: " << chrom.use_count() << endl; // 2
    //vector<void*> inventory; // Vector to hold void pointers
    //inventory.push_back(static_cast<void*>(Iron));
    //inventory.push_back(static_cast<void*>(Wood));
    //inventory.push_back(static_cast<void*>(Diamond));

    //sort(inventory.begin(), inventory.end());

/*
    for (void* item : inventory) {
        useWeapon(item); // Use each weapon in the inventory
    }
*/
    // (6. Array of weapon pointers)
    Weapon* Arsenal[3] = {Iron, Wood, Diamond};
    displayArsenal(Arsenal, 3);

    //(5. Dynamic Memory (delete))
    for (Weapon*& ptr : Arsenal) {
        destroyWeapon(ptr); // Polymorphic call
    }
    
    //(5. Dynamic Memory (delete))
    delete Steel;

    return 0;
}
