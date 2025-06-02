// --- main.cpp ---
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

void playBlackjack(int& balance) {
    int bet;
    cout << "\n[Blackjack] Enter bet: 
      $";
    cin >> bet;
    if (bet > balance || bet <= 0) {
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
        balance -= bet;
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
        balance += bet;
    } else if (dealerTotal == playerTotal) {
        cout << "Push.\n";
    } else {
        cout << "Dealer wins. You lose.\n";
        balance -= bet;
    }
}

void playSlots(int& balance) {
    int bet;
    cout << "\n[Slots] Enter bet: $";
    cin >> bet;
    if (bet > balance || bet <= 0) {
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
    if (a == b && b == c) {
        cout << "Jackpot!\n";
        balance += bet * 10;
    } else if (a == b || b == c || a == c) {
        cout << "Small win.\n";
        balance += bet;
    } else {
        cout << "No match. You lose.\n";
        balance -= bet;
    }
}

void playRoulette(int& balance) {
    int choice, bet;
    cout << "\n[Roulette] Bet on (0=Red, 1=Black): ";
    cin >> choice;
    cout << "Enter bet: $";
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
    int balance = 1000;

    while (true) {
        cout << "\n=== Casino ===\n";
        cout << "Balance: $" << balance << "\n";
        cout << "1. Blackjack\n2. Slots\n3. Roulette\n4. Exit\nChoice: ";

        int choice;
        cin >> choice;

        if (choice == 1) playBlackjack(balance);
        else if (choice == 2) playSlots(balance);
        else if (choice == 3) playRoulette(balance);
        else if (choice == 4) {
            cout << "Goodbye!\n";
            break;
        } else {
            cout << "Invalid choice.\n";
        }

        if (balance <= 0) {
            cout << "You're out of money. Game over.\n";
            break;
        }
    }

    return 0;
}
