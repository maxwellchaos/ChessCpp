#include "Pawn.h"

Pawn::Pawn(Field* field)
{
    FigureType = FigureTypes::pawn;
    _field = field;
}
void Pawn::AllMoves(int i, int j)
{
    //очистить массив ходов
    _field->ClearMove();

    //если пешка белая
    if(FigureColor == FigureColors::white)
    {
        if (_field->CellIsValid(i - 1, j))
            if (_field->Figures[i - 1][j] == nullptr)
            {
                _field->Moves[i - 1][j] = true;
                if (i == 6)//если пешка на том месте, где была в начале партии
                {
                    //то может пойти на 2 клетки вперед
                    if (_field->CellIsValid(i - 2, j))
                        if (_field->Figures[i - 2][j] == nullptr)
                            _field->Moves[i - 2][j] = true;
                }
            }
        //атака влево
        if (_field->CellIsValid(i - 1, j - 1))
            if (_field->Figures[i - 1][j - 1] != nullptr)
                if (_field->Figures[i - 1][j - 1]->FigureColor != FigureColor)
                    _field->Moves[i - 1][j - 1] = true;
        //атака вправо
        if (_field->CellIsValid(i - 1, j + 1))
            if (_field->Figures[i - 1][j + 1] != nullptr)
                if (_field->Figures[i - 1][j + 1]->FigureColor != FigureColor)
                    _field->Moves[i - 1][j + 1] = true;
    }
    //если пешка черная
    if (FigureColor == FigureColors::black)
    {
        if (_field->CellIsValid(i + 1, j))
            if (_field->Figures[i + 1][j] == nullptr)
            {
                _field->Moves[i + 1][j] = true;
                if (i == 1)//если пешка на том месте, где была в начале партии
                {
                    //то может пойти на 2 клетки вперед
                    if (_field->CellIsValid(i + 2, j))
                        if (_field->Figures[i + 2][j] == nullptr)
                            _field->Moves[i + 2][j] = true;
                }
            }
        //атака влево
        if (_field->CellIsValid(i + 1, j + 1))
            if (_field->Figures[i + 1][j + 1] != nullptr)
                if (_field->Figures[i + 1][j + 1]->FigureColor != FigureColor)
                    _field->Moves[i + 1][j + 1] = true;
        //атака вправо
        if (_field->CellIsValid(i + 1, j - 1))
            if (_field->Figures[i + 1][j - 1] != nullptr)
                if (_field->Figures[i + 1][j - 1]->FigureColor != FigureColor)
                    _field->Moves[i + 1][j - 1] = true;
    }
}