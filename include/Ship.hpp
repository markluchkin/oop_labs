#ifndef OOP_LABS_SHIP_HPP
#define OOP_LABS_SHIP_HPP

#include "../include/structures.hpp"
#include <vector>
#include <iostream>

class Ship {
public:
    Ship();
    explicit Ship(int shipSize_ = 1, Orientation orient = Orientation::Vertical, Coordinates coords = {0, 0});

    int getSize() const;

    void setCoordinates(const Coordinates& coords);
    Coordinates getCoordinates() const;

    Orientation getOrientation() const;
    void rotateShip();

    const ShipSegment& getSegment(int index) const;

    void takeDamage(int index);
    bool isDestroyed();

    void printInfo();

    std::vector<ShipSegment> segments;
private:
    int shipSize;
    Orientation orientation;
    ShipState state;
    Coordinates coordinates;
    void initializeSegments();
};

#endif //OOP_LABS_SHIP_HPP
