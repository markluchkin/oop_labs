#ifndef OOP_LABS_SHIPSEGMENT_HPP
#define OOP_LABS_SHIPSEGMENT_HPP

#include "structures.hpp"
#include "Ship.hpp"

struct CellSegment{
    Coordinates coords;
    CellState cellState;
    std::shared_ptr<Ship> ship_;
    int segmentIndex;
};
#endif //OOP_LABS_SHIPSEGMENT_HPP
