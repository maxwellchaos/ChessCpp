#include "Field.h"
#include "Pawn.h"
#include "Rock.h"
#include "Queen.h"
#include "King.h"
#include "Knight.h"
#include "Bishop.h"

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
	ClearMovesMap();

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
	BlackKing = figure;

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
	WhiteKing = figure;

	//�����
	figure = new Queen(this);
	figure->FigureColor = FigureColors::white;
	Figures[7][3] = figure;

	//���������� ��������� �����
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (Figures[i][j] != nullptr)
			{
				Figures[i][j]->i = i;
				Figures[i][j]->j = j;
			}
		}
	}
}



Field::Field(Field *field)
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
	ClearMovesMap();

	//�����������
	CopyToMe(field);
}


bool Field::CellIsValid(int i, int j)
{
	//��������, ������ �� ���������� ������ � ������� ����
	return (i >= 0) && (j >= 0) && (i < 8) && (j < 8);
}

void Field::ClearMovesMap()
{
	//������������� false ���� ��������� �������
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
		figure->FillMovesMapWithClear(i,j);
	}
	return true;
}

//������� ��� ���������� �������
bool Field::Move(int i, int j)
{
	
	if (Checkmate)
	{
		//��� ��� ���������
		return false;
	}

	//��������� ���� �� ����������
	if (!CellIsValid(i, j))
	{
		return false;
	}

	//������� ��� ����
	Field* oldField = new Field(this);


	//if (CheckTest(Figure::InverseColor( CurrentMoveColor)))
	//{
	//	ClearMovesMap();
	//	//��� ��� ���, ������ ��� ������
	//	return false;
	//}

	

	//������� ������, ���� ���� �����
	if (Figures[i][j] != nullptr)
	{
		delete Figures[i][j];
	}
	
	//����������� ������
	Figures[i][j] = SelectedFigure;
	
	//�������� ��� ��������� ��������� � ������� � ��������� �������
	//������� ������� �� ����������
	Figures[SelectedFigure->i][SelectedFigure->j] = nullptr;
	//����������� ����������
	SelectedFigure->i = i;
	SelectedFigure->j = j;
	//���������� ���������
	SelectedFigure = nullptr;

	//���� ��� ��� ���
	if (CheckTest(Figure::InverseColor( CurrentMoveColor)))
	{
		//��������� �� �����
		CopyToMe(oldField);

		ClearMovesMap();
		//��� ��� ���, ������ ��� ������
		return false;
	}

	delete oldField;

	//��������� ���, ���� �� ����
	CheckTest(CurrentMoveColor);

	//����������� ����
	CurrentMoveColor = Figure::InverseColor(CurrentMoveColor);


	ClearMovesMap();

	return true;
}

//���������� ��� ��������� ���� ������ �����
void Field::GetAllAttackMap(int Color)
{
	//�������� ��� ����
	ClearMovesMap();
	//��������� ��� ������
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			//���� ������ ���� �� ���� ����
			if (Figures[i][j] != nullptr)
			{
				//���� ������ ������� �����
				if (Figures[i][j]->FigureColor == Color)
				{
					//�������� ��� �� ��������� ����� � ����� ����� ��������� ����
					Figures[i][j]->FillAttackMap(i,j);
				}
			}
		}
	}
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

bool Field::CheckTest(int color)
{
	GetAllAttackMap(color);
	if (color != FigureColors::black)
	{
		if (Moves[BlackKing->i][BlackKing->j])
		{
			Check = true;
		}
		else
		{
			Check = false;
		}
	}
	else
	{
		if (Moves[WhiteKing->i][WhiteKing->j])
		{
			Check = true;
		}
		else
		{
			Check = false;
		}
	}
	return Check;
}


void Field::CopyToMe(Field* field)
{
	//����������� ����� 
	CurrentMoveColor = field->CurrentMoveColor;

	//������� ����
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			//������ ������, ���� ��� ����
			if (Figures[i][j] != nullptr)
			{
				delete Figures[i][j];
				//Figures[i][j] = nullptr;
			}

			//������� ������
			if (field->Figures[i][j] != nullptr)
			{
				Figure* figure = field->Figures[i][j];
				if (figure->FigureType == FigureTypes::bishop)
				{
					Figure* newFigure = new Bishop(this);
					newFigure->FigureColor = figure->FigureColor;
					Figures[i][j] = newFigure;
				}
				if (figure->FigureType == FigureTypes::king)
				{
					Figure* newFigure = new King(this);
					newFigure->FigureColor = figure->FigureColor;
					Figures[i][j] = newFigure;

					//���������� ��������� �� �������
					if (figure->FigureColor == FigureColors::black)
					{
						BlackKing = newFigure;
					}
					else
					{
						WhiteKing = newFigure;
					}
				}
				if (figure->FigureType == FigureTypes::knight)
				{
					Figure* newFigure = new Knight(this);
					newFigure->FigureColor = figure->FigureColor;
					Figures[i][j] = newFigure;
				}
				if (figure->FigureType == FigureTypes::pawn)
				{
					Figure* newFigure = new Pawn(this);
					newFigure->FigureColor = figure->FigureColor;
					Figures[i][j] = newFigure;
				}
				if (figure->FigureType == FigureTypes::queen)
				{
					Figure* newFigure = new Queen(this);
					newFigure->FigureColor = figure->FigureColor;
					Figures[i][j] = newFigure;
				}
				if (figure->FigureType == FigureTypes::rock)
				{
					Figure* newFigure = new Rock(this);
					newFigure->FigureColor = figure->FigureColor;
					Figures[i][j] = newFigure;
				}
			}
			else
			{
				Figures[i][j] = nullptr;
			}
		}
	}

	//������� ����� 
	ClearMovesMap();

	//���������� ��������� �����
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (Figures[i][j] != nullptr)
			{
				Figures[i][j]->i = i;
				Figures[i][j]->j = j;
			}
		}
	}
}
