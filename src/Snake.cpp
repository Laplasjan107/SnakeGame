//
// Created by Zofia Salata on 01/09/2021.
//

#include "Snake.h"
#include "Game.h"


Snake::Snake(Coordinates boardSize, char left, char right) :
        head(1 + rand() % (boardSize.x - 2), 1 + rand() % (boardSize.y - 2)), foodCounter(0), left(left),
        right(right) {
    tail = set<Coordinates>();
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

void Snake::print(Board &board) {
    board.print_element(head, SNAKE_HEAD);
    for (auto el : body) {
        board.print_element(el, SNAKE_BODY);
    }
    print_food_counter();
}

bool Snake::move(Game* game) {
    bool hasEaten = false;

    Coordinates previousHead = head;
    Coordinates previousTail;
    head = head.move_to_direction(direction);
    if (game->is_wall(head) || game->is_snake(head))
        return false;

    body.push_front(previousHead);
    tail.insert(previousHead);
    previousTail = body.back();

    if (game->is_food(head)) {
        foodCounter++;
        hasEaten = true;
        print_food_counter();
        game->food_eaten(head);
    } else {
        tail.erase(body.back());
        body.pop_back();
    }

    update_print(game, previousTail, previousHead, hasEaten);
    return true;
}

void Snake::update_print(Game *game, Coordinates previousTail, Coordinates previousHead, bool hasEaten) {
    game->print_element(previousHead, SNAKE_BODY);
    game->print_element(head, SNAKE_HEAD);

    if (!hasEaten) {
        game->print_element(previousTail, ' ');
    }
}
