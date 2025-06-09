#include "GradeWheel.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

vector<int> GradeWheelRed = {1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};
vector<int> GradeWheelBlack = {2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35};

void GradeWheel::play(double& gpa) {
    int choiceColor;
    double bet;

    cout << "\n[Grade Wheel - School Roulette]\n";
    cout << "Bet on a color:\n  0 = Red\n  1 = Black\n  2 = Green (0)\nYour choice: ";
    cin >> choiceColor;

    cout << "Enter your bet amount: ";
    cin >> bet;

    if (bet <= 0 || bet > gpa || (choiceColor < 0 || choiceColor > 2)) {
        cout << "Invalid choice or bet amount.\n";
        return;
    }

    int spin = rand() % 37;
    cout << "Wheel spins... landed on: " << spin;

    if (spin == 0) {
        cout << " (Green)\n";
        if (choiceColor == 2) {
            cout << "Jackpot! You win 14x your bet!\n";
            gpa += bet * 14;
        } else {
            cout << "You lose!\n";
            gpa -= bet;
        }
        return;
    }

    bool isRed = (find(GradeWheelRed.begin(), GradeWheelRed.end(), spin) != GradeWheelRed.end());
    cout << (isRed ? " (Red)\n" : " (Black)\n");

    if ((isRed && choiceColor == 0) || (!isRed && choiceColor == 1)) {
        cout << "You win!\n";
        gpa += bet;
    } else {
        cout << "You lose!\n";
        gpa -= bet;
    }
}