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

    bool getIsPlaced() const;
    void setIsPlaced();

    void printInfo();


private:
    std::vector<std::shared_ptr<ShipSegment>> segments;
    int shipSize;
    Orientation orientation;
    Coordinates coordinates;
    bool isPlaced;
    void initializeSegments();
};

#endif //OOP_LABS_SHIP_HPP
