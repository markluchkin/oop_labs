#include "../include/ShipManager.hpp"

ShipManager::ShipManager(){
    createDefaultSetOfShips();
}

ShipManager::ShipManager(std::vector<int> sizes) {
    for (int j = 0; j < static_cast<int>(size(sizes)); j++) {
        addShip(std::make_shared<Ship>(sizes[j]));
    }
}

void ShipManager::addShip(std::shared_ptr<Ship> ship) {
    ships.push_back(std::move(ship));
}

void ShipManager::createDefaultSetOfShips() {
    std::vector<int> sizes = {4, 3, 3, 2, 2, 2, 1, 1, 1, 1};
    for (int j = 0; j < static_cast<int>(size(sizes)); j++) {
        addShip(std::make_shared<Ship>(sizes[j]));
    }
}

std::shared_ptr<Ship> ShipManager::getShip(int index) {
    return ships[index];
}

std::shared_ptr<Ship> ShipManager::getShipByCoords(Coordinates coords) {
    for (auto &ship : ships){
        if(ship->getCoordinates() == coords){
            return ship;
        }
    }
    return nullptr;
}

std::vector<std::shared_ptr<Ship>> ShipManager::getAllShips() {
    return ships;
}

void ShipManager::printShipsInfo() {
    for (auto &ship : ships) {
        ship->printInfo();
        std::cout << "--------------------\n";
    }
}