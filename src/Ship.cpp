#include "Ship.hpp"

Ship::Ship(int shipSize_)
    : shipSize(0), orientation(Orientation::Undefined), state(ShipState::Intact), coordinates({0, 0}) {
    setSize(shipSize_);
    initializeSegments();
}

Ship::~Ship() = default;

void Ship::setSize(int shipSize_) {
    if (shipSize_ < 1 || shipSize_ > 4) {
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

void Ship::rotateShip() {
    setOrientation(orientation == Orientation::Vertical ? Orientation::Horizontal : Orientation::Vertical);
}

void Ship::initializeSegments() {
    segments.resize(shipSize);
    for (int i = 0; i < shipSize; ++i) {
        segments[i].hp = 2;
        segments[i].segmentState = SegmentState::Intact;
        segments[i].coordinates = {
                coordinates.x + (orientation == Orientation::Horizontal ? i : 0),
                coordinates.y + (orientation == Orientation::Vertical ? i : 0)
        };

    }
}

void Ship::takeDamage(int segmentIndex) {
    if (segmentIndex < 0 || segmentIndex >= static_cast<int>(segments.size())) {
        throw std::out_of_range("Invalid segment index.");
    }

    ShipSegment& segment = segments[segmentIndex];
    segment.hp--;

    if (segment.hp == 1) {
        segment.segmentState = SegmentState::Damaged;
    } else if (segment.hp == 0) {
        segment.segmentState = SegmentState::Destroyed;
    }
}

bool Ship::isDestroyed() {
    for (const auto& segment : segments) {
        if (segment.segmentState != SegmentState::Destroyed) {
            return false;
        }
    }

    if (state != ShipState::Destroyed) {
        state = ShipState::Destroyed;
    }

    return true;
}
