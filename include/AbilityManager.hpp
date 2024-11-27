#ifndef OOP_LABS_ABILITYMANAGER_HPP
#define OOP_LABS_ABILITYMANAGER_HPP

#include "DoubleDamage.hpp"
#include "Scanner.hpp"
#include "Bombardment.hpp"
#include "structures.hpp"
#include <queue>

class AbilityManager {
public:
    AbilityManager(bool AllAbilitiesInclude=false);
    void addRandomAbility();
    void addAbility(AbilityType abilityType);
    void useAbility(GameField &field, std::optional<int>x=std::nullopt, std::optional<int>y=std::nullopt);
    ~AbilityManager() = default;
private:
    std::queue<std::shared_ptr<AbilityInterface>> abilities;
};


#endif //OOP_LABS_ABILITYMANAGER_HPP
