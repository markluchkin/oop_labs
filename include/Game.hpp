#ifndef OOP_LABS_GAME_HPP
#define OOP_LABS_GAME_HPP

#include "ShipManager.hpp"
#include "GameField.hpp"
#include "AbilityManager.hpp"

class GameState {
public:
    GameState(int width, int height, std::vector<int> shipSizes);

    void resetEnemyState();

    std::shared_ptr<GameField> getUserField();
    std::shared_ptr<GameField> getEnemyField();
    std::shared_ptr<ShipManager> getUserShips() const;
    std::shared_ptr<ShipManager> getEnemyShips() const;
    std::shared_ptr<AbilityManager> getUserAbilityManager() const;

    int getRoundNumber() const;
    void incRoundNumber();

    void save(const std::string& filename);
    void load(const std::string& filename);

    friend std::ostream& operator<<(std::ostream& out, const GameState& state);
    friend std::istream& operator>>(std::istream& in, const GameState& state);

private:
    std::shared_ptr<GameField> userField;
    std::shared_ptr<GameField> enemyField;
    std::shared_ptr<ShipManager> userShips;
    std::shared_ptr<ShipManager> enemyShips;
    std::shared_ptr<AbilityManager> userAbilityManager;

    int fieldWidth;
    int fieldHeight;
    std::vector<int> sizes;
    int roundNumber;
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
    int shipsNum;
    int destroyedUserShipsNum;
    int destroyedEnemyShipsNum;
    int turnNum;
};

#endif //OOP_LABS_GAME_HPP