#ifndef OOP_LABS_DOUBLEDAMAGE_HPP
#define OOP_LABS_DOUBLEDAMAGE_HPP

#include "structures.hpp"
#include "AbilityInterface.hpp"

class DoubleDamage : public AbilityInterface{
public:
    DoubleDamage();
    ~DoubleDamage() = default;
    void applyAbility() override;

};


#endif //OOP_LABS_DOUBLEDAMAGE_HPP
