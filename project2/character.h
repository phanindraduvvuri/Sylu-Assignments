#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <fstream>

class Character
{
    std::string name;
    std::string role;
    int hitPoints;
    int attachBonus;
    int damageBonus;
    int armorClass;

public:
    Character(std::string name, std::string role, int hitPoints, int attachBonus, int damageBonus, int armorClass)
    {
        Character::name = name;
        Character::role = role;
        Character::hitPoints = hitPoints;
        Character::attachBonus = attachBonus;
        Character::damageBonus = damageBonus;
        Character::armorClass = armorClass;
    };

    int getHealth();

    std::string getName();

    std::string getRole();

    void print(std::ostream &os);

    void damage(int amount);

    void attact(Character &otherCharacter);
};

#endif