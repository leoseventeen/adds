#include "Human.h"
#include "Computer.h"
#include "Referee.h"
#include <iostream>

int main() {
    Human humanPlayer("Mei");
    Computer computerPlayer;
    Referee ref;

    Player* winner = ref.refGame(&humanPlayer, &computerPlayer);

    if (winner == nullptr)
        std::cout << "It's a Tie\n";
    else
        std::cout << winner->getName() << " Wins\n";

    return 0;
}
