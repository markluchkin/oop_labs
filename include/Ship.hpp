#ifndef OOP_LABS_SHIP_HPP
#define OOP_LABS_SHIP_HPP
#include "structures.hpp"

class Ship {
public:
    Ship(int size);
    ~Ship();

    void setSize(int size);

    int getSize();
    Coordinates getCoordinates();

private:
    int size;
    bool orientation;
    ShipState state;
    Coordinates coordinates;
};


#endif //OOP_LABS_SHIP_HPP
