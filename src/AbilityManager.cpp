#include "../include/AbilityManager.hpp"

AbilityManager::AbilityManager() {
    std::vector<std::shared_ptr<AbilityInterface>> abilitiesSet;
    abilitiesSet.push_back(std::make_shared<DoubleDamage>());
    abilitiesSet.push_back(std::make_shared<Scanner>());
    abilitiesSet.push_back(std::make_shared<Bombardment>());
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    auto range = std::default_random_engine(seed);
    std::shuffle(abilitiesSet.begin(), abilitiesSet.end(), range);

    for (auto ability : abilitiesSet){
        abilities.push(ability);
    }
}

AbilityManager::AbilityManager(const std::string &info) {
    std::istringstream iss(info);
    int abilityType;
    while (iss >> abilityType){
        switch (abilityType) {
            case 0:
                addAbility(AbilityType::DD);
                break;
            case 1:
                addAbility(AbilityType::Scan);
                break;
            case 2:
                addAbility(AbilityType::Bomb);
                break;
        }
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
            break;
        case AbilityType::Scan:
            abilities.push(std::make_shared<Scanner>());
            break;
        case AbilityType::Bomb:
            abilities.push(std::make_shared<Bombardment>());
            break;
    }
}

void AbilityManager::useAbility(std::shared_ptr<GameField> field, std::optional<int>x, std::optional<int>y) {
    if (abilities.empty()) {
        throw NoAbilityError("Error: There is no abilities to use.");
    }
    auto ability = abilities.front();
    ability->applyAbility(field, x, y);
    abilities.pop();
}

AbilityType AbilityManager::getFrontAbilityType() const {
    return abilities.front()->getAbilityType();
}

bool AbilityManager::isEmpty() {
    return abilities.empty();
}

std::string AbilityManager::getAbilitiesInfo() const{
    std::string info;
    auto tempQueue = abilities;
    while (!tempQueue.empty()) {
        std::shared_ptr<AbilityInterface> ability = tempQueue.front();
        tempQueue.pop();
        info += std::to_string(static_cast<int>(ability->getAbilityType())) + " ";
    }
    return info;
}