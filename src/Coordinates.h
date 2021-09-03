//
// Created by Zofia Salata on 01/09/2021.
//

#ifndef SNAKEGAME_COORDINATES_H
#define SNAKEGAME_COORDINATES_H

#include "Direction.h"

class Coordinates {
public:
    int x; ///< number of a row
    int y; ///< number of a column

    Coordinates() : x(0), y(0) {}

    Coordinates(int x, int y) : x(x), y(y) {}

    bool operator<(const Coordinates &compared) const {
        if (x == compared.x) return y < compared.y;
        return x < compared.x;
    }

    /**
     * Returns the new coordinations after move in the direction dir
     * @param dir : Direction
     * @return new Coordinations
     */
    Coordinates move_to_direction(Direction dir) {
        switch (dir) {
            case Up:
                return Coordinates(x, y + 1);
            case Right:
                return Coordinates(x - 1, y);
            case Down:
                return Coordinates(x, y - 1);
            case Left:
                return Coordinates(x + 1, y);
        }
    }
};



#endif //SNAKEGAME_COORDINATES_H
