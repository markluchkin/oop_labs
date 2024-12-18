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
        case StartCommand::NewGame: {
            int n = inputHandler->getShipsNum();
            auto sizes = inputHandler->getSizes(n);
            game->startNewGame(sizes);
            round();
            break;
        }
        case StartCommand::LoadGame:
            try {
                game->loadGame(inputHandler->getFileName());
                fieldRenderer->showField(game->getUserField(), true);
                fieldRenderer->showField(game->getEnemyField(), false);
                round();
            } catch (std::exception& err) {
                std::cout << "Cannot load from file: " << err.what() << std::endl;
            }
            break;
        default:
            std::cout << "Unknown command!" << std::endl;
    }
}

template <typename InputHandlerType, typename FieldRendererType>
void GameController<InputHandlerType, FieldRendererType>::executeCommand(Command cmd) {
    switch (cmd) {
        case Save:
            game->saveGame(inputHandler->getFileName());
            break;
        case Load:
            game->loadGame(inputHandler->getFileName());
            break;
        case Attack: {

            break;
        }
        case ShowField:
            fieldRenderer->showField(game->getUserField(), true);
            break;
        case Ability: {

            break;
        }
        default:
            std::cout << "Unknown command!" << std::endl;
    }
}

template class GameController<InputHandler, FieldRenderer>;