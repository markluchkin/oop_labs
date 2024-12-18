#include "../include/GameController.hpp"

int main() {
    GameController<InputHandler, FieldRenderer> gameController;
    gameController.init();
    gameController.startGame();

    return 0;
}


