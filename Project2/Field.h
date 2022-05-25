#pragma once
#include "Figure.h"
#include "Pawn.h"
#include "Rock.h"
#include "Queen.h"
#include "King.h"
#include "Knight.h"
#include "Bishop.h"

// ласс игровое поле
class Field
{
public:
	///¬о всех массивах первое число - номера строк
	///					второе читло - номера столбцов
	///внизу всегда белые - Ѕелые стартуют из строк 6-7, черные стартуют из строк 0-1

	///так же дл€ пон€тности буду использовать индекс i дл€ строк
	///												  j дл€ столбцов

	//массив фигур
	Figure* Figures[8][8];
	//булев массив возможных ходов
	bool Moves[8][8];

	//¬ыбранна€ фигура
	Figure* SelectedFigure = 0;

	int CurrentMove = FigureColors::white;


	// онструктор класса
	//здесь же происходит расстановка фигур
	Field();

	//деструктор
	~Field();

	//проверка действительно ли это поле есть на доске
	bool CellIsValid(int i, int j);

	//ќчистка ходов
	void ClearMove(); 

	//¬ыбрать фигуру
	bool SelectFigure(int i, int j)
};

