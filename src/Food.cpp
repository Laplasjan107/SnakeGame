//
// Created by Zofia Salata on 01/09/2021.
//

#include "Food.h"
#include "Game.h"



void Food::print(Board &board) {
    for (auto el: foods) {
        board.print_element( el, FOOD);
    }
}


void Food::eaten(Game *game, Coordinates eatenFood, Board &board){
    foods.erase(eatenFood);
    Coordinates newFood = generate_new(board.size);
    while(game->is_snake(newFood)){
        newFood = generate_new(board.size);
    }
    foods.insert(newFood);
    update_print(game,newFood);
}

void Food::update_print(Game *game,  Coordinates newFood){
    game->print_element(newFood,FOOD);
}