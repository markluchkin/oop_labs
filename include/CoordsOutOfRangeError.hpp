#ifndef OOP_LABS_COORDSOUTOFRANGEERROR_HPP
#define OOP_LABS_COORDSOUTOFRANGEERROR_HPP

#include "structures.hpp"

class CoordinatesOutOfRangeError : public std::runtime_error{
public:
    CoordinatesOutOfRangeError(const std::string &msg) : std::runtime_error(msg){}
};


#endif //OOP_LABS_COORDSOUTOFRANGEERROR_HPP
