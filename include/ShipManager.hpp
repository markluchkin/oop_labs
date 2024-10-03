#ifndef OOP_LABS_SHIPMANAGER_HPP
#define OOP_LABS_SHIPMANAGER_HPP

#include "../include/Ship.hpp"
#include <memory>

class ShipManager {
public:
    ShipManager();
    explicit ShipManager(std::vector<int> sizes);

    std::shared_ptr<Ship> getShip(int index);
    std::shared_ptr<Ship> getShipByCoords(Coordinates coords);
    std::vector<std::shared_ptr<Ship>> getAllShips();

    void printShipsInfo();

private:
    std::vector<std::shared_ptr<Ship>> ships;
    void addShip(std::shared_ptr<Ship> ship);
    void createDefaultSetOfShips();
};

#endif //OOP_LABS_SHIPMANAGER_HPP
