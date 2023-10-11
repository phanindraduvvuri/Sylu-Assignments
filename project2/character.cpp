#include "character.h"

#include <iostream>

using namespace std;

int attack_roll, damage_amount;

int Character::getHealth() { return hit_points; }

string Character::getName() { return name; }

string Character::getRole() { return role; }

void Character::damage(int amount) {
    hit_points = max(0, hit_points - amount);
}

void Character::print(std::ostream &os) {
    os << "Character summary\n"
       << "-----------------\n"
       << name << " the " << role << '\n'
       << "HP: " << hit_points << '\n'
       << "AB: " << attack_bonus << '\n'
       << "DB: " << damage_bonus << '\n'
       << "AC: " << armor_class << "\n\n";
}

int rollDice(int sides) {
    return (rand() % (20 - 1 + 1) + 1);
}

void Character::attact(Character &otherCharacter) {

    // Roll 20-sided dice and add the attack bonus
    int rand_val = rollDice(20);
    attack_roll = rand_val + attack_bonus;
    cout << "Attack roll: " << rand_val << " + " << attack_bonus << " = " << attack_roll << " ---> "
         << ((attack_roll >= otherCharacter.armor_class) ? "HIT!" : "MISS!") << endl;


    if (attack_roll >= otherCharacter.armor_class) {
        rand_val = rollDice(10);
        damage_amount = rand_val + damage_bonus;
        otherCharacter.damage(damage_amount);

        cout << "Damage: " << rand_val << " + " << damage_bonus << " = " << damage_amount << endl;
        cout << otherCharacter.getName() << " has " << otherCharacter.getHealth() << " hit points remaining";
    }

    cout << "\n\n";
}

