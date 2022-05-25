#pragma once
#include "Figure.h"
#include "Field.h"

class Bishop :
    public Figure
{
public:
    //Конструктор
    Bishop(Field* field);

    void AllMoves(int i, int j);
   
};

