#ifndef OOP_LABS_GAMEFIELD_HPP
#define OOP_LABS_GAMEFIELD_HPP

#include <memory>
#include "../include/structures.hpp"
#include "../include/Ship.hpp"
#include "../include/CellSegment.hpp"

class GameField {
public:
    GameField();
    explicit GameField(int height_, int width_);
    explicit GameField(const GameField& other);
    GameField(GameField &&other);
    GameField &operator=(const GameField &other);
    GameField &operator=(GameField &&other);
    ~GameField();

    void createField();

    CellState getStateAt(Coordinates coords) const;
    int getHeight() const;
    int getWidth() const;

    void placeShip(Coordinates coords, std::shared_ptr<Ship> &ship, Orientation orient = Orientation::Vertical);
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
