#include "../include/GameField.hpp"
#include "../include/ShipManager.hpp"
#include "../include/structures.hpp"

int main() {
    std::cout << "BattleShip\n";
    std::vector<int> shipSizes = {4, 3, 2, 1,};
    ShipManager manager(shipSizes);
    GameField field;
    auto s = manager.getAllShips();
    field.placeShip({5, 5}, s[0], Orientation::Vertical);
    field.placeShip({1, 1}, s[1], Orientation::Horizontal);
    field.placeShip({1, 3}, s[2], Orientation::Horizontal);
    field.placeShip({3, 8}, s[3]);

    field.attackCell({5, 6});
    manager.printShipsInfo();
    field.printField();
    return 0;
}