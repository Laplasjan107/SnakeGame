//
// Created by Zofia Salata on 01/09/2021.
//

#ifndef SNAKEGAME_SNAKE_H
#define SNAKEGAME_SNAKE_H

#include <deque>
#include <set>
#include <stdlib.h>


#include "Coordinates.h"
#include "Direction.h"
#include "Board.h"
#include "Food.h"


#define SNAKE_HEAD '@'
#define SNAKE_BODY 'o'

using namespace std;


class Snake {
private:
    set<Coordinates> tail;
    Coordinates head;
    deque <Coordinates> body;
    const char left;
    const char right;
public:
    Direction direction;
    int foodCounter;


    /**
     * boardSize is at least 3
     * @param boardSize
     * @param left
     * @param right
     */
    Snake(Coordinates boardSize, char left = 'a', char right = 'd');

    /**
     *
     * @param board
     */
    void print(Board &board);

    void turn(Direction dir) {
        direction = dir;
    }

    bool move(Game * game);

    void update_print(Game *game, Coordinates previousTail, Coordinates previousHead, bool hasEaten);

    //prints how much snake has eaten
    void print_food_counter() {
        mvprintw(0, 0, "%*d", 2, foodCounter);
    }

    inline bool is_snake(Coordinates c) {
        return tail.find(c) != tail.end();
    }

    char getterLeft(){
        return left;
    }
    char getterRight(){
        return right;
    }
};

#endif //SNAKEGAME_SNAKE_H
