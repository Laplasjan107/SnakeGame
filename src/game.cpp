#include <iostream>
#include <queue>
#include <ncurses.h>
#include <set>
#include <chrono>
#include <thread>


#include "Food.h"
#include "Snake.h"
#include "Board.h"
#include "Direction.h"
#include "Coordinates.h"

using namespace std;


#define COLUMNS 20
#define ROWS 20


bool endOfTheGame = false;

//prints how much snake has eaten
void print_food_counter(Snake &snake) {
    mvprintw(0, 0, "%*d", 2, snake.foodCounter);
}


//rozblyskuje ekran po wygranej
void winning() {
    flash();
}

//Zczytuje ruch gracza i go zwraca
inline char read_move() {
    return getch();
}

//
void change_direction(Snake &snake) {
    char mv = read_move();
    if (mv == snake.left) {
        snake.turn(turn_direction_left(snake.direction));
        return;
    } else if (mv == snake.right) {
        snake.turn(turn_direction_right(snake.direction));
        return;
    } else if (mv == ERR) {
        return;
    } else {
        endOfTheGame = true;
    }
}


void game(Board &board) {
    while (!endOfTheGame) {
        this_thread::sleep_for(std::chrono::seconds(1));
        change_direction(board.snake);
        board.snake.move(&board);
        refresh();
    }

}

//inicjuje interfejs TUI i wlacza wyswietlanie planszy na poczatku
void interface_ini(Board &board) {

    initscr();  //wlacza TUI
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    board.print();
    cbreak(); // wlacza czekanie
}


int main() {
    srand(time(0));
    Board board(ROWS, COLUMNS);
    interface_ini(board);
    game(board);
    endwin();

    // Wypisanie_planszy(&a);
    // Przekierowanie_ruchu(&a);
    // Zwalnianie_pamieci(&a);
}
