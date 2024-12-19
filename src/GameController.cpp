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
    bool res = false;
    while (!end) {
        Command cmd = inputHandler->getCommand();
        if (cmd == Exit) {
            end = true;
        }
        else {
            res = executeCommand(cmd);
        }

        if (res){
            int n = inputHandler->getShipsNum();
            auto sizes = inputHandler->getSizes(n);
            game->startNewGame(sizes);
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
bool GameController<InputHandlerType, FieldRendererType>::executeCommand(Command cmd) {
    switch (cmd) {
        case Save:
            game->saveGame(inputHandler->getFileName());
            break;
        case Load:
            game->loadGame(inputHandler->getFileName());
            break;
        case Attack: {
            while (true) {
                try {
                    int x = inputHandler->getX();
                    int y = inputHandler->getY();
                    game->userAttackAction(x, y);
                    break;
                } catch (AttackError &err) {
                    std::cout << err.what() << std::endl;
                    std::cout << "Try again. \n";
                }
            }
            game->enemyAttackAction();

            game->checkVictory();
            if (game->getIsEnemyGameOver()){
                std::cout << "You won in this round! Starting next...\n";
                game->resetEnemy();
                game->placeEnemyShipsAction();
                game->incRoundNumber();
            }
            if (game->getIsUserGameOver()){
                std::cout << "You lost in this round!\n";
                return true;
            }

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
    return false;
}

template class GameController<InputHandler, FieldRenderer>;