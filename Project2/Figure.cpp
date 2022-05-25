#include "Figure.h"
#include "Field.h"

//Этот метод общий для нескольких фигур, поэтому он в родительском классе
    //метод для проверки каждой ячейки на отмечание ее как доступной для хода
    //возвращает нужно ли выделять дальше
bool Figure::CheckCell(int i, int j)
{
    if (_field->CellIsValid(i, j))
    {
        Figure* figure = _field->Figures[i][j];
        //если клетка свободная, то помечаем ее доступной для хода
        if (figure == 0)
        {
            _field->Moves[i][j] = true;
            return true;
        }
        //если клетка занята своей фигурой, то дальше уже не считаем
        if (figure->FigureColor == this->FigureColor)
        {
            return false;
        }
        else
        {
            //если клетка занята чужой фигурой, то  помечаем доступной для хода 
            //и дальше уже не считаем
            _field->Moves[i][j] = true;
            return false;
        }
    }
    return false;
}