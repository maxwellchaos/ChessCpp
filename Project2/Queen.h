#pragma once
#include "Figure.h"
#include "Field.h"

class Queen :
    public Figure
{
public:
    //�����������
    Queen(Field* field);

    void AllMoves(int i, int j);
};

