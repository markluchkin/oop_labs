#ifndef OOP_LABS_SCANNER_HPP
#define OOP_LABS_SCANNER_HPP

#include "AbilityInterface.hpp"
#include "CoordsOutOfRangeError.hpp"

class Scanner : public AbilityInterface{
public:
    ~Scanner() = default;
    void applyAbility(GameField &field, std::optional<int>x=std::nullopt, std::optional<int>y=std::nullopt) override;
    AbilityType getAbilityType() override;
private:
    int x;
    int y;
};


#endif //OOP_LABS_SCANNER_HPP
