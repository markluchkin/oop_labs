#include "../include/ShipSegment.hpp"

ShipSegment::ShipSegment()
    : hp(2), segmentState(SegmentState::Intact), coordinates({0, 0}) {}

ShipSegment::~ShipSegment() = default;

int ShipSegment::getHp() const{
    return hp;
}

void ShipSegment::takeDamage() {
    if (segmentState == SegmentState::Destroyed){
        throw std::logic_error("Can not damage a destroyed segment.");
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

void ShipSegment::setCoordinates(const Coordinates& coords) {
    this->coordinates = coords;
}

Coordinates ShipSegment::getCoordinates() const{
    return coordinates;
}