#include "GradeCards.h"
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void GradeCards::play(double& gpa) {
    double bet;
    cout << "\n[Grade Cards] Enter bet: ";
    cin >> bet;
    if (bet > gpa || bet <= 0) {
        cout << "Invalid bet.\n";
        return;
    }

    vector<int> playerCards;
    vector<int> dealerCards;
    int playerTotal = 0, dealerTotal = 0;

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

    cout << "Dealer's cards: ";
    for (int c : dealerCards) cout << c << " ";
    cout << "= " << dealerTotal << "\n";
    while (dealerTotal < 17) {
        int card = rand() % 10 + 1;
        dealerCards.push_back(card);
        dealerTotal += card;
        cout << "Dealer draws: " << card << ". Total: " << dealerTotal << "\n";
    }

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