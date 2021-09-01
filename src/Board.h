//
// Created by Zofia Salata on 01/09/2021.
//

#ifndef SNAKEGAME_BOARD_H
#define SNAKEGAME_BOARD_H

#include <ncurses.h>

#include "Coordinates.h"
#include "Direction.h"

//Liczba znaków zajmowanych na ekranie przez jedno pole.
#define EL_WIDTH 2

class Board {
public:
    Coordinates size;

    Board(int rows, int columns) : size(rows, columns) {
    }

   /**
    * Prints the board.
    */
    void print();

    /**
     * Checks if c contains wall.
     * @param Coordinates c
     * @return c==wall
     */
    bool is_wall(Coordinates c) {
        return !(c.x >= 0 && c.x < size.x && c.y >= 0 && c.y < size.y);
    }

    /**
     * Prints k on the board in place of coordinates c.
     * @param Coordinates c
     * @param char k
     */
    void print_element( Coordinates c, char k) {
        int y = (((LINES) - (size.y)) / 2) + c.y;
        int x = (((COLS) - (EL_WIDTH) * (size.x)) / 2) + EL_WIDTH * c.x;
        mvprintw(y, x, "%*c", EL_WIDTH, k);
    }
};


#endif //SNAKEGAME_BOARD_H
