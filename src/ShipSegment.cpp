#include "../include/ShipSegment.hpp"

ShipSegment::ShipSegment(std::shared_ptr<Ship> parentShip_, SegmentState state)
    : hp(2), segmentState(state), parentShip(parentShip_) {
}

ShipSegment::~ShipSegment() = default;

int ShipSegment::getHp() const{
    return hp;
}

void ShipSegment::takeDamage() {
    if (segmentState == SegmentState::Destroyed){
        return;
    }
    hp--;
    if (hp == 1){
        segmentState = SegmentState::Damaged;
    } else if(hp == 0){
        segmentState = SegmentState::Destroyed;
    }
}

SegmentState ShipSegment::getState() const{
    return segmentState;
}

void ShipSegment::setState(SegmentState state) {
    this->segmentState = state;
}

std::shared_ptr<Ship> ShipSegment::getParentShip() const {
    return parentShip;
}