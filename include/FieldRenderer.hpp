#ifndef OOP_LABS_FIELDRENDERER_HPP
#define OOP_LABS_FIELDRENDERER_HPP

#include "structures.hpp"
#include "GameField.hpp"

class FieldRenderer {
public:
    FieldRenderer(const GameField& gameField);

    void render(bool isEnemyField = false) const;

private:
    const GameField& gameField;

    void drawBorder() const;
    void drawRow(int row, bool isEnemyField) const;

};


#endif //OOP_LABS_FIELDRENDERER_HPP
