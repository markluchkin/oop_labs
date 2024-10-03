#include "../include/GameField.hpp"

GameField::GameField()
    : GameField(10, 10) {
    createField();
}

GameField::GameField(int height_, int width_)
    : height(height_), width(width_),
    field(height_, std::vector<CellSegment>(width_)){
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
    field(std::move(other.field)){
    other.field.clear();
}

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
            field[y][x].coords.x = x;
            field[y][x].coords.y = y;
            field[y][x].cellState = CellState::Unknown;
            field[y][x].ship_ = nullptr;
        }
    }
}

CellState GameField::getStateAt(Coordinates coords) const{
    return field[coords.x][coords.y].cellState;
}

int GameField::getHeight() const{
    return this->height;
}

int GameField::getWidth() const{
    return this->width;
}

void GameField::placeShip(Coordinates coords, std::shared_ptr<Ship> &ship,  Orientation orient) {
    if (ship == nullptr){
        throw std::invalid_argument("Invalid argument: nullptr was given.");
    }

    if (isPlaceAvailable(coords, ship)){
        ship->setCoordinates(coords);
        if (orient == Orientation::Horizontal){
            ship->rotateShip();
        }
    }

    int shipSize = ship->getSize();
    int startX = coords.x;
    int startY = coords.y;

    for (int i = 0; i < shipSize; ++i) {
        if (ship->getOrientation() == Orientation::Horizontal) {
            field[startY][startX + i].cellState = CellState::ContainsShip;
            field[startY][startX + i].ship_ = ship;
            field[startY][startX + i].segmentIndex = i;

        } else {
            field[startY + i][startX].cellState = CellState::ContainsShip;
            field[startY + i][startX].ship_ = ship;
            field[startY + i][startX].segmentIndex = i;
        }
    }
}

void GameField::attackCell(Coordinates coords) {
    if (!isValidCoordinates(coords)) {
        throw std::out_of_range("Invalid coordinates.");
    }
    CellSegment& targetCell = field[coords.y][coords.x];

    if (targetCell.cellState == CellState::ContainsShip){
        auto hitShip = targetCell.ship_;
        hitShip->takeDamage(targetCell.segmentIndex);
    }
}

void GameField::printField() {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            switch (field[y][x].cellState) {
                case CellState::Empty:
                    std::cout << ". ";
                    break;
                case CellState::ContainsShip:
                    std::cout << "O ";
                    break;
                case CellState::Unknown:
                default:
                    std::cout << "? ";
                    break;
            }
        }
        std::cout << std::endl;
    }
}

bool GameField::isValidCoordinates(Coordinates coords) const {
    return coords.x < width && coords.y < height;
}

bool GameField::isPlaceAvailable(Coordinates coords, std::shared_ptr<Ship> &ship) const {
    int shipSize = ship->getSize();
    int startX = coords.x > 0 ? coords.x - 1 : 0;
    int startY = coords.y > 0 ? coords.y - 1 : 0;
    int endX = ship->getOrientation() == Orientation::Vertical ? coords.x + 1 : coords.x + shipSize;
    int endY = ship->getOrientation() == Orientation::Vertical ? coords.y + shipSize : coords.y + 1;

    if (endX >= width || endY >= height) {
        return false;
    }

    for (int y = startY; y <= endY; ++y) {
        for (int x = startX; x <= endX; ++x) {
            if (!isValidCoordinates({x, y}) || getStateAt({x, y}) == CellState::ContainsShip) {
                return false;
            }
        }
    }
    return true;
}
