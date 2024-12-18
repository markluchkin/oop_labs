#include "../include/FieldRenderer.hpp"

FieldRenderer::FieldRenderer(const GameField& gameField)
        : gameField(gameField) {}

void FieldRenderer::render(bool isEnemyField) const {
    std::cout << "  ";
    for (int x = 0; x < gameField.getWidth(); ++x) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    drawBorder();

    for (int y = 0; y < gameField.getHeight(); ++y) {
        std::cout << y << "|";
        drawRow(y, isEnemyField);
        std::cout << "|" << y << std::endl;
    }

    drawBorder();

    std::cout << "  ";
    for (int x = 0; x < gameField.getWidth(); ++x) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

void FieldRenderer::drawBorder() const {
    std::cout << " +";
    for (int x = 0; x < gameField.getWidth(); ++x) {
        std::cout << "--";
    }
    std::cout << "+" << std::endl;
}

void FieldRenderer::drawRow(int row, bool isEnemyField) const {
    for (int x = 0; x < gameField.getWidth(); ++x) {
        CellState state = gameField.getStateAt(x, row);
        if (isEnemyField && state == CellState::ContainsShip) {
            std::cout << " ?"; // Скрываем корабли противника
        } else {
            switch (state) {
                case CellState::Empty:
                    std::cout << "  ";
                    break;
                case CellState::ContainsShip:
                    std::cout << "S ";
                    break;
            }
        }
    }
}