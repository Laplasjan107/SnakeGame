//
// Created by Zofia Salata on 01/09/2021.
//

#ifndef SNAKEGAME_SNAKE_H
#define SNAKEGAME_SNAKE_H

#include <deque>
#include "Coordinates.h"
#include "Direction.h"


#define SNAKE_HEAD '@'
#define SNAKE_BODY 'o'

using namespace std;

class Board;


class Snake {

public:
    Coordinates head;
    deque <Coordinates> body;
    Direction direction;
    int foodCounter;
    const char left;
    const char right;

    // Zakładam, że wielkość planszy to minimum 3.
    Snake(Coordinates boardSize, char left = 'a', char right = 'd');

    void print(Board *board);

    void turn(Direction dir) {
        direction = dir;
    }

    void move(Board *board);

    void update_print(Board *board, Coordinates previousTail, Coordinates previousHead, bool hasEaten);

};

#endif //SNAKEGAME_SNAKE_H
