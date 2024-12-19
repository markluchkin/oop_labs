#include "../include/Game.hpp"

Game::Game() : isUserGameOver(false), isEnemyGameOver(false){}

void Game::startNewGame(std::vector<int> sizes) {
    auto [width, height] = setupFieldAction();
    gameState = std::make_shared<GameState>(width, height, sizes);
    placeShipsAction();
    placeEnemyShipsAction();
}

std::shared_ptr<GameField> Game::getUserField() const{
    return gameState->getUserField();
}
std::shared_ptr<GameField> Game::getEnemyField() const{
    return gameState->getEnemyField();
}

std::shared_ptr<AbilityManager> Game::getAbilityManager() {
    return gameState->getUserAbilityManager();
}

bool Game::getIsUserGameOver() const{
    return isUserGameOver;
}
bool Game::getIsEnemyGameOver() const{
    return isEnemyGameOver;
}

void Game::incRoundNumber() {
    gameState->incRoundNumber();
}

void Game::resetEnemy() {
    gameState->resetEnemyState();
}

std::pair<int, int> Game::setupFieldAction() {
    int width, height;
    while (true){
        std::cout << "Enter the dimensions of the game field (width and height, two numbers separated by a space):";
        std::cin >> width >> height;
        if (width > 1 && height > 1){
            return {width, height};
        }
        std::cout << "Incorrect dimensions. Try again.\n";
    }
}

void Game::placeShipsAction() {
    auto userShips = gameState->getUserShips();
    for (int i = 0; i < static_cast<int>(userShips->getAllShips().size()); i++){
        int currShipSize = userShips->getShip(i)->getSize();
        while (true){
            std::cout << "Placing a ship with size " << currShipSize << ". Enter three numbers separated by a space: coordinates (x, y)"
                                                                         " and orientation (0 - horizontal, 1 - vertical): ";
            int x, y, orientation;
            std::cin >> x >> y >> orientation;
            if (orientation < 0 || orientation > 1){
                std::cout << "Orientation can be only 1 or 0!Try again:\n";
                continue;
            }
            Orientation orient = orientation == 0 ? Orientation::Horizontal : Orientation::Vertical;

            try{
                gameState->getUserField()->placeShip(x, y, userShips->getShip(i), orient);
                gameState->getUserField()->printField();
                break;
            } catch(PlaceShipError &err){
                std::cout << err.what() << std::endl;
                std::cout << "Try again:\n";
            }
        }
    }
}

void Game::placeEnemyShipsAction() {
    auto enemyShips = gameState->getEnemyShips();
    for (int i = 0; i < static_cast<int>(enemyShips->getAllShips().size()); i++){
        while (true){
            int x = rand() % gameState->getEnemyField()->getWidth();
            int y = rand() % gameState->getEnemyField()->getHeight();
            int orientation = rand() % 2;

            Orientation orient = orientation == 0 ? Orientation::Horizontal : Orientation::Vertical;

            try{
                gameState->getEnemyField()->placeShip(x, y, enemyShips->getShip(i), orient);
                break;

            } catch(PlaceShipError &err){
                continue;
            }
        }
    }
}


void Game::userAttackAction(int x, int y) {
    std::cout << "Attack is processing.\n";
        try {
            bool isShipDestroyed  = gameState->getEnemyField()->attackCell(x, y);
            CellState cellState = gameState->getEnemyField()->getStateAt(x, y);

            if (cellState == CellState::Empty){
                std::cout << "You missed!\n";
            } else if (cellState == CellState::ContainsShip) {
                if (isShipDestroyed) {
                    std::cout << "The enemy ship was destroyed!\n";
                    gameState->getUserAbilityManager()->addRandomAbility();
                    gameState->incDestroyedEnemyShipsNum();
                } else {
                    std::cout << "You hitted!\n";
                }
            }
        } catch (const AttackError& err){
            throw AttackError(err.what());
        }

}

void Game::enemyAttackAction() {
    while (true){
        int x = rand() % gameState->getUserField()->getWidth();
        int y = rand() % gameState->getUserField()->getHeight();

        try {
            bool isShipDestroyed = gameState->getUserField()->attackCell(x, y);
            CellState cellState = gameState->getUserField()->getStateAt(x, y);
            if (cellState == CellState::Empty){
                std::cout << "The enemy attacked (" << x << ", " << y << ") - miss!\n";
            } else if (cellState == CellState::ContainsShip){
                if (isShipDestroyed){
                    std::cout << "The enemy attacked (" << x << ", " << y << ") - your ship is destroyed!\n";
                    gameState->incDestroyedUserShipsNum();
                } else{
                    std::cout << "The enemy attacked (" << x << ", " << y << ") - hit!\n";
                }
            }
            break;
        } catch (...){
            continue;
        }
    }
}

void Game::checkVictory() {
    if (gameState->getDestroyedEnemyShipsNum() == gameState->getShipsNum()) {
        isEnemyGameOver = true;
    }
    if (gameState->getDestroyedUserShipsNum() == gameState->getShipsNum()){
        isUserGameOver = true;
    }
}

void Game::printRoundInfo() {
    std::cout << "\n==========================================\n";
    std::cout << "-Round № " << gameState->getRoundNumber() << "\n";
    gameState->getUserField()->printField();
    gameState->getEnemyField()->printField();
}

void Game::saveGame(const std::string &filename) {
    try {
        gameState->save(filename);
        std::cout << "The game saved in " << filename << std::endl;
    } catch (GameError& err) {
        throw GameError(err.what());
    }
}

void Game::loadGame(const std::string &filename) {
    std::vector<int> a;
    gameState = std::make_shared<GameState>(0, 0, a);
    try {
        gameState->load(filename);
        std::cout << "The game loaded from " << filename << std::endl;
    } catch (GameError& err) {
        throw GameError(err.what());
    }
}