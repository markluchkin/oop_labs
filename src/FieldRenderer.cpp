#include "../include/FieldRenderer.hpp"



void FieldRenderer::showField(std::shared_ptr<GameField> field, bool playerTurn) {
    if (playerTurn) {
        std::cout << "============== Your field ==============" << std::endl;
    }
    else {
        std::cout << "============== Computer's field ==============" << std::endl;
    }
    field->printField();
}