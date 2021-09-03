//
// Created by Zofia Salata on 01/09/2021.
//

#ifndef SNAKEGAME_DIRECTION_H
#define SNAKEGAME_DIRECTION_H

#define NUMBER_OF_DIRECTIONS 4

enum Direction {
    Up, Right, Down, Left
};
/**
 * Counts the direction,which will be a result of
 * howManytimes turns to the right from position current.
 * @param current
 * @param howManytimes
 * @return new Direction
 */
Direction turn_direction_right(Direction current, int howManytimes = 1) ;

Direction turn_direction_left(Direction current) ;


#endif //SNAKEGAME_DIRECTION_H
