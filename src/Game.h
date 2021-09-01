//
// Created by Zofia Salata on 01/09/2021.
//

#ifndef SNAKEGAME_GAME_H
#define SNAKEGAME_GAME_H

#include <iostream>
#include <queue>
#include <ncurses.h>
#include <set>
#include <chrono>
#include <thread>

#include "Board.h"
#include "Coordinates.h"
#include "Food.h"
#include "Snake.h"
#include "Direction.h"


#define COLUMNS 15
#define ROWS 15

#define ENDGAMEKEY 'x'

class Game {

    Board board;
    Snake snake;
    Food food;
    bool endOfTheGame;
    int level;

public:
    Game() : board(ROWS, COLUMNS), snake(Coordinates(ROWS, COLUMNS)), food(Coordinates(ROWS, COLUMNS)),
             endOfTheGame(false),level(1) {
    }



    /**
    * Initiates TUI interface.
    */
    void interface_ini();

    /**
     * Conducts the game, till the player looses.
     */
    void play();

    /**
     * Reads players move.
     * @return pressed key
     */
    inline char read_move() {
        return getch();
    }
    /**
     * Forwards the move to the snake.
     */
    void change_direction() {
        char mv = read_move();
        if (mv == snake.left) {
            snake.turn(turn_direction_left(snake.direction));
            return;
        } else if (mv == snake.right) {
            snake.turn(turn_direction_right(snake.direction));
            return;
        } else if (mv == ERR) {
            return;
        } else if (mv == ENDGAMEKEY) {
            endOfTheGame = true;
        }
    }

    /**
     * Ends the game
     */
    inline void end() {
        endwin();
    }

    void update_level(int eatenFood){
        if (eatenFood>level*5) {
            level++;
            print_level();
        }
    }

    /**
     * Prints the current level.
     */
    inline void print_level(){
        mvprintw(0, COLS-EL_WIDTH-1, "%*d", EL_WIDTH, level);
    }

    bool is_snake(Coordinates c){
       return  snake.is_snake(c);
    }

    bool is_wall(Coordinates c){
        return board.is_wall(c);
    }

    bool is_food(Coordinates c){
        return food.is_food(c);
    }

    void print_element(Coordinates c, char k){
        board.print_element(c,k);
    }

    void food_eaten(Coordinates c){
        food.eaten(this,c,board);
    }

};


#endif //SNAKEGAME_GAME_H
