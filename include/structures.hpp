#ifndef OOP_LABS_STRUCTURES_HPP
#define OOP_LABS_STRUCTURES_HPP

enum class ShipState{Intact, Damaged, Destroyed};

struct Coordinates{
    int x;
    int y;
    bool operator==(const Coordinates& other) const {
        return (x == other.x && y == other.y);
    }
};
#endif //OOP_LABS_STRUCTURES_HPP
