#include <iostream>
#include "game_of_life.h"

int main(){
    GameOfLife game(30,30,100);
    game.shuffle();
    game.applyRule();
    game.display();
    return 0;
}