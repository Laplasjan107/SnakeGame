#include <iostream>
#include <queue>
#include <ncurses.h>
#include <set>
#include <chrono>
#include <thread>

using namespace std;

//Liczba znaków zajmowanych na ekranie przez jedno pole.
#define EL_WIDTH 2

#define COLUMNS 20
#define ROWS 20

#define SNAKE_HEAD '@'
#define SNAKE_BODY 'o'

#define FOOD '*'

#define NUMBER_OF_DIRECTIONS 4

bool endOfTheGame = false;


enum Direction {
    Up, Right, Down, Left
};

class Board;

class Coordinates;

void print_element(Board *board, Coordinates c, char k);

class Coordinates {
public:
    int x; // row
    int y; // column

    Coordinates() : x(0), y(0) {}

    Coordinates(int x, int y) : x(x), y(y) {}

    bool operator<(const Coordinates &compared) const {
        if (x == compared.x) return y < compared.y;
        return x < compared.x;
    }
} typedef Coordinates;

class Snake {
public:
    Coordinates head;
    deque <Coordinates> body;
    Direction direction;
    int foodCounter;
    const char left;
    const char right;

    // Zakładam, że wielkość planszy to minimum 3.
    Snake(Coordinates boardSize, char left = 'a', char right = 'd') : head(1 + rand() % (boardSize.x - 2),
                                                                           1 + rand() % (boardSize.y - 2)), left(left),
                                                                      right(right) {
        //head = Coordinates (rand() % boardSize.x, rand() % boardSize.y);
        body = deque<Coordinates>();
        direction = (Direction) (rand() % NUMBER_OF_DIRECTIONS);
        Coordinates neck;
        switch (direction) {
            case Up:
                neck = Coordinates(head.x, head.y - 1);
                break;
            case Right:
                neck = Coordinates(head.x - 1, head.y);
                break;
            case Down:
                neck = Coordinates(head.x, head.y + 1);
                break;
            case Left:
                neck = Coordinates(head.x + 1, head.y);
                break;
        }
        body.push_front(neck);
    }

    void print(Board *board) {
        print_element(board, head, SNAKE_HEAD);
        for (auto el : body) {
            print_element(board, el, SNAKE_BODY);
        }
    }
};

class Food {
public:
    set <Coordinates> foods;

    Food(Coordinates boardSize) {
        foods = set<Coordinates>();
        foods.insert(Coordinates(rand() % boardSize.x, rand() % boardSize.y));
    }

    void print(Board *board) {
        for (auto el: foods) {
            print_element(board, el, FOOD);
        }
    }
};

class Board {
public:
    Snake snake;
    Food food;
    Coordinates size;

    Board(int rows, int columns) : size(rows, columns), snake(Coordinates(rows, columns)),
                                   food(Coordinates(rows, columns)) {
    }

    //wyswietla cala plansze na poczatku gry
    //przyjmuje jako argument plansze
    void print() {
        for (int i = 0; i < size.x; i++) {
            print_element(this, Coordinates(i, -1), '-');
            print_element(this, Coordinates(i, size.x), '-');
        }

        for (int i = 0; i < size.y; i++) {
            print_element(this, Coordinates(-1, i), '|');
            print_element(this, Coordinates(size.y, i), '|');
        }

        print_element(this, Coordinates(-1, -1), '+');
        print_element(this, Coordinates(-1, size.y), '+');
        print_element(this, Coordinates(size.x, -1), '+');
        print_element(this, Coordinates(size.x, size.y), '+');

        snake.print(this);
        food.print(this);
        refresh();
    }
};


//prints how much snake has eaten
void print_food_counter(Snake &snake) {
    mvprintw(0, 0, "%*d", 2, snake.foodCounter);
}

//odpowiada za wyswietlanie każdego pojedynczego pola
//przyjmuje plansze oraz kolumne i wiersz w ktorych znajduje sie pole ktore nalezy zmienic
//aktualizuje rowniez licznik diamentow
void print_element(Board *board, Coordinates c, char k) {

    int y = (((LINES) - (board->size.y)) / 2) + c.y;
    int x = (((COLS) - (EL_WIDTH) * (board->size.x)) / 2) + EL_WIDTH * c.x;
    mvprintw(y, x, "%*c", EL_WIDTH, k);
}


void update_print_snake(Board *board) {

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
void change_direction(Snake snake) {
    char mv = read_move();
    if (mv == snake.left) {
        return;
    } else if (mv == snake.right) {
        return;
    } else {

        endOfTheGame = true;
    }
}

void move(Board &board) {

}


void game(Board &board) {
    while (!endOfTheGame) {

       this_thread::sleep_for(std::chrono::seconds(1));
        change_direction(board.snake);
    }

}

//inicjuje interfejs TUI i wlacza wyswietlanie planszy na poczatku
void interface_ini(Board *board) {

    initscr();  //wlacza TUI
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    board->print();
    cbreak(); // wlacza czekanie
}


int main() {
    srand(time(0));
    Board board(ROWS, COLUMNS);
    interface_ini(&board);
    game(board);
    endwin();

    // Wypisanie_planszy(&a);
    // Przekierowanie_ruchu(&a);
    // Zwalnianie_pamieci(&a);
}
