# Weapons Class Hierarchy

## Project Overview
This project implements a comprehensive weapon system in C++. The primary goal is to demonstrate a deep understanding of Object-Oriented Programming (OOP) principles by modeling various combat items—such as Swords, Axes, and hybrid Sword-Axes—within a structured class hierarchy.

## Features & OOP Concepts Demonstrated
The implementation covers 20 key programming questions and concepts, including:

* **Inheritance & Multiple Inheritance**: Utilizing a base `Weapon` class with specialized derived classes, including the `SwordAxe` hybrid class which demonstrates multiple inheritance.
* **Abstract Classes & Polymorphism**: Use of pure virtual functions to ensure a consistent interface across different weapon types and the implementation of dynamic binding.
* **Memory Management**: Demonstrates manual memory management using `new` and `delete`, the importance of **Virtual Destructors**, and modern C++ **Smart Pointers** (`std::shared_ptr`).
* **Encapsulation & Access Specifiers**: Proper use of `public`, `protected`, and `private` members to manage data access.
* **Operator Overloading**: Custom logic for comparing weapons (`==`), combining stats (`+`), and deep copying via the assignment operator (`=`).
* **Standard Template Library (STL)**: Use of `std::vector` for inventory management and the `std::sort` algorithm for organizing weapons by attributes like damage.
* **Advanced C++ Features**: Implementation of `static` members for tracking object counts, `enum` for item rarity, and `const` correctness.

## Repository Structure
* `Weapon.h/cpp`: Definitions and implementations for the base Abstract Class.
* `Sword.h/cpp`: Specific implementations for Sword-type weapons.
* `Axe.h/cpp`: Specific implementations for Axe-type weapons.
* `SwordAxe.h/cpp`: A hybrid class demonstrating multiple inheritance.
* `main.cpp`: A comprehensive test suite that executes 20 distinct coding tasks to verify functionality and OOP logic.
