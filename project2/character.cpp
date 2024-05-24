#include "character.h"

#include <iostream>

using namespace std;

int attackRoll, damageAmount;

int Character::getHealth() { return hitPoints; }

string Character::getName() { return name; }

string Character::getRole() { return role; }

void Character::damage(int amount)
{
    hitPoints = max(0, hitPoints - amount);
}

void Character::print(std::ostream &os)
{
    os << "Character summary\n"
       << "-----------------\n"
       << name << " the " << role << '\n'
       << "HP: " << hitPoints << '\n'
       << "AB: " << attachBonus << '\n'
       << "DB: " << damageBonus << '\n'
       << "AC: " << armorClass << "\n\n";
}

int rollDice(int sides)
{
    return (rand() % (20 - 1 + 1) + 1);
}

void Character::attact(Character &otherCharacter)
{

    // Roll 20-sided dice and add the attack bonus
    int randVal = rollDice(20);
    attackRoll = randVal + attachBonus;
    cout << "Attack roll: " << randVal << " + " << attachBonus << " = " << attackRoll << " ---> "
         << ((attackRoll >= otherCharacter.armorClass) ? "HIT!" : "MISS!") << endl;

    if (attackRoll >= otherCharacter.armorClass)
    {
        randVal = rollDice(10);
        damageAmount = randVal + damageBonus;
        otherCharacter.damage(damageAmount);

        cout << "Damage: " << randVal << " + " << damageBonus << " = "
             << damageAmount << endl;

        cout << otherCharacter.getName() << " has "
             << otherCharacter.getHealth() << " hit points remaining";
    }

    cout << "\n\n";
}
