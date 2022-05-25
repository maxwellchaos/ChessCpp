#pragma once
#include "Figure.h"
#include "Field.h"

class Rock :
    public Figure
{
public:
    //Конструктор
    Rock(Field* field);
    

    void AllMoves(int i, int j);
   
};

