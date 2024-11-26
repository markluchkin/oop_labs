#include "../include/Ship.hpp"

Ship::Ship()
    : Ship(1, Orientation::Vertical){}

Ship::Ship(int shipSize_, Orientation orient)
    :  shipSize(shipSize_), orientation(orient),
    isPlaced(false){
    if (shipSize_ < 1)
        shipSize = 1;
    else if (shipSize_ > 4)
        shipSize = 4;

//    for (int i = 0; i < shipSize; i++){
//        segments.push_back(std::make_shared<ShipSegment>(shared_from_this()));
//    }
//    initSegments();
}

void Ship::initSegments() {
    for (int i = 0; i < shipSize; i++) {
        segments.push_back(std::make_shared<ShipSegment>(shared_from_this()));
    }
}

int Ship::getSize() const {
    return this->shipSize;
}

Orientation Ship::getOrientation() const {
    return this->orientation;
}

void Ship::rotateShip() {
    orientation = (orientation == Orientation::Vertical) ? Orientation::Horizontal : Orientation::Vertical;
}

int Ship::getCoordinatesX() const {
    return x;
}

int Ship::getCoordinatesY() const {
    return y;
}

void Ship::setCoordinates(int x_, int y_) {
    this->x = x_;
    this->y = y_;
}

std::shared_ptr<ShipSegment> Ship::getSegment(int index){
    return segments[index];
}

bool Ship::isDestroyed() const {
    for (int i = 0; i < shipSize; ++i){
        if (segments[i]->getHp() > 0){
            return false;
        }
    }

    return true;
}

bool Ship::getIsPlaced() const {
    return isPlaced;
}

void Ship::setIsPlaced(){
    this->isPlaced = true;
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
    std::cout << " Is placed: (" << this->isPlaced << ")\n";

    std::cout << "Segments info:\n";
    for (int i = 0; i < shipSize; ++i) {
        auto segment = segments[i];
        std::cout << "  Segment " << i + 1 << ":"
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
}
