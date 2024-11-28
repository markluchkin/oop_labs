#ifndef OOP_LABS_GAME_HPP
#define OOP_LABS_GAME_HPP

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
    friend std::ostream& operator<<(std::ostream& out, const std::shared_ptr<GameState> state);
    friend std::istream& operator>>(std::istream& in, std::shared_ptr<GameState> state);

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


class Game {
public:
    Game();
    ~Game() = default;
    void startNewGame();
private:
    //---------actions---------//
    // setups:
    std::vector<int> setupShipsAction(int h, int w);
    std::pair<int, int> setupFieldAction();
    void placeShipsAction();
    void placeEnemyShipsAction();
    // process:
    void playTurn();
    void userTurnAction();
    void enemyTurnAction();
    void userAttackAction();
    void enemyAttackAction();
    // other:
    void checkVictory();
    void printRoundInfo();
    std::vector<int> parseShipsInput(const std::string& input);

    //--------file operations--------/
    void saveGame(const std::string& filename);
    void loadGame(const std::string& filename);

    std::shared_ptr<GameState> gameState;
    bool userTurn;
    bool isUserGameOver;
    bool isEnemyGameOver;
};

#endif //OOP_LABS_GAME_HPP