//
// Created by Zofia Salata on 01/09/2021.
//

#include "Direction.h"

Direction turn_direction_right(Direction current, int howManytimes) {
    if (!howManytimes)
        return current;
    switch (current) {
        case Up:
            return turn_direction_right(Right, howManytimes - 1);
        case Right:
            return turn_direction_right(Down, howManytimes - 1);
        case Down:
            return turn_direction_right(Left, howManytimes - 1);
        case Left:
            return turn_direction_right(Up, howManytimes - 1);
    }
}
Direction turn_direction_left(Direction current) {
    return turn_direction_right(current, 3);
}
