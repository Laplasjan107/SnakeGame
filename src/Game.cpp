//
// Created by Zofia Salata on 01/09/2021.
//

#include "Game.h"


void Game::play() {
    while (!endOfTheGame) {
        this_thread::sleep_for(std::chrono::milliseconds(300));
        change_direction();
        endOfTheGame = !snake.move(board, food);
        refresh();
    }
    flash();
    this_thread::sleep_for(std::chrono::milliseconds(1000));
}


void Game::interface_ini() {
    initscr();  // Turns on TUI
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    board.print();
    snake.print(board);
    food.print(board);
    refresh();
    cbreak(); // Turns on waiting
}
