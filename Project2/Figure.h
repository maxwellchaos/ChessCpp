#pragma once
#include "Field.h"

//Абстрактный класс фигуры
class Figure
{
protected:
    Field* _field;

public:
    FigureTypes FigureType;
    FigureColors FigureColor;
    

    //это виртуальный метод, его обязательно нужно переопределить в потомке - у каждой фигуры-потомка
    // для каждой фигуры такой метод будет отмечать разные поля
    //Этот метод отмечает все поля на поле, куда может ходить эта фигура
    virtual void AllMoves() = 0;

};

//Тип фигуры
//Значение фигурф - это ее ценность для вычисления позиции
enum FigureTypes
{
    king = 9000,//король
    queen = 9,//ферзь
    bishop = 3,//слон
    knight = 3,//конь
    rock = 5,//ладья
    pawn = 1//пешка
};

//Цвет фигуры
enum FigureColors
{
    black,
    white 
};

