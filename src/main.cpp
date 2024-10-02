#include "Field.hpp"
#include "ShipManager.hpp"

int main() {
    std::cout << "BattleShip\n";
    Ship ship(4);
    ship.rotateShip();
    ship.printInfo();
    return 0;
}