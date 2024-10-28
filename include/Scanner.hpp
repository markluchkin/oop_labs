#ifndef OOP_LABS_SCANNER_HPP
#define OOP_LABS_SCANNER_HPP

#include "structures.hpp"
#include "AbilityInterface.hpp"

class Scanner : public AbilityInterface{
public:
    Scanner();
    ~Scanner() = default;
    void applyAbility() override;
};


#endif //OOP_LABS_SCANNER_HPP
