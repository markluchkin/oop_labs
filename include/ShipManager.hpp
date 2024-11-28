#ifndef OOP_LABS_SHIPMANAGER_HPP
#define OOP_LABS_SHIPMANAGER_HPP

#include "../include/Ship.hpp"

class ShipManager {
public:
    ShipManager();
    ShipManager(std::vector<int> sizes);

    std::shared_ptr<Ship> getShip(int index);
    std::vector<std::shared_ptr<Ship>> getAllShips();

    void printShipsInfo();
    void addShip(std::shared_ptr<Ship> ship);
private:
    std::vector<std::shared_ptr<Ship>> ships;

    void createDefaultSetOfShips();
};

#endif //OOP_LABS_SHIPMANAGER_HPP
