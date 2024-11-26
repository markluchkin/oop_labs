#include "../include/GameField.hpp"

GameField::GameField()
    : GameField(10, 10) {
    createField();
}

GameField::GameField(int height_, int width_)
    : height(height_), width(width_),
    field(height_, std::vector<CellSegment>(width_)),
    shipCounter(0),
    orginalAttack(&GameField::averageAttack){
    createField();
}

GameField::GameField(const GameField &other)
    : height(other.height),
      width(other.width),
      field(other.field){
    createField();
}
GameField::GameField(GameField &&other)
    : height(other.height), width(other.width),
    field(std::move(other.field)){}

GameField &GameField::operator=(const GameField &other) {
    if (this != &other) {
        height = other.height;
        width = other.width;
        field = other.field;
    }
    return *this;
}

GameField &GameField::operator=(GameField &&other) {
    if (this != &other) {
        height = other.height;
        width = other.width;
        field = std::move(other.field);
    }
    return *this;
}

GameField::~GameField() = default;

void GameField::createField() {
    for (int y = 0; y < height; ++y){
        for (int x = 0; x < width; ++x){
            field[y][x].cellState = CellState::Empty;
            field[y][x].shipSegment = nullptr;
        }
    }
}

CellState GameField::getStateAt(int x, int y) const{
    return field[y][x].cellState;
}

int GameField::getHeight() const{
    return this->height;
}

int GameField::getWidth() const{
    return this->width;
}

int GameField::getShipCounter() const {
    return this->shipCounter;
}

void GameField::setDoubleDamage() {
    orginalAttack = &GameField::doubleDamageAttack;
}

void GameField::removeShip(int x, int y, int shipSize, Orientation orient) {
    for (int i = 0; i < shipSize; ++i) {
        if (orient == Orientation::Horizontal) {
            if (isValidCoordinates(x + i, y)) {
                field[y][x + i].cellState = CellState::Empty;
                field[y][x + i].shipSegment = nullptr;
            }
        } else {
            if (isValidCoordinates(x, y + i)) {
                field[y + i][x].cellState = CellState::Empty;
                field[y + i][x].shipSegment = nullptr;
            }
        }
    }
}


void GameField::placeShip(int x, int y, const std::shared_ptr<Ship> &ship,  Orientation orient) {
    if (ship == nullptr){
        throw PlaceShipError("Invalid argument: nullptr was given.");
    }

    if (ship->getIsPlaced()){
        removeShip(ship->getCoordinatesX(), ship->getCoordinatesY(), ship->getSize(), ship->getOrientation());
    }

    if (isPlaceAvailable(x, y, ship)){
        if (orient != ship->getOrientation()){
            ship->rotateShip();
        }
    } else{
        throw PlaceShipError("Error: It is not an available place to place a ship.");
    }
    ship->setCoordinates(x, y);
    ship->setIsPlaced();
    this->shipCounter++;

    int shipSize = ship->getSize();
    int startX = x;
    int startY = y;

    for (int i = 0; i < shipSize; ++i) {
        if (ship->getOrientation() == Orientation::Horizontal) {
            field[startY][startX + i].cellState = CellState::ContainsShip;
            field[startY][startX + i].shipSegment = ship->getSegment(i);

        } else {
            field[startY + i][startX].cellState = CellState::ContainsShip;
            field[startY + i][startX].shipSegment = ship->getSegment(i);
        }
    }
}

bool GameField::attackCell(int x, int y) {
    bool destroyed = false;
    if (!isValidCoordinates(x, y)) {
        throw AttackError("Error: Invalid coordinates.");
    }
    CellSegment& targetCell = field[y][x];
    auto parentShip = targetCell.shipSegment->getParentShip();
    if (parentShip->isDestroyed()){
        return destroyed; // already shot at this cell and destroyed the ship
    }
    if (targetCell.cellState == CellState::ContainsShip && targetCell.shipSegment != nullptr){
        (this->*orginalAttack)(targetCell.shipSegment);
        if (parentShip->isDestroyed()) {
            destroyed = true;
        }
    } else if(targetCell.cellState == CellState::Unknown){
        targetCell.cellState = CellState::Empty;
    }
    return destroyed;
}

void GameField::printField() {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            char symbol = field[y][x].cellState == CellState::Empty ? '~' :
                          field[y][x].cellState == CellState::ContainsShip ? 'O' : '?';
            std::cout << symbol << ' ';
        }
        std::cout << std::endl;
    }
}

bool GameField::isValidCoordinates(int x, int y) const {
    return x < width && y < height && x >= 0 && y >= 0;
}

bool GameField::isPlaceAvailable( int x, int y, const std::shared_ptr<Ship> &ship) const {
    int shipSize = ship->getSize();
    int startX = x > 0 ? x - 1 : 0;
    int startY = y > 0 ? y - 1 : 0;
    int endX = ship->getOrientation() == Orientation::Vertical ? x + 1 : x + shipSize;
    int endY = ship->getOrientation() == Orientation::Vertical ? y + shipSize : y + 1;

    if (endX >= width || endY > height) {
        return false;
    }

    for (int y_ = startY; y_ <= endY; ++y_) {
        for (int x_ = startX; x_ <= endX; ++x_) {
            if (!isValidCoordinates(x_, y_) || getStateAt(x_, y_) == CellState::ContainsShip) {
                return false;
            }
        }
    }
    return true;
}

void GameField::averageAttack(std::shared_ptr<ShipSegment> shipSegment) {
    shipSegment->takeDamage();
}

void GameField::doubleDamageAttack(std::shared_ptr<ShipSegment> shipSegment) {
    shipSegment->takeDamage();
    shipSegment->takeDamage();
    std::cout << "Double Damage attack was performed. " << std::endl;
    orginalAttack = &GameField::averageAttack;
}