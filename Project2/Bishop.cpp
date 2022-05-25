#include "Bishop.h"

Bishop::Bishop(Field* field)
{
    FigureType = FigureTypes::bishop;
    _field = field;
}



void Bishop::AllMoves(int i, int j)
{
    _field->ClearMove();
    for (int x = i + 1, y = j+1; x < 8; x++,y++)
    {
        if (CheckCell(x, y))
            continue;
        else
            break;
    }
    for (int x = i - 1, y = j + 1; x < 8; x--, y++)
    {
        if (CheckCell(x, y))
            continue;
        else
            break;
    }
    for (int x = i + 1, y = j - 1; x < 8; x++, y--)
    {
        if (CheckCell(x, y))
            continue;
        else
            break;
    }
    for (int x = i - 1, y = j - 1; x < 8; x--, y--)
    {
        if (CheckCell(x, y))
            continue;
        else
            break;
    }
}