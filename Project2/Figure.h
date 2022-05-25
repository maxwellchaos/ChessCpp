#pragma once

class Field;

//Абстрактный класс фигуры
class Figure
{
public:
    class Field* _field = nullptr;


    int FigureType;
    int FigureColor;
    

    //это виртуальный метод, его обязательно нужно переопределить в потомке - у каждой фигуры-потомка
    // для каждой фигуры такой метод будет отмечать разные поля
    //Этот метод отмечает все поля на поле, куда может ходить эта фигура
    //Принимает координаты фигуры
    virtual void AllMoves(int i,int j) = 0;

};

//Тип фигуры
//Значение фигурф - это ее ценность для вычисления позиции
enum FigureTypes
{
    king = 9000,//король
    queen = 90,//ферзь
    bishop = 35,//слон
    knight = 30,//конь
    rock = 50,//ладья
    pawn = 10//пешка
};

//Цвет фигуры
enum FigureColors
{
    black,
    white 
};

