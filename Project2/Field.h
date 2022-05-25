#pragma once
#include "Figure.h"
#include "Pawn.h"
#include "Rock.h"
#include "Queen.h"
#include "King.h"
#include "Knight.h"
#include "Bishop.h"

//Класс игровое поле
class Field
{
public:
	///Во всех массивах первое число - номера строк
	///					второе читло - номера столбцов
	///внизу всегда белые - Белые стартуют из строк 6-7, черные стартуют из строк 0-1

	///так же для понятности буду использовать индекс i для строк
	///												  j для столбцов

	//массив фигур
	Figure* Figures[8][8];
	//булев массив возможных ходов
	bool Moves[8][8];

	//Выбранная фигура
	Figure* SelectedFigure = 0;
	int SelectedFigureI = 0;
	int SelectedFigureJ = 0;

	int CurrentMoveColor = FigureColors::white;


	//Конструктор класса
	//здесь же происходит расстановка фигур
	Field();

	//деструктор
	~Field();

	//проверка действительно ли это поле есть на доске
	bool CellIsValid(int i, int j);

	//Очистка ходов
	void ClearMove(); 

	//Выбрать фигуру
	bool SelectFigure(int i, int j);

	//Сделать ход выделенной фигурой
	bool Move(int i, int j);
};

