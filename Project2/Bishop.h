#pragma once
#include "Figure.h"
#include "Field.h"

class Bishop :
    public Figure
{
public:
    //Конструктор
    Bishop(Field* field)
    {
        FigureType = FigureTypes::bishop;
        _field = field;
    }

    
    void AllMoves(int i, int j);
   
};

