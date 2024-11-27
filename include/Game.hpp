#ifndef OOP_LABS_GAME_HPP
#define OOP_LABS_GAME_HPP

#include "ShipManager.hpp"
#include "GameField.hpp"
#include "AbilityManager.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <numeric>

class GameState {
public:
    GameState(int width, int height, std::vector<int> shipSizes);

    std::shared_ptr<GameField> getUserField() const;
    std::shared_ptr<GameField> getEnemyField() const;
    std::shared_ptr<ShipManager> getUserShips() const;
    std::shared_ptr<ShipManager> getEnemyShips() const;
    std::shared_ptr<AbilityManager> getUserAbilityManager() const;

    int getRoundNumber() const;
    void incRoundNumber();

    void save();
    void load();

    friend std::ostream& operator<<(std::ostream& out, const GameState& state);
    friend std::istream& operator>>(std::istream& in, const GameState& state);

private:
    std::shared_ptr<GameField> userField;
    std::shared_ptr<GameField> enemyField;
    std::shared_ptr<ShipManager> userShips;
    std::shared_ptr<ShipManager> enemyShips;
    std::shared_ptr<AbilityManager> userAbilityManager;

    int roundNumber;
};


class Game {
public:
    Game();
    ~Game() = default;
private:
    void startNewGame();

    //---------actions---------//
    // setups:
    std::vector<int> setupShipsAction(int h, int w);
    std::pair<int, int> setupFieldAction();
    void placeShipsAction();
    void placeEnemyShipsAction();
    // process:
    void userTurnAction();
    void enemyTurnAction();
    void userAttackAction();
    void enemyAttackAction();

    std::vector<int> parseShipsInput(const std::string& input);

    //--------file operations--------/
    void saveGame();
    void LoadGame();

    std::shared_ptr<GameState> gameState;
    bool userTurn;
};


#endif //OOP_LABS_GAME_HPP
