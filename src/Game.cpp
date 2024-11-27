#include "../include/Game.hpp"

// -----------------------GAMESTATE----------------------- //
GameState::GameState(int width, int height, std::vector<int> shipSizes){
    userField = std::make_shared<GameField>(width, height);
    enemyField = std::make_shared<GameField>(width, height);
    userShips = std::make_shared<ShipManager>(shipSizes);
    enemyShips = std::make_shared<ShipManager>(shipSizes);
}

std::shared_ptr<GameField> GameState::getUserField() const{
    return userField;
}
std::shared_ptr<GameField> GameState::getEnemyField() const{
    return enemyField;
}
std::shared_ptr<ShipManager> GameState::getUserShips() const{
    return userShips;
}
std::shared_ptr<ShipManager> GameState::getEnemyShips() const{
    return enemyShips;
}
std::shared_ptr<AbilityManager> GameState::getUserAbilityManager() const{
    return userAbilityManager;
}
int GameState::getRoundNumber() const {
    return roundNumber;
}
void GameState::incRoundNumber() {
    roundNumber++;
}

// -----------------------GAME----------------------- //

Game::Game() {
    userTurn = true;
    startNewGame();
}

void Game::startNewGame() {
    std::cout << "Добро пожаловать в Морской бой!\n";
    auto [width, height] = setupFieldAction();
    auto shipSizes = setupShipsAction(height, width);
    gameState = std::make_shared<GameState>(width, height, shipSizes);
    placeShipsAction();
    placeEnemyShipsAction();
}

std::vector<int> Game::setupShipsAction(int h, int w) {
    std::cout << "Выберите режим игры:\n";
    std::cout << "1. Стандартный набор кораблей\n";
    std::cout << "2. Ввести собственный набор кораблей\n";
    std::cout << "Введите 1 или 2: ";
    int choice;
    std::cin >> choice;
    std::vector<int> shipSizes;
    if (choice == 1){
        shipSizes = {4, 3, 3, 2, 2, 2, 1, 1, 1, 1};
    } else if (choice == 2){
        while (true){
            std::cout << "Введите длины кораблей через запятую (например: 4,3,3,2,2,1,1,1): ";
            std::string input;
            std::cin.ignore();
            std::getline(std::cin, input);
            try {
                shipSizes = parseShipsInput(input);
                int totalLenght = std::accumulate(shipSizes.begin(), shipSizes.end(), 0);
                if (totalLenght >= h * w){ // длина ширина поля
                    std::cout << "Слишком много кораблей! Общая длина кораблей превышает размер поля ("
                              << h * w << "). Попробуйте снова.\n" ;
                    continue;
                }
                break; // Корректный ввод
            } catch (const std::invalid_argument& err){
                std::cout << err.what() << " Попробуйте снова.\n";
            }
        }
    } else {
        std::cout << "Некорректный выбор. Используется стандартный набор кораблей.\n";
        shipSizes = {4, 3, 3, 2, 2, 2, 1, 1, 1, 1};
    }

    return shipSizes;
}

std::pair<int, int> Game::setupFieldAction() {
    int width, height;
    while (true){
        std::cout << "Введите размеры игрового поля (ширина и высота, два числа через пробел):";
        std::cin >> width >> height;
        if (width > 0 && height > 0){
            return {width, height};
        }
        std::cout << "Некорректные размеры. Попробуйте снова.\n";
    }
}

void Game::placeShipsAction() {
    auto userShips = gameState->getUserShips();
    for (int i = 0; i < userShips->getAllShips().size(); i++){
        int currShipSize = userShips->getShip(i)->getSize();
        while (true){
            std::cout << "Размещение корабля длиной " << currShipSize << ". Введите три числа через пробел: координаты (x, y)"
                                                                         " и ориентацию (0 - горизонтально, 1 - вертикально): ";
            int x, y, orientation;
            std::cin >> x >> y >> orientation;

            Orientation orient = orientation == 0 ? Orientation::Horizontal : Orientation::Vertical;

            try{
                gameState->getUserField()->placeShip(x, y, userShips->getShip(i), orient);
                break;

            } catch(PlaceShipError &err){
                std::cout << err.what() << std::endl;
                std::cout << "Попробуйте снова:\n";
            }
        }
    }
}

void Game::placeEnemyShipsAction() {
    auto enemyShips = gameState->getEnemyShips();
    for (int i = 0; i < enemyShips->getAllShips().size(); i++){
        int currShipSize = enemyShips->getShip(i)->getSize();
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

std::vector<int> Game::parseShipsInput(const std::string& input) {
    std::vector<int> shipSizes;
    std::stringstream ss(input);
    std::string item;
    while (std::getline(ss, item, ',')){
        try{
            int shipSize = std::stoi(item);
            if (shipSize <= 0){
                throw std::invalid_argument("Корабль не может быть нулевой или отрицательной длины.");
            }
            shipSizes.push_back(shipSize);
        } catch (...){
            throw std::invalid_argument("Некорректный ввод. Должны быть только положительные числа, разделённые запятыми.");
        }
    }
    return shipSizes;
}