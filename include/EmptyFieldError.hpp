#ifndef OOP_LABS_EMPTYFIELDERROR_HPP
#define OOP_LABS_EMPTYFIELDERROR_HPP

#include <iostream>

class EmptyFieldError : public std::runtime_error{
public:
    EmptyFieldError(const std::string &msg) : std::runtime_error(msg){}
};

#endif //OOP_LABS_EMPTYFIELDERROR_HPP
