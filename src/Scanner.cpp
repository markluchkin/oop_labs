#include "../include/Scanner.hpp"

void Scanner::applyAbility(GameField &field) {
    std::cout << "Bombardment is applying." << std::endl;

    bool found = false;
    for (int dx = -1; dx <= 0; ++dx){
        for (int dy = -1; dy <= 0; ++dy){
            if (field.isValidCoordinates(x, y) &&
            field.getStateAt(x + dx, y + dy) == CellState::ContainsShip){
                found = true;
                break;
            }
        }
    }

    std::cout << (found ? "Found a ship segment!" : "Ship segment was not found. ") << std::endl;
}

AbilityType Scanner::getAbilityType() {
    return AbilityType::Scan;
}