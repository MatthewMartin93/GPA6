#include "GameManager.h"
#include "GradeCards.h"
#include "GradeMachine.h"
#include "GradeWheel.h"
#include <iostream>

using namespace std;

GameManager::GameManager() {
    gpa = 4.0;
}

void GameManager::run() {
    while (true) {
        cout << "\n=== GPA 6 MAIN MENU ===\n";
        cout << "Balance: " << gpa << "\n";
        cout << "1. Grade Cards\n2. Grade Machine\n3. Grade Wheel\n4. Exit\nChoice: ";

        int choice;
        cin >> choice;

        if (choice == 1) GradeCards::play(gpa);
        else if (choice == 2) GradeMachine::play(gpa);
        else if (choice == 3) GradeWheel::play(gpa);
        else if (choice == 4) {
            cout << "dropout\n";
            break;
        } else {
            cout << "Pick a real option (-1 gpa).\n";
            gpa -= 1;
        }

        if (gpa <= 0) {
            cout << "You're out of GPA. You get kicked out for being too dumb.\n";
            break;
        }
    }
}