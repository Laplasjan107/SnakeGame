#include <iostream>
#include <queue>
#include <ncurses.h>



#include "Game.h"

using namespace std;




int main() {
    srand(time(0));
    Game game= Game();
    game.interface_ini();
    game.play();
    game.end();

    // Wypisanie_planszy(&a);
    // Przekierowanie_ruchu(&a);
    // Zwalnianie_pamieci(&a);
}
