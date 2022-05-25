#include "Field.h"

Field::Field()
{
	//������� ����
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			Figures[i][j] = 0;
		}
	}

	//������� ����� 
	ClearMove();

	//����� ������ � ���������� ������
	Figure* figure;


	//����������� �����
	//������
	//�����
	for (int j = 0; j < 8; j++)
	{
		figure = new Pawn(this);
		figure->FigureColor = FigureColors::black;
		Figures[1][j] = figure;
	}

	//�����
	figure = new Rock(this);
	figure->FigureColor = FigureColors::black;
	Figures[0][0] = figure;

	figure = new Rock(this);
	figure->FigureColor = FigureColors::black;
	Figures[0][7] = figure;

	//����
	figure = new Knight(this);
	figure->FigureColor = FigureColors::black;
	Figures[0][1] = figure;

	figure = new Knight(this);
	figure->FigureColor = FigureColors::black;
	Figures[0][6] = figure;

	//�����
	figure = new Bishop(this);
	figure->FigureColor = FigureColors::black;
	Figures[0][2] = figure;

	figure = new Bishop(this);
	figure->FigureColor = FigureColors::black;
	Figures[0][5] = figure;

	//������
	figure = new King(this);
	figure->FigureColor = FigureColors::black;
	Figures[0][4] = figure;

	//�����
	figure = new Queen(this);
	figure->FigureColor = FigureColors::black;
	Figures[0][3] = figure;

	//�����
	for (int j = 0; j < 8; j++)
	{
		figure = new Pawn(this);
		figure->FigureColor = FigureColors::white;
		Figures[6][j] = figure;
	}

	//�����
	figure = new Rock(this);
	figure->FigureColor = FigureColors::white;
	Figures[7][0] = figure;

	figure = new Rock(this);
	figure->FigureColor = FigureColors::white;
	Figures[7][7] = figure;

	//����
	figure = new Knight(this);
	figure->FigureColor = FigureColors::white;
	Figures[7][1] = figure;

	figure = new Knight(this);
	figure->FigureColor = FigureColors::white;
	Figures[7][6] = figure;

	//�����
	figure = new Bishop(this);
	figure->FigureColor = FigureColors::white;
	Figures[7][2] = figure;

	figure = new Bishop(this);
	figure->FigureColor = FigureColors::white;
	Figures[7][5] = figure;

	//������
	figure = new King(this);
	figure->FigureColor = FigureColors::white;
	Figures[7][4] = figure;

	//�����
	figure = new Queen(this);
	figure->FigureColor = FigureColors::white;
	Figures[7][3] = figure;

}

bool Field::CellIsValid(int i, int j)
{
	//��������, ������ �� ���������� ������ � ������� ����
	return (i >= 0) && (j >= 0) && (i < 8) && (j < 8);
}

void Field::ClearMove()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			Moves[i][j] = false;
		}
	}
}
//������� ������
bool Field::SelectFigure(int i, int j)
{
	//���� ���������� �� �������� - ������� �� ������� ����
	//�� �� ������ ������
	if (!CellIsValid(i, j))
		return false;

	//���� � ��������� ���� ��� ������
	//�� �� ������ ������
	Figure* figure = Figures[i][j];
	if (figure == nullptr)
		return false;

	//���� ������� ������ ���� �����, ������� �����
	//�� ����� ����� ��������� �����
	if (figure->FigureColor == CurrentMoveColor)
	{
		SelectedFigure = figure;
		SelectedFigureI = i;
		SelectedFigureJ = j;
		figure->AllMoves(i,j);
	}
	return true;
}

//������� ��� ���������� �������
bool Field::Move(int i, int j)
{
	//��������� ���� �� ����������
	if (!CellIsValid(i, j))
		return false;

	//������� ������, ���� ���� �����
	if (Figures[i][j] != nullptr)
	{
		delete Figures[i][j];
	}
	
	//����������� ������
	Figures[i][j] = SelectedFigure;
	
	//�������� ��� ���������
	Figures[SelectedFigureI][SelectedFigureJ] = nullptr;
	SelectedFigure = nullptr;

	//����������� ����
	if (CurrentMoveColor == FigureColors::black)
	{
		CurrentMoveColor = FigureColors::white;
	}
	else
	{
		CurrentMoveColor = FigureColors::black;
	}

	ClearMove();
	return true;
}

//����������
Field::~Field()
{
	//������� ��� ������
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (Figures[i][j] != nullptr)
			{
				//������� ������
				delete Figures[i][j];
			}
		}
	}
}