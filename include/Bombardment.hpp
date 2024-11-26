#ifndef OOP_LABS_BOMBARDMENT_HPP
#define OOP_LABS_BOMBARDMENT_HPP

#include "structures.hpp"
#include "AbilityInterface.hpp"
#include <cstdlib>
#include <ctime>

class Bombardment : public AbilityInterface {
public:
    ~Bombardment() = default;
    void applyAbility(GameField &field) override;
};


#endif //OOP_LABS_BOMBARDMENT_HPP
