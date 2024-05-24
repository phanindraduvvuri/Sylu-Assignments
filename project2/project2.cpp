#include <string>
#include <iostream>

#include "character.cpp"

using namespace std;

int main()
{

    // Read input from user
    string name, role;
    int hitPoints, attachBonus, damageBonus, armorClass;

    cout << "First character name?" << endl;
    cin >> name;

    cout << name << "'s role?" << endl;
    cin >> role;

    cout << name << " the " << role << "'s hit points?" << endl;
    cin >> hitPoints;

    cout << name << " the " << role << "'s attack bonus?" << endl;
    cin >> attachBonus;

    cout << name << " the " << role << "'s damage bonus?" << endl;
    cin >> damageBonus;

    cout << name << " the " << role << "'s armor class" << endl;
    cin >> armorClass;

    Character char1(name, role, hitPoints, attachBonus, damageBonus, armorClass);

    char1.print(cout);

    // --------------- second character -------------------------------//

    cout << "Second character name?" << endl;
    cin >> name;

    cout << name << "'s role?" << endl;
    cin >> role;

    cout << name << " the " << role << "'s hit points?" << endl;
    cin >> hitPoints;

    cout << name << " the " << role << "'s attack bonus?" << endl;
    cin >> attachBonus;

    cout << name << " the " << role << "'s damage bonus?" << endl;
    cin >> damageBonus;

    cout << name << " the " << role << "'s armor class" << endl;
    cin >> armorClass;

    Character char2(name, role, hitPoints, attachBonus, damageBonus, armorClass);

    char2.print(cout);

    bool currentAttackerFlag = true; // if true - char1 attacks, false - char2 attacks

    cout << "Simulated Combat: " << endl;
    while ((char1.getHealth() > 0) && (char2.getHealth() > 0))
    {
        if (currentAttackerFlag)
        {
            cout << char1.getName() << " attacks!" << endl;
            char1.attact(char2);
        }
        else
        {
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