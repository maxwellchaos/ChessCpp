#pragma once
#include "Move.h"
#include "Field.h"
#include <deque>

//����� �������������� ���������
class AI
{
	//���������� ������� �����
	//��������� �� ��� https://metanit.com/cpp/tutorial/7.8.php
	//��� ������� �� ���� ��������� ����� ���� ����� ������ �����.
	std::deque<Move> Moves;

	Move bestMove;

public:
	//������� ��������� ��� �� ���� �� �������� ����
	Move* RandomMove(Field* field, int color);

	//������� ��������� ��� �� ���� �� �������� ����
	Move* BestMove(Field* field, int color);

	//��������� ��� ��������� ���� ������ � �������
	void AllFigureMovesToDeque(Figure* figure,Field * field);

	//������� ������ ���� ��������� �����
	//������ ����� ������ � Moves
	void CreateMoveList(Field* field, int color);
};

