//
// Created by Zofia Salata on 01/09/2021.
//

#ifndef SNAKEGAME_FOOD_H
#define SNAKEGAME_FOOD_H

#include <set>

#include "Coordinates.h"

#define FOOD '*'

using namespace std;

class Board;

class Food {
    set <Coordinates> foods;
public:
    Food(Coordinates boardSize) {
        foods = set<Coordinates>();
        foods.insert(Coordinates(rand() % boardSize.x, rand() % boardSize.y));
    }

    void print(Board *board);

    bool isFood(Coordinates c) {
        return foods.find(c) != foods.end();
    }
};


#endif //SNAKEGAME_FOOD_H
