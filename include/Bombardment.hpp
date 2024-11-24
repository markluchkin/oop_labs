#ifndef OOP_LABS_BOMBARDMENT_HPP
#define OOP_LABS_BOMBARDMENT_HPP

#include "structures.hpp"
#include "AbilityInterface.hpp"
#include <cstdlib>
#include <ctime>

class Bombardment : public AbilityInterface {
public:
    ~Bombardment() = default;
    void applyAbility(GameField &field, std::optional<int>x=std::nullopt, std::optional<int>y=std::nullopt) override;
    AbilityType getAbilityType() override;
};


#endif //OOP_LABS_BOMBARDMENT_HPP
