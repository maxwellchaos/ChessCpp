#pragma once
#include "Figure.h"
#include "Field.h"

class Queen :
    public Figure
{
public:
    //�����������
    Queen(Field* field)
    {
        FigureType = FigureTypes::queen;
        _field = field;
    }

    //
    void AllMoves(int i, int j)
    {

    }
};

