#ifndef OOP_LABS_CUSTOMEXCEPTIONS_HPP
#define OOP_LABS_CUSTOMEXCEPTIONS_HPP

#include "structures.hpp"

class InvalidPlacementException : public std::runtime_error {
public:
    InvalidPlacementException(const std::string& message)
            : std::runtime_error("Invalid Placement: " + message) {}
};

class OutOfBoundsAttackException : public std::out_of_range {
public:
    OutOfBoundsAttackException(const std::string& message)
            : std::out_of_range("Out of Bounds Attack: " + message) {}
};

class NoAbilityAvailableException : public std::logic_error {
public:
    NoAbilityAvailableException()
            : std::logic_error("No Ability Available to Apply") {}
};

class SegmentAlreadyDestroyedException : public std::logic_error {
public:
    SegmentAlreadyDestroyedException()
            : std::logic_error("Cannot damage a destroyed segment.") {}
};

class InvalidSegmentIndexException : public std::out_of_range {
public:
    InvalidSegmentIndexException(int index)
            : std::out_of_range("Invalid Segment Index: " + std::to_string(index) + ".") {}
};

class NoAbilityException : public std::runtime_error {
public:
    NoAbilityException() : std::runtime_error("No abilities available.") {}
};

#endif //OOP_LABS_CUSTOMEXCEPTIONS_HPP
