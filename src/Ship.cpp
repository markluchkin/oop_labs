#include "include/Ship.hpp"


Ship::Ship(int shipSize) {
    setSize(shipSize);
    initializeSegments();
}

Ship::~Ship() = default;

void Ship::setSize(int shipSize) {
    if (shipSize < 1 || shipSize > 4) {
        throw std::invalid_argument("Ship size must be: 1, 2, 3 or 4.");
    }
    this->shipSize = shipSize;
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

void Ship::setOrientation(Orientation orientation) {
    this->orientation = orientation;
}

Orientation Ship::getOrientation() const {
    return this->orientation;
}

void Ship::initializeSegments() {
    //...
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