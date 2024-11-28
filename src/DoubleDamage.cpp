#include "../include/DoubleDamage.hpp"

void DoubleDamage::applyAbility(std::shared_ptr<GameField> field, std::optional<int>x, std::optional<int>y) {
    (void)x;
    (void)y;
    std::cout << "Double Damage is applying." << std::endl;
    field->setDoubleDamage();
}

AbilityType DoubleDamage::getAbilityType() {
    return AbilityType::DD;
}