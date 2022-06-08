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
	//Выбрать случайный ход на поле за заданный цвет
	Move* RandomMove(Field* field, int color);

	//Выбрать случайный ход на поле за заданный цвет
	Move* BestMove(Field* field, int color);

	//Добавляет все возможные ходы фигуры в очередь
	void AllFigureMovesToDeque(Figure* figure,Field * field);

	//Собрать список всех доступных ходов
	//Список будет лежать в Moves
	void CreateMoveList(Field* field, int color);
};

