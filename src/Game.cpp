#include "../include/Game.hpp"

Game::Game() : userTurn(true), isUserGameOver(false), isEnemyGameOver(false){}

void Game::startNewGame() {
    std::cout << "Добро пожаловать в Морской бой!\n";
    auto [width, height] = setupFieldAction();
    auto shipSizes = setupShipsAction(height, width);
    gameState = std::make_shared<GameState>(width, height, shipSizes);
    placeShipsAction();
    placeEnemyShipsAction();

    while (true){
        checkVictory();
        if (isUserGameOver){
            break;
        }
        if (isEnemyGameOver){
            gameState->resetEnemyState();
            placeEnemyShipsAction();
            gameState->incRoundNumber();
            userTurn = true;
        }
        playTurn();

    }

    int choice;
    std::cout << "Вы проиграли. Хотите начать новую игру? (1 - да, 0 - нет)\n";
    std::cin >> choice;
    if (choice == 1){
        startNewGame();
    } else if (choice != 0 && choice != 1){
        std::cout << "Неккоректный ввод. Игра завершена.\n";
    } else{
        std::cout << "Игра завершена\n";
    }
}

void Game::playTurn() {
    if (userTurn){
        while (true){
            std::string filename;
            std::cout << "\n";
            std::cout << "1 - сохранить игру\n";
            std::cout << "2 - загрузить игру\n";
            std::cout << "3 - продолжить игру:\n";
            std::cout << "Выберите действие: ";
            int choice;
            std::cin >> choice;
            if (choice == 1){
                std::cout << "Введите название файла для сохранения: ";
                std::cin >> filename;
                saveGame(filename);
                break;
            } else if (choice == 2){
                std::cout << "Введите название файла для загрузки: ";
                std::cin >> filename;
                loadGame(filename);
                break;
            } else if (choice == 3){
                break;
            } else {
                std::cout << "Неккоректный ввод. Попробуйте снова.\n";
            }
        }
        printRoundInfo();
        userTurnAction();
    } else {
        enemyTurnAction();
    }

    userTurn = !userTurn;
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
            std::cout << "Введите длины кораблей через пробел (например: 4 3 3 2 2 2 1 1 1): ";
            std::string input;
            std::cin.ignore();
            std::getline(std::cin, input);
            try {
                shipSizes = parseShipsInput(input);
                int totalLenght = std::accumulate(shipSizes.begin(), shipSizes.end(), 0);
                if (totalLenght >= h * w - 1){ // длина ширина поля
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
        if (h * w > 60){
            std::cout << "Некорректный выбор. Используется стандартный набор кораблей.\n";
            shipSizes = {4, 3, 3, 2, 2, 2, 1, 1, 1, 1};
        } else {
            std::cout << "Размер поля слишком маленький для стандартного набора кораблей. Введите цифру 2.\n";
            setupShipsAction(h, w);
        }
    }

    return shipSizes;
}

std::pair<int, int> Game::setupFieldAction() {
    int width, height;
    while (true){
        std::cout << "Введите размеры игрового поля (ширина и высота, два числа через пробел, большие единицы):";
        std::cin >> width >> height;
        if (width > 1 && height > 1){
            return {width, height};
        }
        std::cout << "Некорректные размеры. Попробуйте снова.\n";
    }
}

void Game::placeShipsAction() {
    auto userShips = gameState->getUserShips();
    for (int i = 0; i < static_cast<int>(userShips->getAllShips().size()); i++){
        int currShipSize = userShips->getShip(i)->getSize();
        while (true){
            std::cout << "Размещение корабля длиной " << currShipSize << ". Введите три числа через пробел: координаты (x, y)"
                                                                         " и ориентацию (0 - горизонтально, 1 - вертикально): ";
            int x, y, orientation;
            std::cin >> x >> y >> orientation;
            if (orientation < 0 || orientation > 1){
                std::cout << "Ориентация может быть только 1 или 0! Попробуйте снова:\n";
                continue;
            }
            Orientation orient = orientation == 0 ? Orientation::Horizontal : Orientation::Vertical;

            try{
                gameState->getUserField()->placeShip(x, y, userShips->getShip(i), orient);
                gameState->getUserField()->printField(false);
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

void Game::userTurnAction() {
    while(true){
        if (gameState->getUserAbilityManager()->isEmpty()){
            //
            // std::cout << "У вас нет способностей.\n";
            break;
        }
        int abilityChoice;
        std::cout << "Использовать способность? (1 - да, 0 - нет): ";
        std::cin >> abilityChoice;
        if (abilityChoice == 1){
            AbilityType abilityType = gameState->getUserAbilityManager()->getFrontAbilityType();
            auto enemyField = gameState->getEnemyField();
            if (abilityType == AbilityType::Scan){
                int x, y;
                std::cout << "Введите координаты через пробел для сканирования области(x y): ";
                std::cin >> x >> y;
                gameState->getUserAbilityManager()->useAbility(enemyField, x, y);
            } else{
                gameState->getUserAbilityManager()->useAbility(enemyField);
            }
            break;
        } else if (abilityChoice == 0){
            break;
        } else {
            std::cout << "Неккоректный ввод, попробуйте снова. \n";
        }
    }
    userAttackAction();
}

void Game::enemyTurnAction() {
    enemyAttackAction();
}

void Game::userAttackAction() {
    std::cout << "Выполнение атаки.\n";
    while (true){
        int x, y;
        std::cout << "Введите координаты через пробел для атаки (x y): ";
        std::cin >> x >> y;
        try {
            bool isShipDestroyed  = gameState->getEnemyField()->attackCell(x, y);
            CellState cellState = gameState->getEnemyField()->getStateAt(x, y);

            if (cellState == CellState::Empty){
                std::cout << "Мимо!\n";
            } else if (cellState == CellState::ContainsShip){
                if (isShipDestroyed){
                    std::cout << "Корабль противника уничтожен!\n";
                    gameState->getUserAbilityManager()->addRandomAbility();
                    gameState->incDestroyedEnemyShipsNum();
                } else{
                    std::cout << "Попадание!\n";
                }
            }
            break;
        } catch (const AttackError& err){
            std::cout << err.what() << "Попробуйте снова.\n";
        }
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
                std::cout << "Противник атаковал (" << x << ", " << y << ") - мимо!\n";
            } else if (cellState == CellState::ContainsShip){
                if (isShipDestroyed){
                    std::cout << "Противник атаковал (" << x << ", " << y << ") - ваш корабль уничтожен!\n";
                    gameState->incDestroyedUserShipsNum();
                } else{
                    std::cout << "Противник атакifовал (" << x << ", " << y << ") - попадание!\n";
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
        std::cout << "\n--Вы победили в этом раунде!\n";
        isEnemyGameOver = true;
    }
    if (gameState->getDestroyedUserShipsNum() == gameState->getShipsNum()){
        std::cout << "\n--Вы проиграли в этом раунде!\n";
        isUserGameOver = true;
    }
}

void Game::printRoundInfo() {
    std::cout << "\n==========================================\n";
    std::cout << "-Раунд номер " << gameState->getRoundNumber() << "\n";
    std::cout << "-Текущий ход: " << (userTurn ? "Ваш" : "Противника") << "\n";
    gameState->getUserField()->printField(false);
    gameState->getEnemyField()->printField(true);
}

std::vector<int> Game::parseShipsInput(const std::string& input) {
    std::vector<int> shipSizes;
    std::stringstream ss(input);
    std::string item;
    while (std::getline(ss, item, ' ')){
        try{
            int shipSize = std::stoi(item);
            if (shipSize <= 0){
                throw std::invalid_argument("Корабль не может быть нулевой или отрицательной длины.");
            }
            shipSizes.push_back(shipSize);
        } catch (...){
            throw std::invalid_argument("Некорректный ввод. Должны быть только положительные числа через пробел.");
        }
    }
    return shipSizes;
}

void Game::saveGame(const std::string &filename) {
    try {
        gameState->save(filename);
        std::cout << "Игра сохранена в " << filename << std::endl;
    } catch (GameError& err) {
        std::cerr << "Ошибка при сохранении игры: " << err.what() << std::endl;
    }
}

void Game::loadGame(const std::string &filename) {
    try {
        gameState->load(filename);
        std::cout << "Игра загружена из " << filename << std::endl;
    } catch (GameError& err) {
        std::cerr << "Ошибка при загрузке игры: " << err.what() << std::endl;
    }
}