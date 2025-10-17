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
    Sword *Diamond = new Sword(Rarity::Legendary, "Diamond", 200, 500, 50, 100, 50, 60);
    Axe Bronze = Axe(Rarity::Common, "Bronze", 30, 60, 20, 40, 10);
    Sword *Wood = new Sword(Rarity::Uncommon, "Wood", 20, 50, 30, 10, 5, 5);

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

    // (6. Array of weapon pointers)
    cout << "Question 6: Array of Weapon Pointers" << endl;
    Weapon* Arsenal[3] = {Iron, Wood, Diamond};
    displayArsenal(Arsenal, 3);
    cout << endl;

    //Iron->printCount(); // Static method call
    //(7.Smart Pointers)
    cout << "Question 7: Smart Pointers" << endl;
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
    cout << endl;

    //sort(inventory.begin(), inventory.end());

    // (8. Const Correctness)
    cout << "Question 8: Const Correctness" << endl;
    Tin.attack(); 
    displayRarity(Tin);
    cout << endl;

    // (9. PBV vs PBR)
    cout << "Question 9: PBV vs PBR" << endl;
    weaponBuffByValue(Tin); // Pass by value
    cout << "After PBV, Tin's damage: " << Tin.getDamage() << endl; // Unchanged -> created copy so original is same
    weaponBuffByReference(Tin); // Pass by reference
    cout << "After PBR, Tin's damage: " << Tin.getDamage() << endl; // Increased
    cout << endl;

    // (10. Self-Referencing Objects)
    cout << "Question 10: Self Reference" << endl;
    Tin.increaseSpeed(Tin); // Increase speed using self-reference
    cout << endl;

    // (11. Friend Functions)
    cout << "Question 11: Friend Functions" << endl;
    getDurability(&Bronze); // Access private member durability via friend function. Need to redo this on something private
    cout << endl;

    // (12. Virtual and Non-Virtual Methods)
    cout << "Question 12: Virtual vs Non-Virtual Methods" << endl;
    Weapon *Steel = new Sword(Rarity::Rare, "Steel", 70, 120, 38, 80, 15, 20);
    cout << Steel->getRarityName() << endl; // Virtual call -> Sword's getRarityName
    Steel->getSpeed(); // Non-virtual call -> Weapon's getSpeed
    cout << endl;

    // (13. Explicit Casts)
    Sword *Copper = new Sword(Rarity::Rare, "Copper", 20, 20, 20, 25, 18, 22);
    cout << "Question 13: Explicit Casts" << endl;
    useWeapon(static_cast<void*>(Copper)); 
    cout << endl;

    // (14. Operator Overloading)
    cout << "Question 14: Operator Overloading" << endl;
    Sword *toySword = new Sword(Rarity::Uncommon, "Wood", 20, 50, 30, 10, 5, 5);
    if (*Copper < *toySword) {
        cout << "Copper sword has less damage than Steel sword." << endl;
    } else {
        cout << "Copper sword has more damage than Steel sword." << endl;
    }
    cout << endl;

    // (15. Assignment Operator Overloading)
    cout << "Question 15: Assignment Operator Overloading" << endl;
    Sword mySword = Sword(Rarity::Uncommon, "Wood", 20, 50, 30, 10, 5, 5); 
    mySword = *Iron; // Calls overloaded assignment operator
    mySword.displayInfo();
    Sword anotherSword = Sword(Rarity::Uncommon, "Wood", 20, 50, 30, 10, 5, 5); ;
    anotherSword = mySword = *Diamond; // Chained assignment
    anotherSword.displayInfo();
    cout << endl;

    // (16. Copy Constructor)
    cout << "Question 16: Copy Constructor" << endl;
    Sword copySword = *Diamond; // Calls copy constructor
    copySword.displayInfo();
    cout << endl;

    // (17. Static Members)
    cout << "Question 17: Static Members" << endl;
    Sword::printCount(); // Print number of Sword instances
    cout << endl;

    // (18. Enumerations)
    cout << "Question 18: Enumerations" << endl;
    cout << "Rarity of Iron sword: " << Iron->getRarityName() << endl;
    cout << "Rarity of Diamond sword: " << Diamond->getRarityName() << endl;
    cout << endl;

    // (19. Vectors)
    cout << "Question 19: Vectors" << endl;
    vector<void*> inventory; // Vector to hold void pointers
    inventory.push_back(static_cast<void*>(Iron));
    inventory.push_back(static_cast<void*>(Wood));
    inventory.push_back(static_cast<void*>(Diamond));
    cout << "Inventory contains " << inventory.size() << " items." << endl;
    cout << endl;

    // (20. Sorting Algorithms)
    cout << "Question 20: Sorting Algorithms" << endl;
    //sort(inventory.begin(), inventory.end(), [](void* a, void* b) {});
    for (size_t i = 0; i < inventory.size(); ++i) {
        cout << "Item " << inventory[i] << endl;
    }
    cout << endl;
/*
    for (void* item : inventory) {
        useWeapon(item); // Use each weapon in the inventory
    }
*/
    

    //(5. Dynamic Memory (delete))
    for (Weapon*& ptr : Arsenal) {
        destroyWeapon(ptr); // Polymorphic call
    }
    
    //(5. Dynamic Memory (delete))
    delete Steel;

    return 0;
}