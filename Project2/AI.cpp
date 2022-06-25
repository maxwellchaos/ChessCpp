#include "AI.h"
#include <algorithm>    // std::sort


FigureMove* AI::RandomMove(Field*field,int color)
{
	
	CreateMoveList(field, color);

	//���� ��� �� ���������
	//������� �� ������ ��������� ����� ��� ����
	bool Done = true;
	while (Done)
	{
		//��� ���
		if (Moves.size() == 0)
			return nullptr;


		//������� ��������� �� ��������� ���
		//��������� ��������� ����� ����� �����
		//http://cppstudio.com/post/339/
		int randomNumber = rand() % Moves.size();
		bestMove = Moves[randomNumber];

		//������� ���
		field->SelectFigure(bestMove.StartI, bestMove.StartJ);
		Done = !field->Move(bestMove.FinishI, bestMove.FinishJ);
		
		//���� ��� �� ������
		if (!Done)
		{
			//������� ��� �� �������
			Moves.erase(Moves.begin() + randomNumber);
		}
	}
	return &bestMove;
}

bool CompareFunc(FigureMove i, FigureMove j) 
{ 
	return (i.efficiency < j.efficiency); 
}

FigureMove* AI::BestMove(Field* field, int color)
{

	CreateMoveList(field, color);
	
	//������������� �������
	//��� �������� ��� ���������� � ��������� https://cplusplus.com/reference/algorithm/sort/
	std::sort(Moves.begin(), Moves.end(), CompareFunc);

	//���� ��� �� ���������
	//������� �� ������ ��������� ����� ��� ����
	bool Done = true;
	while (Done)
	{
		//��� ���
		if (Moves.size() == 0)
			return nullptr;

		bestMove = Moves[0];

		//������� ���
		field->SelectFigure(bestMove.StartI, bestMove.StartJ);
		Done = !field->Move(bestMove.FinishI, bestMove.FinishJ);

		//���� ��� �� ������
		if (!Done)
		{
			//������� ��� �� �������
			Moves.erase(Moves.begin());
		}
	}
	return &bestMove;
}

//��������� ��� ��������� ���� ������ � �������
void AI::AllFigureMovesToDeque(Figure* figure,Field *field)
{
	figure->FillMovesMapWithClear(figure->i, figure->j);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (field->Moves[i][j])
			{
				//��������� ��� � ���������� ��� �������������
				FigureMove move;
				move.StartI = figure->i;
				move.StartJ = figure->j;
				move.FinishI = i;
				move.FinishJ = j;

				//������� �������� ���� ������������ �������� ����
				Field* testedField = new Field(field);
				//��������� �� ��� �������
				int oldPosition = testedField->CalcPosition(figure->FigureColor);

				//������� �� ��� ���
				testedField->SelectFigure(move.StartI, move.StartJ);
				bool moveResult = testedField->Move(move.FinishI, move.FinishJ);
				if (!moveResult)
				{
					//���� ������� ��� �� ���������� - �� ��������� ���� ��� � �������
					//������� �������� ���� � ���������� ������ ������ ����
					delete testedField;
					continue;
				}
				
				//��������� ��� �������������
				int newPosition = testedField->CalcPosition(figure->FigureColor);

				move.efficiency = oldPosition - newPosition;

				//�������� ��������� ��������� ��������, ����� ��� ���������� �������������� 
				//��������� ��������� ���. ��� �������� ��������� ����������
				move.efficiency += (double)rand() / (RAND_MAX-1);

				//������� �������� ����
				delete testedField;

				//�������� ��� � �������
				Moves.push_back(move);
			}
		}
	}
}


void AI::CreateMoveList(Field* field, int color)
{
	if (field->Checkmate)
		return;
	Moves.clear();
	//������� ������ ���� ��������� �����

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			Figure* figure = field->Figures[i][j];
			if (figure != nullptr)
			{
				if (figure->FigureColor == color)
				{
					AllFigureMovesToDeque(figure, field);
				}
			}
		}
	}
	return;
}
