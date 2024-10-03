#include "../include/Ship.hpp"

Ship::Ship()
    : Ship(1, Orientation::Vertical, {0, 0}){}

Ship::Ship(int shipSize_, Orientation orient, Coordinates coords)
    :  shipSize(shipSize_), orientation(orient), state(ShipState::Intact), coordinates(coords){
    if (shipSize_ < 1 || shipSize_ > 4) {
        throw std::invalid_argument("Ship size must be: 1, 2, 3 or 4.");
    }
    initializeSegments();
}

int Ship::getSize() const {
    return this->shipSize;
}

void Ship::setCoordinates(const Coordinates &coords) {
    this->coordinates = coords;
    initializeSegments();
}

Coordinates Ship::getCoordinates() const {
    return this->coordinates;
}

Orientation Ship::getOrientation() const {
    return this->orientation;
}

void Ship::rotateShip() {
    orientation = (orientation == Orientation::Vertical) ? Orientation::Horizontal : Orientation::Vertical;
    initializeSegments();
}

const ShipSegment& Ship::getSegment(int index) const{
    if (index < 1 || index > shipSize){
        throw std::invalid_argument("Invalid segment index.");
    }
    return segments[index];
}

void Ship::initializeSegments() {
    segments.resize(shipSize);
    for (int i = 0; i < shipSize; ++i) {
        segments[i].hp = 2;
        segments[i].segmentState = SegmentState::Intact;
        if (orientation == Orientation::Horizontal) {
            segments[i].coordinates = {coordinates.x + i, coordinates.y};
        } else if (orientation == Orientation::Vertical) {
            segments[i].coordinates = {coordinates.x, coordinates.y + i};
        }
    }
}

void Ship::takeDamage(int index) {
    ShipSegment &segment = segments[index];

    if (segment.segmentState == SegmentState::Destroyed){
        throw std::logic_error("Can not damage a destroyed segment.");
    }

    segment.hp--;

    if (segment.hp == 1){
        segment.segmentState = SegmentState::Damaged;
    } else if (segment.hp == 0){
        segment.segmentState = SegmentState::Destroyed;
    }

    isDestroyed();
}

bool Ship::isDestroyed() {
    for (const auto& segment : segments) {
        if (segment.segmentState != SegmentState::Destroyed) {
            return false;
        }
    }
    state = ShipState::Destroyed;
    return true;
}

void Ship::printInfo() {
    std::cout << "_____Ship Information_____" << std::endl;
    std::cout << " Size: " << shipSize << std::endl;

    std::cout << " Orientation: ";
    if (orientation == Orientation::Horizontal) {
        std::cout << "Horizontal, ";
    } else{
        std::cout << "Vertical, ";
    }

    std::cout << " Starting coordinates: (" << coordinates.x << ", " << coordinates.y << ")\n";

    std::cout << "Segments info:\n";
    for (int i = 0; i < shipSize; ++i) {
        const ShipSegment &segment = segments[i];
        std::cout << "  Segment " << i + 1 << ":"
                  << " Coordinates: (" << segment.coordinates.x << ", " << segment.coordinates.y << ")"
                  << ", HP: " << segment.hp
                  << ", State: ";
        if (segment.segmentState == SegmentState::Intact) {
            std::cout << "Intact\n";
        } else if (segment.segmentState == SegmentState::Damaged) {
            std::cout << "Damaged\n";
        } else if (segment.segmentState == SegmentState::Destroyed) {
            std::cout << "Destroyed\n";
        }
    }

    std::cout << "Overall ship state: ";
    if (state == ShipState::Intact) {
        std::cout << "Intact\n";
    } else if (state == ShipState::Damaged) {
        std::cout << "Damaged\n";
    } else if (state == ShipState::Destroyed) {
        std::cout << "Destroyed\n";
    }
}
