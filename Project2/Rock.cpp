#include "Rock.h"

Rock::Rock(Field* field)
{
    FigureType = FigureTypes::rock;
    _field = field;
}

void Rock::AllMoves(int i, int j)
{
    _field->ClearMove();
    //Вниз
    for (int x = i; x < 8; x++)
    {
        if (_field->CellIsValid(x, j))
        {
            Figure* figure = _field->Figures[x][j];
            //если клетка свободная, то помечаем ее доступной для хода
            if (figure == 0)
            {
                _field->Moves[x][j] = true;
                continue;
            }
            //если клетка занята своей фигурой, то дальше уже не считаем
            if (figure->FigureColor == this->FigureColor)
            {
                break;
            }
            else
            {
                //если клетка занята чужой фигурой, то  помечаем доступной для хода 
                //и дальше уже не считаем
                _field->Moves[x][j] = true;
                break;
            }
        }
    }
    //Вверх
    for (int x = i; x >= 0; x--)
    {
        if (_field->CellIsValid(x, j))
        {
            Figure* figure = _field->Figures[x][j];
            //если клетка свободная, то помечаем ее доступной для хода
            if (figure == 0)
            {
                _field->Moves[x][j] = true;
                continue;
            }
            //если клетка занята своей фигурой, то дальше уже не считаем
            if (figure->FigureColor == this->FigureColor)
            {
                break;
            }
            else
            {
                //если клетка занята чужой фигурой, то  помечаем доступной для хода 
                //и дальше уже не считаем
                _field->Moves[x][j] = true;
                break;
            }
        }
    }
    //Вправо
    for (int x = j; x < 8; x++)
    {
        if (_field->CellIsValid(x, j))
        {
            Figure* figure = _field->Figures[x][j];
            //если клетка свободная, то помечаем ее доступной для хода
            if (figure == 0)
            {
                _field->Moves[x][j] = true;
                continue;
            }
            //если клетка занята своей фигурой, то дальше уже не считаем
            if (figure->FigureColor == this->FigureColor)
            {
                break;
            }
            else
            {
                //если клетка занята чужой фигурой, то  помечаем доступной для хода 
                //и дальше уже не считаем
                _field->Moves[x][j] = true;
                break;
            }
        }
    }
    //Влево
    for (int x = j; x >= 0; x--)
    {
        if (_field->CellIsValid(x, j))
        {
            Figure* figure = _field->Figures[x][j];
            //если клетка свободная, то помечаем ее доступной для хода
            if (figure == 0)
            {
                _field->Moves[x][j] = true;
                continue;
            }
            //если клетка занята своей фигурой, то дальше уже не считаем
            if (figure->FigureColor == this->FigureColor)
            {
                break;
            }
            else
            {
                //если клетка занята чужой фигурой, то  помечаем доступной для хода 
                //и дальше уже не считаем
                _field->Moves[x][j] = true;
                break;
            }
        }
    }
}