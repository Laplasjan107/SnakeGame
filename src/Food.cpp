//
// Created by Zofia Salata on 01/09/2021.
//

#include "Food.h"



void Food::print(Board &board) {
    for (auto el: foods) {
        board.print_element( el, FOOD);
    }
}