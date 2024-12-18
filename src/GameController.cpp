#include "../include/GameController.hpp"

template <typename InputHandlerType, typename FieldRendererType>
void GameController<InputHandlerType, FieldRendererType>::init() {
    inputHandler->init();
}

template <typename InputHandlerType, typename FieldRendererType>
void GameController<InputHandlerType, FieldRendererType>::startGame() {
    std::cout << "============= Battleship =============" << std::endl;
    StartCommand cmd = inputHandler->getStartCommand();
    executeStartCommand(cmd);
}

template <typename InputHandlerType, typename FieldRendererType>
void GameController<InputHandlerType, FieldRendererType>::round() {
    bool end = false;
    while (!end) {
        Command cmd = inputHandler->getCommand();
        if (cmd == Exit) {
            end = true;
        }
        else {
            executeCommand(cmd);
        }
    }
}

template <typename InputHandlerType, typename FieldRendererType>
void GameController<InputHandlerType, FieldRendererType>::executeStartCommand(StartCommand cmd) {
    switch (cmd) {

        default:
            std::cout << "Unknown command!" << std::endl;
    }
}

template <typename InputHandlerType, typename FieldRendererType>
void GameController<InputHandlerType, FieldRendererType>::executeCommand(Command cmd) {
    switch (cmd) {

        default:
            std::cout << "Unknown command!" << std::endl;
    }
}

template class GameController<InputHandler, FieldRenderer>;