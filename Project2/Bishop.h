#pragma once
#include "Figure.h"
#include "Field.h"

class Bishop :
    public Figure
{
public:
    //�����������
    Bishop(Field* field)
    {
        FigureType = FigureTypes::bishop;
        _field = field;
    }

    
    void AllMoves(int i, int j);
   
};

