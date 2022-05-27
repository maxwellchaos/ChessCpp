#pragma once
#include "Figure.h"
#include "Pawn.h"
#include "Rock.h"
#include "Queen.h"
#include "King.h"
#include "Knight.h"
#include "Bishop.h"

//����� ������� ����
class Field
{
public:
	///�� ���� �������� ������ ����� - ������ �����
	///					������ ����� - ������ ��������
	///����� ������ ����� - ����� �������� �� ����� 6-7, ������ �������� �� ����� 0-1

	///��� �� ��� ���������� ���� ������������ ������ i ��� �����
	///												  j ��� ��������

	//������ �����
	Figure* Figures[8][8];
	//����� ������ ��������� �����
	bool Moves[8][8];

	//��������� ������
	Figure* SelectedFigure = 0;
	int SelectedFigureI = 0;
	int SelectedFigureJ = 0;

	//����� ���� ������ �����
	int CurrentMoveColor = FigureColors::white;

	//��������� ����
	bool Check = false;//���
	bool Checkmate = false;//���


	//����������� ������
	//����� �� ���������� ����������� �����
	Field();

	//����������
	~Field();

	//�������� ������������� �� ��� ���� ���� �� �����
	bool CellIsValid(int i, int j);

	//������� �����
	void ClearMovesMap(); 

	//������� ������
	bool SelectFigure(int i, int j);

	//������� ��� ���������� �������
	bool Move(int i, int j);

	//���������� ��� ��������� ���� ������ �����
	void GetAllattackMap(int Color);
};

