#ifndef OOP_LABS_BOMBARDMENT_HPP
#define OOP_LABS_BOMBARDMENT_HPP

#include "structures.hpp"
#include "AbilityInterface.hpp"

class Bombardment : public AbilityInterface {
public:
    Bombardment();
    ~Bombardment() = default;
    void applyAbility() override;
};


#endif //OOP_LABS_BOMBARDMENT_HPP
