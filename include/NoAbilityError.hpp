#ifndef OOP_LABS_NOABILITYERROR_HPP
#define OOP_LABS_NOABILITYERROR_HPP

#include "structures.hpp"

class NoAbilityError : public std::runtime_error{
public:
    NoAbilityError(const std::string &msg) : std::runtime_error(msg){}
};

#endif //OOP_LABS_NOABILITYERROR_HPP
