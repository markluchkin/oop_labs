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

    void setCoordinates(const Coordinates& coords);
    Coordinates getCoordinates() const;

private:
    int hp;
    SegmentState segmentState;
    Coordinates coordinates;
};


#endif //OOP_LABS_SHIPSEGMENT_HPP
