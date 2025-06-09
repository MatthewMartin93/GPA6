#include <iostream>
#include <ctime>
#include "GameManager.h"

int main() {
    srand(static_cast<unsigned int>(time(0)));
    GameManager game;
    game.run();
    return 0;
}
