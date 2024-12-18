#ifndef OOP_LABS_STRUCTURES_HPP
#define OOP_LABS_STRUCTURES_HPP

#include <memory>
#include <iostream>
#include <vector>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <string>
#include <numeric>
#include <queue>
#include <chrono>
#include <random>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <optional>
#include <unordered_map>

enum class Orientation{Vertical, Horizontal};

enum class SegmentState{Intact, Damaged, Destroyed};

enum class CellState{Empty, ContainsShip};

enum class AbilityType{DD, Scan, Bomb};

enum Command {
    Save, Load, Attack, Ability, ShowField, Exit, Unknown
};

enum class StartCommand{ NewGame, LoadGame, Unknown };

#endif //OOP_LABS_STRUCTURES_HPP
