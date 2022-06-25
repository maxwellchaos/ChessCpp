#pragma once
#include "FigureMove.h"
#include "Field.h"
#include <deque>

//����� �������������� ���������
class AI
{
	//���������� ������� �����
	//��������� �� ��� https://metanit.com/cpp/tutorial/7.8.php
	//��� ������� �� ���� ��������� ����� ���� ����� ������ �����.
	std::deque<FigureMove> Moves;

	FigureMove bestMove;

public:
	//������� ��������� ��� �� ���� �� �������� ����
	FigureMove* RandomMove(Field* field, int color);

	//������� ��������� ��� �� ���� �� �������� ����
	FigureMove* BestMove(Field* field, int color);

	//��������� ��� ��������� ���� ������ � �������
	void AllFigureMovesToDeque(Figure* figure,Field * field);

	//������� ������ ���� ��������� �����
	//������ ����� ������ � Moves
	void CreateMoveList(Field* field, int color);
};

