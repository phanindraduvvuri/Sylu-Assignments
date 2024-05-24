#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <fstream>
#include <utility>

class Character {
    std::string name;
    std::string role;
    int hitPoints;
    int attackBonus;
    int damageBonus;
    int armorClass;


public:
    Character(std::string name, std::string role, int points, int bonus, int damageBonus, int aClass) {
        Character::name = std::move(name);
        Character::role = std::move(role);
        Character::hitPoints = points;
        Character::attackBonus = bonus;
        Character::damageBonus = damageBonus;
        Character::armorClass = aClass;
    };

    int getHealth() const;

    std::string getName();

    std::string getRole();

    void print(std::ostream &os);

    void damage(int amount);

    void attack(Character &otherCharacter) const;
};


#endif