#ifndef OOP_LABS_SHIP_HPP
#define OOP_LABS_SHIP_HPP

#include "../include/ShipSegment.hpp"

class Ship {
public:
    Ship();
    Ship(int shipSize_ = 1, Orientation orient = Orientation::Vertical);

    int getSize() const;

    Orientation getOrientation() const;
    void rotateShip();

    int getCoordinatesX() const;
    int getCoordinatesY() const;
    void setCoordinates(int x_, int y_);

    std::shared_ptr<ShipSegment> getSegment(int index);

    bool getIsPlaced() const;
    void setIsPlaced();

    void printInfo();


private:
    std::vector<std::shared_ptr<ShipSegment>> segments;
    int shipSize;
    Orientation orientation;
    bool isPlaced;
    int x;
    int y;
};

#endif //OOP_LABS_SHIP_HPP
