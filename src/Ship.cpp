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

std::shared_ptr<ShipSegment> Ship::getSegment(int index){
    if (index < 0 || index >= shipSize){
        throw std::invalid_argument("Invalid segment index.");
    }

    return segments[index];
}

void Ship::initializeSegments() {
    segments.resize(shipSize);
    for (int i = 0; i < shipSize; ++i) {
        auto segment = std::make_shared<ShipSegment>();
        if (orientation == Orientation::Horizontal) {
            segment->setCoordinates({coordinates.x + i, coordinates.y});
        } else if (orientation == Orientation::Vertical) {
            segment->setCoordinates({coordinates.x, coordinates.y + i});
        }
        segments[i] = segment;
    }
}

bool Ship::isDestroyed() { // I got to add some checkState methods?
    for (const auto& segment : segments) {
        if (segment->getState() != SegmentState::Destroyed) {
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
        auto segment = segments[i];
        std::cout << "  Segment " << i + 1 << ":"
                  << " Coordinates: (" << segment->getCoordinates().x << ", " << segment->getCoordinates().y << ")"
                  << ", HP: " << segment->getHp()
                  << ", State: ";
        if (segment->getState() == SegmentState::Intact) {
            std::cout << "Intact\n";
        } else if (segment->getState() == SegmentState::Damaged) {
            std::cout << "Damaged\n";
        } else if (segment->getState() == SegmentState::Destroyed) {
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
