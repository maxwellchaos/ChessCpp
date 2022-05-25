#pragma once
#include "Figure.h"
#include "Field.h"

class Rock :
    public Figure
{
private:
    //метод для проверки каждой ячейки на отмечание ее
    //возвращает нужно ли выделять дальше
    bool CheckCell(int i, int j);
public:
    //Конструктор
    Rock(Field* field);
    

    void AllMoves(int i, int j);
   
};

