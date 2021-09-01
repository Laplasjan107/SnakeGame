//
// Created by Zofia Salata on 01/09/2021.
//

#ifndef SNAKEGAME_GAME_H
#define SNAKEGAME_GAME_H

#include <iostream>
#include <queue>
#include <ncurses.h>
#include <set>
#include <chrono>
#include <thread>

#include "Board.h"
#include "Coordinates.h"
#include "Food.h"
#include "Snake.h"
#include "Direction.h"


#define COLUMNS 20
#define ROWS 20

class Game {
public:
    Board board;
    Snake snake;
    Food food;
    bool endOfTheGame;

    Game() : board(ROWS, COLUMNS), snake(Coordinates(ROWS, COLUMNS)), food(Coordinates(ROWS, COLUMNS)),
             endOfTheGame(false) {

    }



    /**
    * initiates TUI interface
    */
    void interface_ini();

    void play();

    //Zczytuje ruch gracza i go zwraca
    inline char read_move() {
        return getch();
    }

    void change_direction() {
        char mv = read_move();
        if (mv == snake.left) {
            snake.turn(turn_direction_left(snake.direction));
            return;
        } else if (mv == snake.right) {
            snake.turn(turn_direction_right(snake.direction));
            return;
        } else if (mv == ERR) {
            return;
        } else {
            endOfTheGame = true;
        }
    }

    inline void end() {
        endwin();
    }


};


#endif //SNAKEGAME_GAME_H
