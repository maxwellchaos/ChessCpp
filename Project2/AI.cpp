#include "AI.h"


Move* AI::BestMove(Field*field,int color)
{
	if (field->Checkmate)
		return nullptr;
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
					AllFigureMovesToVector(figure, field);
				}
			}
		}
	}
	

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

//��������� ��� ��������� ���� ������ � ������
void AI::AllFigureMovesToVector(Figure* figure,Field *field)
{
	figure->FillMovesMapWithClear(figure->i, figure->j);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (field->Moves[i][j])
			{
				Move move;
				move.StartI = figure->i;
				move.StartJ = figure->j;
				move.FinishI = i;
				move.FinishJ = j;
				Moves.push_back(move);
			}
		}
	}
}
