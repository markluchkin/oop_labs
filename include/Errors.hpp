#ifndef OOP_LABS_ERRORS_HPP
#define OOP_LABS_ERRORS_HPP

#include "structures.hpp"

class AttackError : public std::runtime_error{
public:
    AttackError(const std::string &msg) : std::runtime_error(msg){}
};

class EmptyFieldError : public std::runtime_error{
public:
    EmptyFieldError(const std::string &msg) : std::runtime_error(msg){}
};

class NoAbilityError : public std::runtime_error{
public:
    NoAbilityError(const std::string &msg) : std::runtime_error(msg){}
};

class PlaceShipError : public std::runtime_error{
public:
    PlaceShipError(const std::string &msg) : std::runtime_error(msg){}
};

class CoordinatesOutOfRangeError : public std::runtime_error{
public:
    CoordinatesOutOfRangeError(const std::string &msg) : std::runtime_error(msg){}
};


#endif //OOP_LABS_ERRORS_HPP
