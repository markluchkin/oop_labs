#ifndef OOP_LABS_SHIPSEGMENT_HPP
#define OOP_LABS_SHIPSEGMENT_HPP

#include "structures.hpp"

class ShipSegment{
public:
    ShipSegment();
    ~ShipSegment();
    int getHp() const;
    void takeDamage();

    void setState(SegmentState state);
    SegmentState getState() const;

private:
    int hp;
    SegmentState segmentState;
};


#endif //OOP_LABS_SHIPSEGMENT_HPP
