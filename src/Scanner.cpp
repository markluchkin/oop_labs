#include "../include/Scanner.hpp"

void Scanner::applyAbility(std::shared_ptr<GameField> field, std::optional<int>x, std::optional<int>y) {
    std::cout << "Scanner is applying." << std::endl;
    if (!x || !y) {
        throw std::invalid_argument("Scanner ability requires a coordinate!");
    }

    bool found = false;
    for (int dx = -1; dx <= 0; ++dx){
        for (int dy = -1; dy <= 0; ++dy){
            if (field->isValidCoordinates(x.value(), y.value()) &&
            field->getStateAt(x.value() + dx, y.value() + dy) == CellState::ContainsShip){
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