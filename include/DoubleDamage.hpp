#ifndef OOP_LABS_DOUBLEDAMAGE_HPP
#define OOP_LABS_DOUBLEDAMAGE_HPP

#include "structures.hpp"
#include "AbilityInterface.hpp"

class DoubleDamage : public AbilityInterface{
public:
    ~DoubleDamage() = default;
    void applyAbility(GameField &field, std::optional<int>x=std::nullopt, std::optional<int>y=std::nullopt) override;
    AbilityType getAbilityType() override;
};


#endif //OOP_LABS_DOUBLEDAMAGE_HPP
