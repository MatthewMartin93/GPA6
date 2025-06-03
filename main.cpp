// --- main.cpp ---
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

void playBlackjack(double& gpa) {
    double bet;
    cout << "\n[Blackjack] Enter bet: ";
    cin >> bet;
    if (bet > gpa || bet <= 0) {
        cout << "Invalid bet.\n";
        return;
    }

    vector<int> playerCards;
    vector<int> dealerCards;
    int playerTotal = 0, dealerTotal = 0;

    // Initial deal
    for (int i = 0; i < 2; ++i) {
        int card = rand() % 10 + 1;
        playerCards.push_back(card);
        playerTotal += card;
    }

    for (int i = 0; i < 2; ++i) {
        int card = rand() % 10 + 1;
        dealerCards.push_back(card);
        dealerTotal += card;
    }

    cout << "Your cards: ";
    for (int c : playerCards) cout << c << " ";
    cout << "= " << playerTotal << "\n";

    // Player turn
    while (playerTotal < 21) {
        cout << "Hit or stand? (h/s): ";
        char move;
        cin >> move;
        if (move == 's') break;
        int card = rand() % 10 + 1;
        playerCards.push_back(card);
        playerTotal += card;
        cout << "You drew: " << card << ". Total: " << playerTotal << "\n";
    }

    if (playerTotal > 21) {
        cout << "You busted!\n";
        gpa -= bet;
        return;
    }

    // Dealer turn
    cout << "Dealer's cards: ";
    for (int c : dealerCards) cout << c << " ";
    cout << "= " << dealerTotal << "\n";
    while (dealerTotal < 17) {
        int card = rand() % 10 + 1;
        dealerCards.push_back(card);
        dealerTotal += card;
        cout << "Dealer draws: " << card << ". Total: " << dealerTotal << "\n";
    }

    // Outcome
    if (dealerTotal > 21 || playerTotal > dealerTotal) {
        cout << "You win!\n";
        gpa += bet;
    } else if (dealerTotal == playerTotal) {
        cout << "Push.\n";
    } else {
        cout << "Dealer wins. You lose.\n";
        gpa -= bet;
    }
}

void playGradeMachine(double& gpa) {
    double bet;
    cout << "Welcome to the grade machine!" << endl;
    cout << "[ A+ | A+ | A+ ] = 50x" << endl;
    cout << "[ A  | A  | A  ] = 25x" << endl;
    cout << "[ A- | A- | A- ] = 20x" << endl;
    cout << "[ B  | B  | B  ] = 15x" << endl;
    cout << "[ C  | C  | C  ] = 10x" << endl;
    cout << "3 of a kind = 5x" << endl;
    cout << "Pair = 2x" << endl;

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
//A+A+A+ 50
//A A A 25
//A-A-A- 20
//B B B 15
//C C C 10
//3OAK 5
//PAIR 2
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

void playRoulette(double& balance) {
    double choice, bet;
    cout << "\n[Roulette] Bet on (0=Red, 1=Black): ";
    cin >> choice;
    cout << "Enter bet: ";
    cin >> bet;

    if (bet > balance || bet <= 0 || (choice != 0 && choice != 1)) {
        cout << "Invalid bet.\n";
        return;
    }

    int spin = rand() % 2;
    cout << "Wheel landed on: " << (spin == 0 ? "Red" : "Black") << "\n";

    if (spin == choice) {
        cout << "You win!\n";
        balance += bet;
    } else {
        cout << "You lose!\n";
        balance -= bet;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    double gpa = 4.0;

    while (true) {
        cout << "\n=== Casino ===\n";
        cout << "Balance: " << gpa << "\n";
        cout << "1. Blackjack\n2. Grade Machine\n3. Roulette\n4. Exit\nChoice: ";

        int choice;
        cin >> choice;

        if (choice == 1) playBlackjack(gpa);
        else if (choice == 2) playGradeMachine(gpa);
        else if (choice == 3) playRoulette(gpa);
        else if (choice == 4) {
            cout << "Goodbye!\n";
            break;
        } else {
            cout << "Invalid choice.\n";
        }

        if (gpa <= 0) {
            cout << "You're out of GPA. You get kicked out for being too dumb.\n";
            break;
        }
    }

    return 0;
}
