#pragma once
#include "Figure.h"

//����� ������� ����
class Field
{
public:
	///�� ���� �������� ������ ����� - ������ �����
	///					������ ����� - ������ ��������
	///����� ������ ����� - ����� �������� �� ����� 6-7, ������ �������� �� ����� 0-1

	///��� �� ��� ���������� ���� ������������ ������ i ��� �����
	///												  j ��� ��������

	//��� ���������� ������� � �������
	Figure* WhiteKing = nullptr;
	Figure* BlackKing = nullptr;


	//������ �����
	Figure* Figures[8][8];
	//����� ������ ��������� �����
	bool Moves[8][8];

	//��������� ������
	Figure* SelectedFigure = 0;


	//����� ���� ������ �����
	int CurrentMoveColor = FigureColors::white;

	//��������� ����
	bool Check = false;//���
	bool Checkmate = false;//���


	//����������� ������
	//����� �� ���������� ����������� �����
	Field();

	//����������� �����������
	//������� ����� ������� �����
	Field(Field*field);

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
	void GetAllAttackMap(int Color);

	//�������� �� ��� � ���
	//��� ��������� �����
	bool CheckTest(int color);


	void CopyToMe(Field* field);
};

