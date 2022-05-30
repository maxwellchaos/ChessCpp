#pragma once
#include "Move.h"
#include "Field.h"
#include <deque>

//����� �������������� ���������
class AI
{
	std::deque<Move> Moves;
	Move bestMove;

public:
	//������� ������ ��� �� ���� �� �������� ����
	Move* BestMove(Field* field, int color);
	void AllFigureMovesToVector(Figure* figure,Field * field);
};

