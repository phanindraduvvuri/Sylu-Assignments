#include <iostream>
#include <string>
#include <random>

using namespace std;

int roll_dice() {
    return rand() % 6 + 1;
}

int main() {

    // Asking user for the number of rolls
    cout << "How many rolls?  ";
    int rolls = 0;
    cin >> rolls;

    cout << endl
         << "Simulating " << rolls << " rolls..." << endl;

    srand(time(NULL));

    // Defining the output array
    int result[13] = {0};

    // Rolling 2 dices for number of times the user had entered
    for (int i = 0; i < rolls; i++) {
        int dice1 = roll_dice();
        int dice2 = roll_dice();

        result[dice1 + dice2]++;  // updating the output array after each roll
    }

    // Printing the output array in the desired format
    for (int i = 2; i <= 12; i++) {
        cout << i << " was rolled " << result[i] << " times" << endl;
    }

    return 0;
}
