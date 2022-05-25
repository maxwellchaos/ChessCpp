#include "Rock.h"

Rock::Rock(Field* field)
{
    FigureType = FigureTypes::rock;
    _field = field;
}

//метод дл€ проверки каждой €чейки на отмечание ее
//возвращает нужно ли выдел€ть дальше
bool Rock::CheckCell(int i, int j)
{
    if (_field->CellIsValid(i, j))
    {
        Figure* figure = _field->Figures[i][j];
        //если клетка свободна€, то помечаем ее доступной дл€ хода
        if (figure == 0)
        {
            _field->Moves[i][j] = true;
            return true;
        }
        //если клетка зан€та своей фигурой, то дальше уже не считаем
        if (figure->FigureColor == this->FigureColor)
        {
            return false;
        }
        else
        {
            //если клетка зан€та чужой фигурой, то  помечаем доступной дл€ хода 
            //и дальше уже не считаем
            _field->Moves[i][j] = true;
            return false;
        }
    }
    return false;
}

void Rock::AllMoves(int i, int j)
{
    _field->ClearMove();
    //¬низ
    for (int x = i+1; x < 8; x++)
    {
        if (CheckCell(x, j))
        {
            continue;
        }
        else
        {
            break;
        }
    }
    //¬верх
    for (int x = i-1; x >= 0; x--)
    {
        if (CheckCell(x, j))
        {
            continue;
        }
        else
        {
            break;
        }
    }
    //¬право
    for (int x = j+1; x < 8; x++)
    {
        if (CheckCell(i, x))
        {
            continue;
        }
        else
        {
            break;
        }
    }
    //¬лево
    for (int x = j-1; x >= 0; x--)
    {
        if (CheckCell(i, x))
        {
            continue;
        }
        else
        {
            break;
        }
    }
}