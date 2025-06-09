#include "GradeMachine.h"
#include <iostream>
#include <cstdlib>
using namespace std;

void GradeMachine::play(double& gpa) {
    double bet;
    cout << "Welcome to the grade machine!\n";
    cout << "[ A+ | A+ | A+ ] = 50x\n";
    cout << "[ A  | A  | A  ] = 25x\n";
    cout << "[ A- | A- | A- ] = 20x\n";
    cout << "[ B  | B  | B  ] = 15x\n";
    cout << "[ C  | C  | C  ] = 10x\n";
    cout << "3 of a kind = 5x\n";
    cout << "Pair = 2x\n";

    cout << "\n[Grade Machine] Enter bet: ";
    cin >> bet;
    if (bet > gpa || bet <= 0) {
        cout << "Invalid bet.\n";
        return;
    }

    const char* symbols[7] = { "A+", "A", "A-", "B", "C", "D", "F" };
    int a = rand() % 7;
    int b = rand() % 7;
    int c = rand() % 7;

    cout << "[ " << symbols[a] << " | " << symbols[b] << " | " << symbols[c] << " ]\n";

      if (a == 0 && b == 0 && c == 0) {
        cout << "JACKPOT! (50x)\n";
        gpa += bet * 50;
    } else if (a == 1 && b == 1 && c == 1) {
        cout << "BIG WIN! (25x)\n";
        gpa += bet * 25;
    } else if (a == 2 && b == 2 && c == 2) {
        cout << "WIN! (20x)\n";
        gpa += bet * 20;
    } else if (a == 3 && b == 3 && c == 3) {
        cout << "win! (15x)\n";
        gpa += bet * 15;
    } else if (a == 4 && b == 4 && c == 4) {
        cout << "win (10x)\n";
        gpa += bet * 10;
    } else if (a == b && b == c) {
        cout << "3 of a kind (5x)\n";
        gpa += bet * 5;
    } else if (a == b || b == c || a == c) {
        cout << "Pair (2x)\n";
        gpa += bet;
    } else {
        cout << "No matches, you suck.\n";
        gpa -= bet;
    }
}