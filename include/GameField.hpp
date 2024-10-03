#ifndef OOP_LABS_GAMEFIELD_HPP
#define OOP_LABS_GAMEFIELD_HPP

#include <memory>
#include "../include/structures.hpp"
#include "../include/Ship.hpp"

class GameField {
public:
    GameField();
    GameField(int height_, int width_);
    GameField(const GameField& other);
    GameField &operator=(const GameField &other);
    ~GameField();

    void createField();

    CellState getStateAt(Coordinates coords) const;
    int getHeight() const;
    int getWidth() const;

    void placeShip(Coordinates coords, std::shared_ptr<Ship> &ship);
    void attackCell(Coordinates coords);

    void printField();

    bool isValidCoordinates(Coordinates coords) const;
    bool isPlaceAvailable(Coordinates coords, std::shared_ptr<Ship> &ship) const;

private:
    int height;
    int width;
    std::vector<std::vector<CellSegment>> field;
};

#endif //OOP_LABS_GAMEFIELD_HPP
