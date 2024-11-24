#include "../include/DoubleDamage.hpp"

void DoubleDamage::applyAbility(GameField &field) {
    std::cout << "Double Damage is applying." << std::endl;
    field.setDoubleDamage();
}

AbilityType DoubleDamage::getAbilityType() {
    return AbilityType::DD;
}