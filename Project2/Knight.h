#pragma once
#include "Figure.h"
#include "Field.h"

class Knight :
    public Figure
{
public:
    //�����������
    Knight(Field* field)
    {
        FigureType = FigureTypes::knight;
        _field = field;
    }

    //
    void AllMoves(int i, int j)
    {

    }
};

