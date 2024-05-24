#include "character.h"

#include <iostream>

using namespace std;

int attackRoll;
int damageAmount;

int Character::getHealth() const { return hitPoints; }

string Character::getName() { return name; }

string Character::getRole() { return role; }

void Character::damage(int amount) {
    hitPoints = max(0, hitPoints - amount);
}

void Character::print(std::ostream &os) {
    os << "Character summary\n"
       << "-----------------\n"
       << name << " the " << role << '\n'
       << "HP: " << hitPoints << '\n'
       << "AB: " << attackBonus << '\n'
       << "DB: " << damageBonus << '\n'
       << "AC: " << armorClass << "\n\n";
}

int rollDice(int sides) {
    return (rand() % (20 - 1 + 1) + 1);
}

void Character::attack(Character &otherCharacter) const {

    // Roll 20-sided dice and add the attack bonus
    int rand_val = rollDice(20);
    attackRoll = rand_val + attackBonus;
    cout << "Attack roll: " << rand_val << " + " << attackBonus << " = " << attackRoll << " ---> "
         << ((attackRoll >= otherCharacter.armorClass) ? "HIT!" : "MISS!") << endl;


    if (attackRoll >= otherCharacter.armorClass) {
        rand_val = rollDice(10);
        damageAmount = rand_val + damageBonus;
        otherCharacter.damage(damageAmount);

        cout << "Damage: " << rand_val << " + " << damageBonus << " = " << damageAmount << endl;
        cout << otherCharacter.getName() << " has " << otherCharacter.getHealth() << " hit points remaining";
    }

    cout << "\n\n";
}
