#pragma once
#include "Figure.h"
#include "Field.h"

class Knight :
    public Figure
{
public:
    //Конструктор
    Knight(Field* field);

    //
    void AllMoves(int i, int j);
};

