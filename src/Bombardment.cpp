#include "../include/Bombardment.hpp"

void Bombardment::applyAbility(GameField &field, std::optional<int>x, std::optional<int>y) {
    (void)x;
    (void)y;
    std::cout << "Bombardment is applying." << std::endl;
    if (field.getShipCounter() == 0){
        throw EmptyFieldError("Error: The is empty.");
    }

    while (true){
        int rand_x = std::rand() % field.getWidth();
        int rand_y = std::rand() % field.getHeight();
        if (field.getStateAt(rand_x, rand_y) == CellState::ContainsShip){
            field.attackCell(rand_x, rand_y);
            break;
        } else{
            continue;
        }
    }
    std::cout << "Bombardment was performed." << std::endl;
}

AbilityType Bombardment::getAbilityType() {
    return AbilityType::Bomb;
}