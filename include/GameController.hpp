#ifndef OOP_LABS_GAMECONTROLLER_HPP
#define OOP_LABS_GAMECONTROLLER_HPP

#include "structures.hpp"
#include "Game.hpp"
#include "FieldRenderer.hpp"
#include "InputHandler.hpp"
template <typename InputHandlerType, typename FieldRendererType>
class GameController {
public:
    GameController()
            : game(std::make_shared<Game>()),
              inputHandler(std::make_shared<InputHandlerType>()),
              fieldRenderer(std::make_shared<FieldRendererType>()) {};
    ~GameController() = default;

    void init();
    void round();
    void startGame();

private:
    void executeStartCommand(StartCommand cmd);
    void executeCommand(Command cmd);
    std::shared_ptr<Game> game;
    std::shared_ptr<InputHandlerType> inputHandler;
    std::shared_ptr<FieldRendererType> fieldRenderer;

};


#endif //OOP_LABS_GAMECONTROLLER_HPP
