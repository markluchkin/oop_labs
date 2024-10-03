#ifndef OOP_LABS_STRUCTURES_HPP
#define OOP_LABS_STRUCTURES_HPP

enum class Orientation{Vertical, Horizontal};

enum class ShipState{Intact, Damaged, Destroyed};

enum class SegmentState{Intact, Damaged, Destroyed};

enum class CellState{Unknown, Empty, ContainsShip};

struct Coordinates{
    int x;
    int y;
    bool operator==(const Coordinates& other) const {
        return (x == other.x && y == other.y);
    }
};

struct ShipSegment{
    int hp;
    Coordinates coordinates;
    SegmentState segmentState;
};

struct CellSegment{
    Coordinates coords;
    CellState cellState;
    std::shared_ptr<ShipSegment>;
};

#endif //OOP_LABS_STRUCTURES_HPP
