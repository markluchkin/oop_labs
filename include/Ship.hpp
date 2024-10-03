#ifndef OOP_LABS_SHIP_HPP
#define OOP_LABS_SHIP_HPP

#include "../include/structures.hpp"
#include <vector>
#include <iostream>

class Ship {
public:
    explicit Ship(int shipSize_);
    explicit Ship(int shipSize_, Orientation orient, Coordinates coords);

    int getSize() const;

    void setCoordinates(const Coordinates& coords);
    Coordinates getCoordinates() const;

    Orientation getOrientation() const;
    void rotateShip();

    const ShipSegment& getSegment(int index) const;

    void takeDamage(int segmentIndex);
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
