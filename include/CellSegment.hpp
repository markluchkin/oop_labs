#ifndef OOP_LABS_CELLSEGMENT_HPP
#define OOP_LABS_CELLSEGMENT_HPP

#include "../include/ShipSegment.hpp"

struct CellSegment{
    CellState cellState;
    std::shared_ptr<ShipSegment> shipSegment;
};

#endif //OOP_LABS_CELLSEGMENT_HPP
