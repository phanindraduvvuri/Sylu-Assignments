#include <string>
#include <iostream>

#include "character.cpp"

using namespace std;


int main() {

    // Read input from user
    string name, role;
    int hit_points, attack_bonus, damage_bonus, armor_class;

    cout << "First character name?" << endl;
    cin >> name;

    cout << name << "'s role?" << endl;
    cin >> role;

    cout << name << " the " << role << "'s hit points?" << endl;
    cin >> hit_points;

    cout << name << " the " << role << "'s attack bonus?" << endl;
    cin >> attack_bonus;

    cout << name << " the " << role << "'s damage bonus?" << endl;
    cin >> damage_bonus;

    cout << name << " the " << role << "'s armor class" << endl;
    cin >> armor_class;

    Character char1(name, role, hit_points, attack_bonus, damage_bonus, armor_class);

    char1.print(cout);

    // --------------- second character -------------------------------//

    cout << "Second character name?" << endl;
    cin >> name;

    cout << name << "'s role?" << endl;
    cin >> role;

    cout << name << " the " << role << "'s hit points?" << endl;
    cin >> hit_points;

    cout << name << " the " << role << "'s attack bonus?" << endl;
    cin >> attack_bonus;

    cout << name << " the " << role << "'s damage bonus?" << endl;
    cin >> damage_bonus;

    cout << name << " the " << role << "'s armor class" << endl;
    cin >> armor_class;

    Character char2(name, role, hit_points, attack_bonus, damage_bonus, armor_class);

    char2.print(cout);

    bool currentAttackerFlag = true;  // if true - char1 attacks, false - char2 attacks

    cout << "Simulated Combat: " << endl;
    while ((char1.getHealth() > 0) && (char2.getHealth() > 0)) {
        if (currentAttackerFlag) {
            cout << char1.getName() << " attacks!" << endl;
            char1.attact(char2);
        } else {
            cout << char2.getName() << " attacks!" << endl;
            char2.attact(char1);
        }

        currentAttackerFlag = !currentAttackerFlag;
    }

    if (char1.getHealth() == 0)
        cout << char2.getName() << " wins!" << endl;
    else if (char2.getHealth() == 0)
        cout << char1.getName() << " wins!" << endl;

    return 0;
}