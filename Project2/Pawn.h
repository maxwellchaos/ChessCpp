#pragma once
#include "Figure.h"
class Pawn :
    public Figure
{
public:
    //�����������
    Pawn(Field* field)
    {
        FigureType = FigureTypes::pawn;
        _field = field;
    }

    //
    void AllMoves()
    {

    }
};

