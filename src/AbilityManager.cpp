#include "../include/AbilityManager.hpp"

AbilityManager::AbilityManager(bool AllAbilitiesInclude) {
    if (AllAbilitiesInclude){
        abilities.push(std::make_shared<DoubleDamage>());
        abilities.push(std::make_shared<Scanner>());
        abilities.push(std::make_shared<Bombardment>());
    } else {
        addRandomAbility();
    }
}

void AbilityManager::addRandomAbility() {
    int abilityType = std::rand() % 3;
    switch (abilityType) {
        case 0:
            abilities.push(std::make_shared<DoubleDamage>());
            break;
        case 1:
            abilities.push(std::make_shared<Scanner>());
            break;
        case 2:
            abilities.push(std::make_shared<Bombardment>());
            break;
    }
}

void AbilityManager::addAbility(AbilityType abilityType) {
    switch (abilityType) {
        case AbilityType::DD:
            abilities.push(std::make_shared<DoubleDamage>());
        case AbilityType::Scan:
            abilities.push(std::make_shared<Scanner>());
        case AbilityType::Bomb:
            abilities.push(std::make_shared<Bombardment>());
    }
}

void AbilityManager::useAbility(GameField &field, std::optional<int>x, std::optional<int>y) {
    if (abilities.empty()) {
        throw NoAbilityError("Error: There is no abilities to use.");
    }
    auto ability = abilities.front();
    ability->applyAbility(field, x, y);
    abilities.pop();
}