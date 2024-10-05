#ifndef OOP_LABS_SHIP_HPP
#define OOP_LABS_SHIP_HPP

#include "../include/ShipSegment.hpp"

class Ship {
public:
    Ship();
    Ship(int shipSize_ = 1, Orientation orient = Orientation::Vertical, Coordinates coords = {0, 0});

    int getSize() const;

    void setCoordinates(const Coordinates& coords);
    Coordinates getCoordinates() const;

    Orientation getOrientation() const;
    void rotateShip();

    std::shared_ptr<ShipSegment> getSegment(int index);

    void takeDamage(int index);
    bool isDestroyed();

    void printInfo();

private:
    std::vector<std::shared_ptr<ShipSegment>> segments;
    int shipSize;
    Orientation orientation;
    ShipState state;
    Coordinates coordinates;
    void initializeSegments();
};

#endif //OOP_LABS_SHIP_HPP
