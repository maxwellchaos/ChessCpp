#pragma once
#include "Figure.h"
#include "Field.h"

class King :
    public Figure
{
public:
    //�����������
    King(Field* field)
    {
        FigureType = FigureTypes::king;
        _field = field;
    }

    //
    void AllMoves(int i, int j)
    {

    }
};

