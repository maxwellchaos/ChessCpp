#include "Knight.h"

Knight::Knight(Field* field)
{
    FigureType = FigureTypes::knight;
    _field = field;
}


void Knight::AllMoves(int i, int j)
{
    int x;
    int y;

    x = i + 2;
    y = j + 1;
    CheckCell(x, y);

    x = i - 2;
    y = j + 1;
    CheckCell(x, y);

    x = i + 2;
    y = j - 1;
    CheckCell(x, y);

    x = i - 2;
    y = j - 1;
    CheckCell(x, y);


    x = i + 1;
    y = j + 2;
    CheckCell(x, y);

    x = i - 1;
    y = j + 2;
    CheckCell(x, y);

    x = i + 1;
    y = j - 2;
    CheckCell(x, y);

    x = i - 1;
    y = j - 2;
    CheckCell(x, y);

}