#ifndef OOP_LABS_DOUBLEDAMAGE_HPP
#define OOP_LABS_DOUBLEDAMAGE_HPP

#include "structures.hpp"
#include "AbilityInterface.hpp"

class DoubleDamage : public AbilityInterface{
public:
    ~DoubleDamage() = default;
    void applyAbility(GameField &field) override;
};


#endif //OOP_LABS_DOUBLEDAMAGE_HPP
