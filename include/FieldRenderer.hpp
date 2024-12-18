#ifndef OOP_LABS_FIELDRENDERER_HPP
#define OOP_LABS_FIELDRENDERER_HPP

#include "structures.hpp"
#include "GameField.hpp"

class FieldRenderer {
public:
    FieldRenderer() = default;
    void showField(std::shared_ptr<GameField> field, bool playerTurn);

};


#endif //OOP_LABS_FIELDRENDERER_HPP
