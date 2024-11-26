#ifndef OOP_LABS_ATTACKERROR_HPP
#define OOP_LABS_ATTACKERROR_HPP

#include "structures.hpp"

class AttackError : public std::runtime_error{
public:
    AttackError(const std::string &msg) : std::runtime_error(msg){}
};


#endif //OOP_LABS_ATTACKERROR_HPP
