#include "../include/GameState.hpp"

GameState::GameState(int width, int height, std::vector<int> shipSizes)
        : fieldWidth(width), fieldHeight(height), sizes(shipSizes), roundNumber(1),
          destroyedUserShipsNum(0), destroyedEnemyShipsNum(0)
{
    shipsNum = static_cast<int>(shipSizes.size());
    userField = std::make_shared<GameField>(fieldWidth, fieldHeight);
    enemyField = std::make_shared<GameField>(fieldWidth, fieldHeight);
    userShips = std::make_shared<ShipManager>(sizes);
    enemyShips = std::make_shared<ShipManager>(sizes);
    userAbilityManager = std::make_shared<AbilityManager>();
}

void GameState::resetEnemyState() {
    enemyField = std::make_shared<GameField>(fieldWidth, fieldHeight);
    enemyShips = std::make_shared<ShipManager>(sizes);
    destroyedEnemyShipsNum = 0;
}

std::shared_ptr<GameField> GameState::getUserField(){
    return userField;
}
std::shared_ptr<GameField> GameState::getEnemyField(){
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

int GameState::getShipsNum() const{
    return shipsNum;
}

int GameState::getFieldHeight() const{
    return fieldHeight;
}

int GameState::getFieldWidth() const{
    return fieldWidth;
}

int GameState::getDestroyedUserShipsNum() const{
    return destroyedUserShipsNum;
}

int GameState::getDestroyedEnemyShipsNum() const{
    return destroyedEnemyShipsNum;
}

void GameState::setUserGameField(std::shared_ptr<GameField> field){
    this->userField = field;
}
void GameState::setEnemyGameField(std::shared_ptr<GameField> field){
    this->enemyField =field;
}
void GameState::setUserShips(std::shared_ptr<ShipManager> shipManager){
    this->userShips = shipManager;
}
void GameState::setEnemyShips(std::shared_ptr<ShipManager> shipManager){
    this->enemyShips = shipManager;
}
void GameState::setUserAbilities(std::shared_ptr<AbilityManager> abilityManager){
    this->userAbilityManager = abilityManager;
}

void GameState::setFieldWidth(int w){
    this->fieldWidth = w;
}
void GameState::setFieldHeight(int h){
    this->fieldHeight = h;
}

void GameState::setShipSizes(std::vector<int> sizes_){
    this->sizes = sizes_;
}

void GameState::setShipsNum(int num){
    this->shipsNum = num;
}

void GameState::incRoundNumber() {
    roundNumber++;
}

void GameState::incDestroyedUserShipsNum() {
    destroyedUserShipsNum++;
}

void GameState::incDestroyedEnemyShipsNum() {
    destroyedEnemyShipsNum++;
}

std::ostream &operator<<(std::ostream &out, const GameState& state){
    std::cout << "Saving...\n";
    out << "Размер поля / количество кораблей\n";

    out << std::to_string(state.fieldHeight) + " " + std::to_string(state.fieldWidth) +
           " " + std::to_string(state.getShipsNum()) + "\n";

    out << "Номер раунда / количества уничтоженных кораблей\n";
    out << std::to_string(state.roundNumber) + " ";
    out << std::to_string(state.destroyedUserShipsNum) + " " + std::to_string(state.destroyedEnemyShipsNum) + "\n";

    out << "Корабли пользователя\n";
    for (int i = 0; i < state.getShipsNum(); ++i){
        auto ship = state.getUserShips()->getShip(i);
        out << ship->getInfo() + "\n";
    }

    out << "Корабли противника\n";
    for (int i = 0; i < state.getShipsNum(); ++i){
        auto ship = state.getEnemyShips()->getShip(i);
        out << ship->getInfo() + "\n";
    }

    out << "Способности пользователя\n";
    out << state.getUserAbilityManager()->getAbilitiesInfo();
    return out;
}

std::istream &operator>>(std::istream &in, GameState& state){
    std::cout << "Loading...\n";
    std::string line;

    while (std::getline(in, line) && line != "Размер поля / количество кораблей"){}
    int h, w, shipNum;
    in >> h >> w >> shipNum;
    state.setFieldHeight(h);
    state.setFieldWidth(w);
    state.setUserGameField(std::make_shared<GameField>(h, w));
    state.setEnemyGameField(std::make_shared<GameField>(h, w));
    state.setShipsNum(shipNum);

    while (std::getline(in, line) && line != "Номер раунда / количества уничтоженных кораблей") {}
    int num1, num2, num3;
    in >> num1 >> num2 >> num3;
    state.roundNumber = num1;
    state.destroyedUserShipsNum = num2;
    state.destroyedEnemyShipsNum = num3;
    while (std::getline(in, line) && line != "Корабли пользователя") {}

    std::shared_ptr<ShipManager> tempUserShips = std::make_shared<ShipManager>();
    std::vector<int> sizes;
    for (int i = 0; i < shipNum; ++i){
        std::getline(in, line);
        auto splitLine = state.splitString(line);
        sizes.push_back(std::stoi(splitLine[0]));

        auto orient = splitLine[splitLine.size() - 1];
        Orientation orientation = ( orient == "v")? Orientation::Vertical : Orientation::Horizontal;

        auto tempShip = std::make_shared<Ship>(std::stoi(splitLine[0]));
        tempShip->setOrientation(orientation);
        tempShip->setCoordinates(std::stoi(splitLine[splitLine.size() - 3]), std::stoi(splitLine[splitLine.size() - 2]));
        tempShip->initSegments();
        for (int j = 0; j < tempShip->getSize(); ++j){
            int s = std::stoi(splitLine[1 + j]);
            switch (s) {
                case 0:
                    tempShip->setSegmentStatus(j, SegmentState::Destroyed);
                    break;
                case 1:
                    tempShip->setSegmentStatus(j, SegmentState::Damaged);
                    break;
                case 2:
                    tempShip->setSegmentStatus(j, SegmentState::Intact);
                    break;
            }

        }
        tempUserShips->addShip(tempShip);
    }
    state.setUserShips(tempUserShips);
    for (int k = 0; k < shipNum; ++k){
        int x = state.getUserShips()->getShip(k)->getCoordinatesX();
        int y = state.getUserShips()->getShip(k)->getCoordinatesY();
        Orientation orientation = state.getUserShips()->getShip(k)->getOrientation();
        state.getUserField()->placeShip(x, y, state.getUserShips()->getShip(k), orientation);
    }

    while (std::getline(in, line) && line != "Корабли противника") {}
    std::shared_ptr<ShipManager> tempEnemyShips = std::make_shared<ShipManager>();
    for (int i = 0; i < shipNum; ++i){
        std::getline(in, line);
        auto splitLine = state.splitString(line);
        auto orient = splitLine[splitLine.size() - 1];
        Orientation orientation = ( orient == "v")? Orientation::Vertical : Orientation::Horizontal;

        auto tempShip = std::make_shared<Ship>(std::stoi(splitLine[0]));
        tempShip->setOrientation(orientation);
        tempShip->setCoordinates(std::stoi(splitLine[splitLine.size() - 3]), std::stoi(splitLine[splitLine.size() - 2]));
        tempShip->initSegments();
        for (int j = 0; j < tempShip->getSize(); ++j){
            int s = std::stoi(splitLine[1 + j]);
            switch (s) {
                case 0:
                    tempShip->setSegmentStatus(j, SegmentState::Destroyed);
                    break;
                case 1:
                    tempShip->setSegmentStatus(j, SegmentState::Damaged);
                    break;
                case 2:
                    tempShip->setSegmentStatus(j, SegmentState::Intact);
                    break;
            }

        }
        tempEnemyShips->addShip(tempShip);
    }
    state.setEnemyShips(tempUserShips);
    for (int k = 0; k < shipNum; ++k){
        int x = state.getEnemyShips()->getShip(k)->getCoordinatesX();
        int y = state.getEnemyShips()->getShip(k)->getCoordinatesY();
        Orientation orientation = state.getEnemyShips()->getShip(k)->getOrientation();
        state.getEnemyField()->placeShip(x, y, state.getEnemyShips()->getShip(k), orientation);
    }

    //while (std::getline(in, line) && line != "Способности игрока") {}
    std::getline(in, line);

    std::string abilitiesInfo;
    std::getline(in, abilitiesInfo);
    //std::cout << "<<<<<<<<<<<<<<" << abilitiesInfo  << "\n";
    state.setUserAbilities(std::make_shared<AbilityManager>(abilitiesInfo));

    return in;
}

void GameState::save(const std::string &filename) {
    FileWriter writer(filename + ".txt");
    writer.getOutfile() << *this;
}

void GameState::load(const std::string &filename) {
    FileReader reader(filename + ".txt");
    reader.getInfile() >> *this;
}

std::vector<std::string> GameState::splitString(const std::string& line) {
    std::vector<std::string> result;
    std::istringstream iss(line);
    std::string token;

    while (iss >> token){
        result.push_back(token);
    }

    return result;
}
