#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <fstream>

class Character {
    std::string name;
    std::string role;
    int hit_points;
    int attack_bonus;
    int damage_bonus;
    int armor_class;


public:
    Character(std::string name, std::string role, int hit_points, int attack_bonus, int damage_bonus, int armor_class) {
        Character::name = name;
        Character::role = role;
        Character::hit_points = hit_points;
        Character::attack_bonus = attack_bonus;
        Character::damage_bonus = damage_bonus;
        Character::armor_class = armor_class;
    };

    int getHealth();

    std::string getName();

    std::string getRole();

    void print(std::ostream &os);

    void damage(int amount);

    void attact(Character &otherCharacter);
};


#endif