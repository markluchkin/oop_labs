#ifndef OOP_LABS_GAMEFIELD_HPP
#define OOP_LABS_GAMEFIELD_HPP


#include "../include/Ship.hpp"
#include "../include/CellSegment.hpp"


class GameField {
public:
    GameField();
    GameField(int height_, int width_);
    GameField(const GameField& other);
    GameField(GameField &&other);
    GameField &operator=(const GameField &other);
    GameField &operator=(GameField &&other);
    ~GameField();

    void createField();

    CellState getStateAt(int x, int y) const;
    int getHeight() const;
    int getWidth() const;
    int getShipCounter() const;

    void setDoubleDamage();

    void removeShip(int x, int y, int shipSize, Orientation orient);
    void placeShip(int x, int y, const std::shared_ptr<Ship> &ship, Orientation orient = Orientation::Vertical);
    bool attackCell(int x, int y); // true if destroys a ship

    void printField();

    bool isValidCoordinates(int x, int y) const;
    bool isPlaceAvailable(int x, int y, const std::shared_ptr<Ship> &ship) const;

private:
    int height;
    int width;
    std::vector<std::vector<CellSegment>> field;
    int shipCounter;
    using AttackFunction = void (GameField::*)(std::shared_ptr<ShipSegment> shipSegment);
    AttackFunction orginalAttack;
    void doubleDamageAttack(std::shared_ptr<ShipSegment> shipSegment);
    void averageAttack(std::shared_ptr<ShipSegment> shipSegment);
};

#endif //OOP_LABS_GAMEFIELD_HPP
