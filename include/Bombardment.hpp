#ifndef OOP_LABS_BOMBARDMENT_HPP
#define OOP_LABS_BOMBARDMENT_HPP

#include "AbilityInterface.hpp"

class Bombardment : public AbilityInterface {
public:
    ~Bombardment() = default;
    void applyAbility(std::shared_ptr<GameField> field, std::optional<int>x=std::nullopt, std::optional<int>y=std::nullopt) override;
    AbilityType getAbilityType() override;
};


#endif //OOP_LABS_BOMBARDMENT_HPP
