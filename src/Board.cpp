//
// Created by Zofia Salata on 01/09/2021.
//

#include "Board.h"


void Board::print() {
    for (int i = 0; i < size.x; i++) {
        print_element( Coordinates(i, -1), '-');
        print_element( Coordinates(i, size.x), '-');
    }

    for (int i = 0; i < size.y; i++) {
        print_element( Coordinates(-1, i), '|');
        print_element(Coordinates(size.y, i), '|');
    }

    print_element( Coordinates(-1, -1), '+');
    print_element( Coordinates(-1, size.y), '+');
    print_element( Coordinates(size.x, -1), '+');
    print_element( Coordinates(size.x, size.y), '+');

    snake.print(this);
    food.print(this);
    refresh();
}