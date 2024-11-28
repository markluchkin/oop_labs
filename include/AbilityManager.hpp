#ifndef OOP_LABS_ABILITYMANAGER_HPP
#define OOP_LABS_ABILITYMANAGER_HPP

#include "DoubleDamage.hpp"
#include "Scanner.hpp"
#include "Bombardment.hpp"
#include "structures.hpp"

class AbilityManager {
public:
    AbilityManager();
    void addRandomAbility();
    void addAbility(AbilityType abilityType);
    void useAbility(std::shared_ptr<GameField> field, std::optional<int>x=std::nullopt, std::optional<int>y=std::nullopt);
    AbilityType getFrontAbilityType() const;
    ~AbilityManager() = default;
    bool isEmpty();
private:
    std::queue<std::shared_ptr<AbilityInterface>> abilities;
};


#endif //OOP_LABS_ABILITYMANAGER_HPP
