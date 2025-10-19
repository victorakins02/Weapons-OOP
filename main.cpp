#include "weapon.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;

int main() {
    // Creating instances of Sword (5. Dynamic Memory (new))
    Sword Tin =  Sword("Tin", Rarity::Common, "Tin", 15, 30, 25, 15, 10, 5);
    Sword *Iron = new Sword("Iron", Rarity::Epic, "Iron", 100, 200, 40, 90, 25, 50); 
    Sword *Diamond = new Sword("Diamond", Rarity::Legendary, "Diamond", 200, 500, 50, 100, 50, 60);
    Axe Bronze = Axe("Bronze", Rarity::Common, "Bronze", 30, 60, 20, 40, 10);
    Sword *Wood = new Sword("Wood", Rarity::Uncommon, "Wood", 20, 50, 30, 10, 5, 5);
    SwordAxe Silver = SwordAxe("Slver", Rarity::Rare, "Silver", 150, 300, 45, 95, 30, 40, 60, 20);

    // (6. Array of weapon pointers)
    cout << "Question 6: Array of Weapon Pointers" << endl;
    Weapon* Arsenal[3] = {Iron, Wood, Diamond};
    displayArsenal(Arsenal, 3);
    cout << endl;

    //(7.Smart Pointers)
    cout << "Question 7: Smart Pointers" << endl;
    shared_ptr<Sword> chrom = make_shared<Sword>("Chrom", Rarity::Legendary, "Chrom's Sword", 250, 600, 60, 110, 60, 70);
    cout << "chrom use_count: " << chrom.use_count() << endl; // 1

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
    increaseLength(Wood); // Increase blade length via friend function
    cout << endl;

    // (12. Virtual and Non-Virtual Methods)
    cout << "Question 12: Virtual vs Non-Virtual Methods" << endl;
    Weapon *Steel = new Sword("Steel", Rarity::Rare, "Steel", 70, 120, 38, 80, 15, 20);
    cout << Steel->getRarityName() << endl; // Virtual call -> Sword's getRarityName
    Steel->getName(); // Non-virtual call -> Weapon's getName()
    cout << endl;

    // (13. Explicit Casts)
    Sword *Copper = new Sword("Copper", Rarity::Rare, "Copper", 20, 20, 20, 25, 18, 22);
    cout << "Question 13: Explicit Casts" << endl;
    useWeapon(static_cast<void*>(Copper)); 
    cout << endl;

    // (14. Operator Overloading)
    cout << "Question 14: Operator Overloading" << endl;
    Sword *toySword = new Sword("ToySword", Rarity::Uncommon, "Wood", 20, 50, 30, 10, 5, 5);
    if (*Copper < *toySword) {
        cout << "Copper sword has less damage than toySsword." << endl;
    } else {
        cout << "Copper sword has more damage than or equal damage to ToySword." << endl;
    }

    if (*Copper == *Steel) {
        cout << "Copper sword has equal damage to Steel." << endl;
    } else {
        cout << "Copper sword has different damage than Steel." << endl;
    }

    *Copper + *toySword;
    cout << endl;

    // (15. Assignment Operator Overloading)
    cout << "Question 15: Assignment Operator Overloading" << endl;
    Sword mySword = Sword("MySword", Rarity::Uncommon, "Wood", 20, 50, 30, 10, 5, 5); 
    mySword = *Iron; // Calls overloaded assignment operator
    mySword.displayInfo();
    Sword anotherSword = Sword("AnotherSword",Rarity::Uncommon, "Wood", 20, 50, 30, 10, 5, 5); ;
    anotherSword = mySword = *Diamond; // Chained assignment
    anotherSword.displayInfo();
    cout << endl;

    // (16. Copy Constructor)
    cout << "Question 16: Copy Constructor" << endl;
    Sword copySword = *Diamond; // Calls copy constructor
    copySword.displayInfo();
    copySword.getBladeLengthByValue(copySword); // PBV
    copySword.getBladeLengthByReference(copySword); // PBR
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
    vector<Sword> inventory; // Vector to hold void pointers
    inventory.push_back(mySword);
    inventory.push_back(anotherSword);
    inventory.push_back(Tin);
    cout << "Inventory contains " << inventory.size() << " items." << endl;
    cout << endl;

    // (20. Sorting Algorithms)
    cout << "Question 20: Sorting Algorithms" << endl;
    sort(inventory.begin(), inventory.end());


    for (Sword& i : inventory) {
        cout << "Item " << i.getMaterial() << ", Damage: " << i.getDamage() << endl;
    }
    cout << endl;
    

    //(5. Dynamic Memory (delete))
    for (Weapon*& ptr : Arsenal) {
        destroyWeapon(ptr); // Polymorphic call
    }
    
    //(5. Dynamic Memory (delete))
    delete Steel;

    return 0;
}