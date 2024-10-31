#ifndef OOP_LABS_PLACESHIPERROR_HPP
#define OOP_LABS_PLACESHIPERROR_HPP

#include "structures.hpp"

class PlaceShipError : public std::runtime_error{
public:
    PlaceShipError(const std::string &msg) : std::runtime_error(msg){}
};


#endif //OOP_LABS_PLACESHIPERROR_HPP
