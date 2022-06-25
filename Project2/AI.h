#pragma once
#include "FigureMove.h"
#include "Field.h"
#include <deque>

//Класс искусственного интелекта
class AI
{
	//Двусвязная очередь ходов
	//подробнее об ней https://metanit.com/cpp/tutorial/7.8.php
	//Это очередь из всех возможных ходов всех фигур одного цвета.
	std::deque<FigureMove> Moves;

	FigureMove bestMove;

public:
	//Выбрать случайный ход на поле за заданный цвет
	FigureMove* RandomMove(Field* field, int color);

	//Выбрать случайный ход на поле за заданный цвет
	FigureMove* BestMove(Field* field, int color);

	//Добавляет все возможные ходы фигуры в очередь
	void AllFigureMovesToDeque(Figure* figure,Field * field);

	//Собрать список всех доступных ходов
	//Список будет лежать в Moves
	void CreateMoveList(Field* field, int color);
};

