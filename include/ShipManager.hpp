#ifndef OOP_LABS_SHIPMANAGER_HPP
#define OOP_LABS_SHIPMANAGER_HPP

#include "Ship.hpp"

class ShipManager {
public:
    ShipManager(const std::vector<int>& sizes);
    ~ShipManager();

private:
    std::vector<Ship> ships;
};


#endif //OOP_LABS_SHIPMANAGER_HPP
