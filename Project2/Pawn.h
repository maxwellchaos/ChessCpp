#pragma once
#include "Field.h"
#include "Figure.h"


class Pawn :
    public Figure
{
public:
    //Конструктор
    Pawn(Field* field);

    void AllMoves(int i, int j);
    
};

