#ifndef OOP_LABS_ABILITYINTERFACE_HPP
#define OOP_LABS_ABILITYINTERFACE_HPP

#include "structures.hpp"
#include "GameField.hpp"
#include "ShipManager.hpp"

class AbilityInterface {
public:
    virtual ~AbilityInterface() = default;
    virtual void applyAbility(GameField &field) = 0;
    virtual AbilityType getAbilityType() = 0;
};


#endif //OOP_LABS_ABILITYINTERFACE_HPP
