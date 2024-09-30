#include "Ship.hpp"
#include <stdexcept>

Ship::Ship(int shipSize_) {
    setSize(shipSize_);
    initializeSegments();
}

Ship::~Ship() = default;

void Ship::setSize(int shipSize_) {
    if (shipSize < 1 || shipSize > 4) {
        throw std::invalid_argument("Ship size must be: 1, 2, 3 or 4.");
    }
    this->shipSize = shipSize_;
}

int Ship::getSize() const {
    return this->shipSize;
}

void Ship::setCoordinates(const Coordinates &coords) {
    this->coordinates = coords;
}

Coordinates Ship::getCoordinates() const {
    return this->coordinates;
}

void Ship::setOrientation(Orientation orient) {
    this->orientation = orient;
}

Orientation Ship::getOrientation() const {
    return this->orientation;
}

void Ship::initializeSegments() {
    segments.resize(shipSize);
    for (int i = 0; i < shipSize; ++i) {
        segments[i].hp = 1;
        segments[i].segmentState = SegmentState::Intact;

        segments[i].coordinates = {coordinates.x + (orientation == Orientation::Horizontal ? i : 0), coordinates.y};
        segments[i].coordinates = {coordinates.x, coordinates.y + (orientation == Orientation::Vertical ? i : 0)};
    }
}

void Ship::takeDamage(int segmentIndex) {
    //...
}

bool Ship::isDestroyed(){
    for (const auto& segment : segments) {
        if (segment.segmentState != SegmentState::Destroyed){
            return false;
        }
    }

    this->state = ShipState::Destroyed;
    return true;
}