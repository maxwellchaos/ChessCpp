#include "Rock.h"

Rock::Rock(Field* field)
{
    FigureType = FigureTypes::rock;
    _field = field;
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