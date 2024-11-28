#ifndef OOP_LABS_GAMESTATE_HPP
#define OOP_LABS_GAMESTATE_HPP

#include "ShipManager.hpp"
#include "GameField.hpp"
#include "AbilityManager.hpp"

class GameState {
public:
    GameState(int width, int height, std::vector<int> shipSizes);

    //--------getters--------/
    std::shared_ptr<GameField> getUserField();
    std::shared_ptr<GameField> getEnemyField();
    std::shared_ptr<ShipManager> getUserShips() const;
    std::shared_ptr<ShipManager> getEnemyShips() const;
    std::shared_ptr<AbilityManager> getUserAbilityManager() const;
    int getRoundNumber() const;
    int getShipsNum() const;
    int getFieldHeight() const;
    int getFieldWidth() const;
    int getDestroyedUserShipsNum() const;
    int getDestroyedEnemyShipsNum() const;

    //--------setters--------/
    void setUserGameField(std::shared_ptr<GameField> field);
    void setEnemyGameField(std::shared_ptr<GameField> field);
    void setUserShips(std::shared_ptr<ShipManager> shipManager);
    void setEnemyShips(std::shared_ptr<ShipManager> shipManager);
    void setUserAbilities(std::shared_ptr<AbilityManager> abilityManager);
    void setFieldWidth(int w);
    void setFieldHeight(int h);
    void setShipSizes(std::vector<int> sizes_);
    void setShipsNum(int num);

    //--------file operations--------/
    friend std::ostream& operator<<(std::ostream& out, const GameState& state);
    friend std::istream& operator>>(std::istream& in, GameState& state);

    void save(const std::string& filename);
    void load(const std::string& filename);

    //--------file operations--------/
    std::vector<std::string> splitString(const std::string& line);
    void resetEnemyState();
    void incRoundNumber();
    void incDestroyedUserShipsNum();
    void incDestroyedEnemyShipsNum();

private:
    int fieldWidth;
    int fieldHeight;
    std::vector<int> sizes;
    int roundNumber;
    int shipsNum;
    int destroyedUserShipsNum;
    int destroyedEnemyShipsNum;

    std::shared_ptr<GameField> userField;
    std::shared_ptr<GameField> enemyField;
    std::shared_ptr<ShipManager> userShips;
    std::shared_ptr<ShipManager> enemyShips;
    std::shared_ptr<AbilityManager> userAbilityManager;
};




#endif //OOP_LABS_GAMESTATE_HPP
