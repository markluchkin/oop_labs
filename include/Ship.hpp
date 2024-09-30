#ifndef OOP_LABS_SHIP_HPP
#define OOP_LABS_SHIP_HPP
#include "structures.hpp"
#include <vector>


class Ship {
public:
    Ship(int size);
    ~Ship();

    void setSize(int size);

    int getSize();
    Coordinates getCoordinates();

private:
    int size;
    bool isVertical;
    ShipState state;
    Coordinates coordinates;
    std::vector<ShipSegment> segments;
};


#endif //OOP_LABS_SHIP_HPP
