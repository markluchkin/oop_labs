#ifndef OOP_LABS_GAME_HPP
#define OOP_LABS_GAME_HPP

#include "ShipManager.hpp"
#include "GameField.hpp"
#include "AbilityManager.hpp"
#include "GameState.hpp"

class Game {
public:
    Game();
    ~Game() = default;
    void startNewGame(std::vector<int> sizes);
    //--------file operations--------/
    void saveGame(const std::string& filename);
    void loadGame(const std::string& filename);

    std::shared_ptr<GameField> getUserField() const;
    std::shared_ptr<GameField> getEnemyField() const;
    std::shared_ptr<AbilityManager> getAbilityManager();
    bool getIsUserGameOver() const;
    bool getIsEnemyGameOver() const;
    void incRoundNumber();
    void resetEnemy();

    // process:
    void userAttackAction(int x, int y);
    void enemyAttackAction();
    // other:
    void checkVictory();
    void printRoundInfo();
    // setups:
    std::pair<int, int> setupFieldAction();
    void placeShipsAction();
    void placeEnemyShipsAction();

private:
    std::shared_ptr<GameState> gameState;
    //bool userTurn;
    bool isUserGameOver;
    bool isEnemyGameOver;
};

#endif //OOP_LABS_GAME_HPP