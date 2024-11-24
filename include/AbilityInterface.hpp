#ifndef OOP_LABS_ABILITYINTERFACE_HPP
#define OOP_LABS_ABILITYINTERFACE_HPP

#include "structures.hpp"
#include "GameField.hpp"
#include "ShipManager.hpp"
#include <optional>

class AbilityInterface {
public:
    virtual ~AbilityInterface() = default;
    virtual void applyAbility(GameField &field, std::optional<int>x=std::nullopt, std::optional<int>y=std::nullopt) = 0;
    virtual AbilityType getAbilityType() = 0;
};


#endif //OOP_LABS_ABILITYINTERFACE_HPP
