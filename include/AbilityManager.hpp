#ifndef OOP_LABS_ABILITYMANAGER_HPP
#define OOP_LABS_ABILITYMANAGER_HPP

#include "structures.hpp"
#include "AbilityInterface.hpp"

class AbilityManager {
public:
    AbilityManager();
    ~AbilityManager() = default;
private:
    std::vector<std::shared_ptr<AbilityInterface>> abilities;
};


#endif //OOP_LABS_ABILITYMANAGER_HPP
