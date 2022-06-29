#include "Field.h"
#include "Pawn.h"
#include "Rock.h"
#include "Queen.h"
#include "King.h"
#include "Knight.h"
#include "Bishop.h"
#include <stdexcept>

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

//���� ������ ����
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
		return true;
	}
	return false;
}

//������� ��� ���������� �������
bool Field::Move(int i, int j,bool withoutCheckmate)
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

	//������� ������, ���� ���� �����
	if (Figures[i][j] != nullptr)
	{
		delete Figures[i][j];
	}
	//���������
	//������ ������ ����� - ������� ����������� �����
	if (SelectedFigure->FigureType == FigureTypes::king)
	{
		//���� ������ ������ ����� ������ ��� �� ���� ������, �� ��� ���������
		if (abs(SelectedFigure->j - j) > 1)
		{
			//� ����� ������� ������ ������
			if (SelectedFigure->j - j > 0)
			{
				//�����
				Figures[i][3] = Figures[i][0];
				Figures[i][3]->j = 3;
				Figures[i][0] = nullptr;
			}
			else
			{
				//������
				Figures[i][5] = Figures[i][7];
				Figures[i][5]->j = 5;
				Figures[i][7] = nullptr;

			}
		}
	}

	//����������� ������
	Figures[i][j] = SelectedFigure;

	//������� ����� ������
	if (SelectedFigure->FigureType == FigureTypes::pawn)
	{
		if (SelectedFigure->FigureColor == FigureColors::white)
		{
			if (i == 0)
				SelectedFigure->FigureType = FigureTypes::queen;
		}
		else
		{
			if (i == 7)
				SelectedFigure->FigureType = FigureTypes::queen;
		}
	}

	
	
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

	//�� ��������� �� ���
	//��� ����� ��� �������� �� ���, ����� �� ������� � ��������
	if (!withoutCheckmate)
	{
		//�������� �� ���
		CheckmateTest(CurrentMoveColor);
	}
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

//�������� �� ��� ��� ��������� �����
//������ ��������� ����� ��������� ���
bool Field::CheckmateTest(int color)
{
	//�������� �������� �� ���:
	//��������� ��� ��������� ���� ���� ��������� ����� ���������� �����
	//���� ����� ���� ������ ����������� ���, �� ��������� ���
	
	//���� ��������� ���
	int matedColor = Figure::InverseColor(color);

	//���������� �������, ��� ���
	Checkmate = true;

	//��� ���� � ��� �� - �������� ���� ����� ��������� �����
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			Figure* figure = Figures[i][j];
			if(figure!= nullptr)
				if (figure->FigureColor == matedColor)
				{
					//��� ���������� ��� ������ ������ ��������� �����
					
					//�������� ����� ����� ������
					figure->FillMovesMapWithClear(i, j);

					
					//��������� ��� ��������� ���� ������ �� ���������� ����
					//����� ������� ������� �����������, ������� ������ ��� �� �������
					Checkmate = CheckAllMovesFigure(figure, color);
					
					if (!Checkmate)
					{
						//���� ������������ ���
						return false;
					}
				}
		}
	}
	return Checkmate;
}


//��������� ��� ���� ����� ������ � ������� True, ���� ����� ������� ���� ����� ���
bool Field::CheckAllMovesFigure(Figure* figure,int color)
{
	//���� ��� �������� ������ ����
	Field* oneMoveField = new Field();

	//����� ��� ���� ����� ����� ������
	//��� ���� ����� � �����
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (Moves[i][j])
			{
				// ����������� ����
				oneMoveField->CopyToMe(this);
				//����� ����, ����� ����� ���� ������
				oneMoveField->CurrentMoveColor = Figure::InverseColor(oneMoveField->CurrentMoveColor);

				//������� ���
				oneMoveField->SelectFigure(figure->i, figure->j);
				
				oneMoveField->Move(i, j,true);
				//��������� ���
				if (!oneMoveField->CheckTest(color))
				{
					return false;
				}
			}
		}
	}
	return true;
}

//���������� ������� ��������� ����� �� �����
int Field::CalcPosition(int color)
{

	int position = 0;
	//������� ��� ���� ����� ��������� �����
	//������� ��� ���� ����� ���������� �����
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (Figures[i][j]!= nullptr)
			{
				if (Figures[i][j]->FigureColor == color)
				{
					position += Figures[i][j]->FigureType;
				}
				else
				{
					position -= Figures[i][j]->FigureType;
				}

			}
		}
	}
	return position;
}
