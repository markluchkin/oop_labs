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
    void startNewGame();
    //--------file operations--------/
    void saveGame(const std::string& filename);
    void loadGame(const std::string& filename);

    std::shared_ptr<GameField> getUserField() const;
    std::shared_ptr<GameField> getEnemyField() const;
    // process:
    void playTurn();
    void userTurnAction();
    void enemyTurnAction();
    void userAttackAction();
    void enemyAttackAction();
private:
    //---------actions---------//
    // setups:
    std::vector<int> setupShipsAction(int h, int w);
    std::pair<int, int> setupFieldAction();
    void placeShipsAction();
    void placeEnemyShipsAction();

    // other:
    void checkVictory();
    void printRoundInfo();
    std::vector<int> parseShipsInput(const std::string& input);

    std::shared_ptr<GameState> gameState;
    bool userTurn;
    bool isUserGameOver;
    bool isEnemyGameOver;
};

#endif //OOP_LABS_GAME_HPP