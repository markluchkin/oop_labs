#ifndef OOP_LABS_SHIPMANAGER_HPP
#define OOP_LABS_SHIPMANAGER_HPP

#include "Ship.hpp"
#include <memory>

class ShipManager {
public:
    ShipManager();
    ShipManager(std::vector<int> sizes);
    ~ShipManager();

    void addShip(std::shared_ptr<Ship> ship);
    void createDefaultSetOfShips();

    void printShipsInfo();

private:
    std::vector<std::shared_ptr<Ship>> ships;
};

#endif //OOP_LABS_SHIPMANAGER_HPP
