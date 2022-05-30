#pragma once
#include "Move.h"
#include "Field.h"
#include <deque>

//Класс искусственного интелекта
class AI
{
	std::deque<Move> Moves;
	Move bestMove;

public:
	//Выбрать лучший ход на поле за заданный цвет
	Move* BestMove(Field* field, int color);
	void AllFigureMovesToVector(Figure* figure,Field * field);
};

