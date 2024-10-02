#include "ShipManager.hpp"

ShipManager::ShipManager(){
    createDefaultSetOfShips();
}

ShipManager::ShipManager(std::vector<int> sizes) {
    for (int j = 0; j < static_cast<int>(size(sizes)); j++) {
        addShip(std::make_shared<Ship>(sizes[j]));
    }
}

ShipManager::~ShipManager() = default;

void ShipManager::addShip(std::shared_ptr<Ship> ship) {
    ships.push_back(std::move(ship));
}

void ShipManager::createDefaultSetOfShips() {
    std::vector<int> sizes = {4, 3, 3, 2, 2, 2, 1, 1, 1, 1};
    for (int j = 0; j < static_cast<int>(size(sizes)); j++) {
        addShip(std::make_shared<Ship>(sizes[j]));
    }
}

void ShipManager::printShipsInfo() {
    for (auto &ship : ships) {
        ship->printInfo();
        std::cout << "------------------------\n";
    }
}