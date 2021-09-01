//
// Created by Zofia Salata on 01/09/2021.
//

#include "Snake.h"
#include "Board.h"

void Snake::print(Board &board) {
    board.print_element( head, SNAKE_HEAD);
    for (auto el : body) {
        board.print_element( el, SNAKE_BODY);
    }
    print_food_counter();
}

bool Snake::move(Board &board, Food& food) {
    bool hasEaten = false;

    Coordinates previousHead = head;
    Coordinates previousTail;
    head = head.move_to_direction(direction);
    if (board.is_wall(head) || is_snake(head))
        return false;

    body.push_front(previousHead);
    tail.insert(previousHead);
    previousTail = body.back();

    if (food.is_food(head)) {
        foodCounter++;
        hasEaten = true;
        print_food_counter();
        food.eaten(head,board);
    } else {
        tail.erase(body.back());
        body.pop_back();
    }

    update_print(board, previousTail, previousHead, hasEaten);
    return true;
}

void Snake::update_print(Board &board, Coordinates previousTail, Coordinates previousHead, bool hasEaten) {
    board.print_element( previousHead, SNAKE_BODY);
    board.print_element( head, SNAKE_HEAD);

    if (!hasEaten) {
        board.print_element( previousTail, ' ');
    }
}

Snake::Snake(Coordinates boardSize, char left, char right ) :
        head(1 + rand() % (boardSize.x - 2),1 + rand() % (boardSize.y - 2)), foodCounter(0),left(left),
        right(right) {
    tail = set<Coordinates>();
    head = Coordinates(rand() % boardSize.x, rand() % boardSize.y);
    body = deque<Coordinates>();
    direction = (Direction) (rand() % NUMBER_OF_DIRECTIONS);
    Coordinates neck;
    switch (direction) {
        case Up:
            neck = Coordinates(head.x, head.y - 1);
            break;
        case Right:
            neck = Coordinates(head.x + 1, head.y);
            break;
        case Down:
            neck = Coordinates(head.x, head.y + 1);
            break;
        case Left:
            neck = Coordinates(head.x - 1, head.y);
            break;
    }
    body.push_front(neck);
    tail.insert(neck);
}