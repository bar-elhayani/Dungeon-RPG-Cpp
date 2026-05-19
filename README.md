# Dungeon Game - C++ OOP Adventure

A dungeon-based adventure game built in C++ using object-oriented design principles.

## Gameplay
Navigate through dungeon rooms, battle monsters, and survive using unique player abilities.
The dungeon layout is loaded dynamically from a configuration file.

## Code Structure
- **Entity** — Abstract base class for all players and monsters; handles health, damage, and overloaded operators
- **Player** — Derived from Entity; includes Fighter and Sorcerer subclasses with unique abilities
- **Monster** — Derived from Entity; includes Dragon and Goblin with unique attack logic
- **Room** — Represents dungeon rooms with connections, navigation, and healing mechanics
- **Game** — Central manager; handles the game loop, room navigation, battles, and memory cleanup

## Key Concepts
- **Polymorphism** — Dynamic method calls through base class pointers for flexible player/monster interactions
- **Inheritance** — Hierarchical class structure extending Entity into specialized subclasses
- **Operator Overloading** — Custom operators for health management and attribute comparisons
- **Dynamic Memory Management** — Responsible allocation and deallocation via destructors and `end_game` method

## Configuration File
Reads an external file to set up rooms, monsters, and gameplay elements for flexible dungeon layouts.
