#ifndef OOP_LABS_STRUCTURES_HPP
#define OOP_LABS_STRUCTURES_HPP

#include <memory>
#include <iostream>
#include <vector>
#include "PlaceShipError.hpp"
#include "AttackCellError.hpp"
#include "EmptyFieldError.hpp"

enum class Orientation{Vertical, Horizontal};

enum class SegmentState{Intact, Damaged, Destroyed};

enum class CellState{Unknown, Empty, ContainsShip};

enum class AbilityType{DD, Scan, Bomb};

//struct Coordinates{
//    int x;
//    int y;
//
//    bool operator==(const Coordinates& other) const {
//        return (x == other.x && y == other.y);
//    }
//};

#endif //OOP_LABS_STRUCTURES_HPP
