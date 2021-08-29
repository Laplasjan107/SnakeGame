#include <iostream>
#include <queue>
#include <ncurses.h>
#include <set>

using namespace std;

//Liczba znaków zajmowanych na ekranie przez jedno pole.
#define EL_WIDTH 3

#define COLUMNS 20
#define ROWS 20

#define SNAKE_HEAD '@'
#define SNAKE_BODY 'o'

#define FOOD '*'

#define NUMBER_OF_DIRECTIONS 4

enum Direction {
    Up, Right, Down, Left
};

struct Coordinates {

    int x; // row
    int y; // column
     bool operator< ( const Coordinates &compared) const
    {
        if(x==compared.x) return y<compared.y;
        return x<compared.x;
    }
} typedef Coordinates;

struct Snake {
    Coordinates head;
    deque <Coordinates> body;
    Direction direction;
    int foodCounter;
} typedef Snake;

struct Food {
     set <Coordinates> foods;
} typedef Food;

struct Board {
    Snake snake;
    Food food;
    Coordinates size;
}typedef Board;


//prints how much snake has eaten
void print_food_counter(Snake * snake) {
    mvprintw(0, 0, "%*d", 2, snake->foodCounter);
}

//odpowiada za wyswietlanie każdego pojedynczego pola
//przyjmuje plansze oraz kolumne i wiersz w ktorych znajduje sie pole ktore nalezy zmienic
//aktualizuje rowniez licznik diamentow
void print_element(Board *board, Coordinates c, char k) {

    int y = (((LINES) - (board->size.y)) / 2) + c.y;
    int x = (((COLS) - (EL_WIDTH) * (board->size.x)) / 2) + EL_WIDTH * c.x;
    mvprintw(y, x, "%*c", EL_WIDTH, k);
}


void print_snake(Board *board,Snake snake) {
    print_element(board, snake.head, SNAKE_HEAD);
    for (auto a : snake.body) {
        print_element(board, a, SNAKE_BODY);
    }
}

void print_food(Board*board,Food food){
    for(auto a : food.foods){
        print_element(board,a,FOOD);
    }
}

void update_print_snake(Board *board) {

}

//wyswietla cala plansze na poczatku gry
//przyjmuje jako argument plansze
void print_board(Board *board) {
    for (int i = 0; i < board->size.x; i++) {
        print_element(board, (Coordinates) {i, -1}, '-');
        print_element(board, (Coordinates) {i, board->size.x}, '-');
    }

    for (int i = 0; i < board->size.y; i++) {
        print_element(board, (Coordinates) {-1, i}, '|');
        print_element(board, (Coordinates) {board->size.y, i}, '|');
    }

    print_element(board, (Coordinates) {-1, -1}, '+');
    print_element(board, (Coordinates) {-1, board->size.y}, '+');
    print_element(board, (Coordinates) {board->size.x, -1}, '+');
    print_element(board, (Coordinates) {board->size.x, board->size.y}, '+');

    print_snake(board,board->snake);
    print_food(board,board->food);
    refresh();
}


//rozblyskuje ekran po wygranej
void winning() {
    flash();
}

//Zczytuje ruch gracza i go zwraca
int read_move() {
    return getch();
}

//inicjuje interfejs TUI i wlacza wyswietlanie planszy na poczatku
void interface_ini(Board *board) {
    initscr();  //wlacza TUI
    noecho();
    curs_set(0);
    print_board(board);
    cbreak(); // wlacza czekanie
}

Snake *snake_ini(Coordinates boardSize) {
    Snake *snake = new Snake();
    snake->head = (Coordinates){rand() % boardSize.x, rand() % boardSize.y};
    snake->body = deque<Coordinates>();
    snake->direction = (Direction) (rand() % NUMBER_OF_DIRECTIONS);
    return snake;
};


Food *food_ini(Coordinates boardSize){
    Food *food = new Food();
    food->foods= set<Coordinates>();
    food->foods.insert((Coordinates){rand() % boardSize.x, rand() % boardSize.y});
    return food;
}


int main() {
    srand(time(0));
    Board board;
    board.size = (Coordinates) {ROWS, COLUMNS};
    board.snake = (*snake_ini(board.size));
    board.food= *food_ini(board.size);
    interface_ini(&board);
    read_move();
    endwin();
    // Wypisanie_planszy(&a);
    // Przekierowanie_ruchu(&a);
    // Zwalnianie_pamieci(&a);
}
