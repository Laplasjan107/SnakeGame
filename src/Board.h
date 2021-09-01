//
// Created by Zofia Salata on 01/09/2021.
//

#ifndef SNAKEGAME_BOARD_H
#define SNAKEGAME_BOARD_H

#include <ncurses.h>

#include "Coordinates.h"
#include "Snake.h"
#include "Food.h"
#include "Direction.h"

//Liczba znaków zajmowanych na ekranie przez jedno pole.
#define EL_WIDTH 2

class Board {
public:
    Snake snake;
    Food food;
    Coordinates size;

    Board(int rows, int columns) :  snake(Coordinates(rows, columns)),
                                   food(Coordinates(rows, columns)),size(rows, columns) {
    }

    //wyswietla cala plansze na poczatku gry
    //przyjmuje jako argument plansze
    void print();

    bool isFood(Coordinates c) {
        return food.isFood(c);
    }

    //odpowiada za wyswietlanie każdego pojedynczego pola
//przyjmuje plansze oraz kolumne i wiersz w ktorych znajduje sie pole ktore nalezy zmienic
//aktualizuje rowniez licznik diamentow
    void print_element( Coordinates c, char k) {
        int y = (((LINES) - (size.y)) / 2) + c.y;
        int x = (((COLS) - (EL_WIDTH) * (size.x)) / 2) + EL_WIDTH * c.x;
        mvprintw(y, x, "%*c", EL_WIDTH, k);
    }
};


#endif //SNAKEGAME_BOARD_H
