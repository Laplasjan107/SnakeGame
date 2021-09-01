//
// Created by Zofia Salata on 01/09/2021.
//

#include "Game.h"


void Game::play() {
    while (!endOfTheGame) {
        this_thread::sleep_for(std::chrono::milliseconds(300-level*5));
        change_direction();
        if (!snake.move(board, food))
            endOfTheGame=true;
        update_level(snake.foodCounter);
        refresh();
    }
    flash();
    this_thread::sleep_for(std::chrono::milliseconds(1500));
}


void Game::interface_ini() {
    initscr();  // Turns on TUI
    noecho();  // Read keys won't be echoed
    curs_set(0);
    nodelay(stdscr, TRUE); //function getchar() won't wait for a press of a key
    board.print();
    snake.print(board);
    food.print(board);
    print_level();
    refresh();
    cbreak(); // Turns on waiting
}
