#ifndef OOP_LABS_INPUTHANDLER_HPP
#define OOP_LABS_INPUTHANDLER_HPP

#include "structures.hpp"
#include "File.hpp"

class InputHandler {
public:
    InputHandler();
    void init(const std::string& filename = "commands.txt");
    StartCommand getStartCommandForKey(int key) const;
    Command getCommandForKey(char key) const;
    char getKeyForCommand(Command cmd) const;
    void printMappings() const;

    StartCommand getStartCommand();
    Command getCommand();

    std::vector<int> getSizes(int n);
    int getShipsNum();
    std::vector<int> getCoordinates();
    int getX();
    int getY();
    std::string getFileName();

private:
    void loadFromFile(const std::string& filename = "commands.txt");
    void setDefaultCommands();
    std::unordered_map<char, Command> keyToCommand;  // Соответствие клавиша -> команда
    std::unordered_map<Command, char> commandToKey;  // Соответствие команда -> клавиша
    Command stringToCommand(const std::string& commandStr) const;
    std::string commandToString(Command cmd) const;
};


#endif //OOP_LABS_INPUTHANDLER_HPP
