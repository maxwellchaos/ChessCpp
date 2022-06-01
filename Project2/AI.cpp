#include "AI.h"


Move* AI::BestMove(Field*field,int color)
{
	if (field->Checkmate)
		return nullptr;
	Moves.clear();
	//Собрать список всех возможных ходов
	
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
	

	//пока ход не получится
	//Сделано на случай ошибочных ходов при шахе
	bool Done = true;
	while (Done)
	{
		//Это мат
		if (Moves.size() == 0)
			return nullptr;



		//Вернуть указатель на случайный ход
		//генерация случайных чисел взята здесь
		//http://cppstudio.com/post/339/
		int randomNumber = rand() % Moves.size();
		bestMove = Moves[randomNumber];

		//Сделать ход
		field->SelectFigure(bestMove.StartI, bestMove.StartJ);
		Done = !field->Move(bestMove.FinishI, bestMove.FinishJ);
		
		//Если ход не удался
		if (!Done)
		{
			//Удалить его из вектора
			Moves.erase(Moves.begin() + randomNumber);
		}
	}
	return &bestMove;
}

//Добавляет все возможные ходы фигуры в вектор
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
