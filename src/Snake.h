//
// Created by Zofia Salata on 01/09/2021.
//

#ifndef SNAKEGAME_SNAKE_H
#define SNAKEGAME_SNAKE_H

#include <deque>
#include <set>

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
public:
    Coordinates head;
    deque <Coordinates> body;
    Direction direction;
    int foodCounter;
    const char left;
    const char right;

    // Zakładam, że wielkość planszy to minimum 3.
    Snake(Coordinates boardSize, char left = 'a', char right = 'd');

    void print(Board &board);

    void turn(Direction dir) {
        direction = dir;
    }

    bool move(Board &board, Food& food);

    void update_print(Board &board, Coordinates previousTail, Coordinates previousHead, bool hasEaten);

    //prints how much snake has eaten
    void print_food_counter() {
        mvprintw(0, 0, "%*d", 2, foodCounter);
    }

    inline bool is_snake(Coordinates c) {
        return tail.find(c) != tail.end();
    }
};

#endif //SNAKEGAME_SNAKE_H
