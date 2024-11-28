#ifndef OOP_LABS_SHIPSEGMENT_HPP
#define OOP_LABS_SHIPSEGMENT_HPP

#include "structures.hpp"
class Ship;

class ShipSegment{
public:
    ShipSegment(std::shared_ptr<Ship> parentShip_, SegmentState state);
    ~ShipSegment();
    int getHp() const;
    void takeDamage();

    void setState(SegmentState state);
    SegmentState getState() const;

    std::shared_ptr<Ship> getParentShip() const;

private:
    int hp;
    SegmentState segmentState;
    std::shared_ptr<Ship> parentShip;
};


#endif //OOP_LABS_SHIPSEGMENT_HPP
