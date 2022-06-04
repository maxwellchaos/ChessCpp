#pragma once
#include "Move.h"
#include "Field.h"
#include <deque>

//Класс искусственного интелекта
class AI
{
	//Двусвязная очередь ходов
	//подробнее об ней https://metanit.com/cpp/tutorial/7.8.php
	//Это очередь из всех возможных ходов всех фигур одного цвета.
	std::deque<Move> Moves;

	Move bestMove;

public:
	//Выбрать лучший ход на поле за заданный цвет
	Move* BestMove(Field* field, int color);
	void AllFigureMovesToVector(Figure* figure,Field * field);
};

