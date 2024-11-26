#ifndef OOP_LABS_SCANNER_HPP
#define OOP_LABS_SCANNER_HPP

#include "AbilityInterface.hpp"
#include "CoordsOutOfRangeError.hpp"

class Scanner : public AbilityInterface{
public:
    ~Scanner() = default;
    void applyAbility(GameField &field) override;
};


#endif //OOP_LABS_SCANNER_HPP
