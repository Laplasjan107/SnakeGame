//
// Created by Zofia Salata on 01/09/2021.
//

#ifndef SNAKEGAME_FOOD_H
#define SNAKEGAME_FOOD_H

#include <set>
#include <stdlib.h>

#include "Coordinates.h"
#include "Board.h"


class Game;
#define FOOD '*'

using namespace std;

/**
 * Class of all the food on the board.
 */
class Food {
private:
    set <Coordinates> foods; ///< Set of food coordinates.
public:
    Food(Coordinates boardSize) {
        foods = set<Coordinates>();
        foods.insert(Coordinates(rand() % boardSize.x, rand() % boardSize.y));
    }

    /**
     * Prints the food.
     * @param board
     */
    void print(Board &board);

    /**
     * Checks if there is food under coordinates c.
     * @param c
     * @return
     */
    bool is_food(Coordinates c) {
        return foods.find(c) != foods.end();
    }

    /**
     * Updates food after eating one.
     * @param c coordinates of the eaten food.
     * @param board
     */
    void eaten(Game *game,Coordinates c,Board &board);

    /**
     * Updates the screen.
     * @param board
     * @param newFood
     */
    void update_print(Game *game,  Coordinates newFood);

    /**
     * Generates coordinates of new food.
     * @param boardSize
     * @return
     */
    Coordinates generate_new(Coordinates boardSize){
        return (Coordinates(rand() % boardSize.x, rand() % boardSize.y));
    }
};


#endif //SNAKEGAME_FOOD_H
