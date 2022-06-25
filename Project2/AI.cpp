#include "AI.h"
#include <algorithm>    // std::sort


FigureMove* AI::RandomMove(Field*field,int color)
{
	
	CreateMoveList(field, color);

	//пока ход не получитс€
	//—делано на случай ошибочных ходов при шахе
	bool Done = true;
	while (Done)
	{
		//Ёто мат
		if (Moves.size() == 0)
			return nullptr;


		//¬ернуть указатель на случайный ход
		//генераци€ случайных чисел вз€та здесь
		//http://cppstudio.com/post/339/
		int randomNumber = rand() % Moves.size();
		bestMove = Moves[randomNumber];

		//—делать ход
		field->SelectFigure(bestMove.StartI, bestMove.StartJ);
		Done = !field->Move(bestMove.FinishI, bestMove.FinishJ);
		
		//≈сли ход не удалс€
		if (!Done)
		{
			//”далить его из вектора
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
	
	//ќтсортировать очередь
	// ак работает эта сортировка с примерами https://cplusplus.com/reference/algorithm/sort/
	std::sort(Moves.begin(), Moves.end(), CompareFunc);

	//пока ход не получитс€
	//—делано на случай ошибочных ходов при шахе
	bool Done = true;
	while (Done)
	{
		//Ёто мат
		if (Moves.size() == 0)
			return nullptr;

		bestMove = Moves[0];

		//—делать ход
		field->SelectFigure(bestMove.StartI, bestMove.StartJ);
		Done = !field->Move(bestMove.FinishI, bestMove.FinishJ);

		//≈сли ход не удалс€
		if (!Done)
		{
			//”далить его из вектора
			Moves.erase(Moves.begin());
		}
	}
	return &bestMove;
}

//ƒобавл€ет все возможные ходы фигуры в очередь
void AI::AllFigureMovesToDeque(Figure* figure,Field *field)
{
	figure->FillMovesMapWithClear(figure->i, figure->j);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (field->Moves[i][j])
			{
				//заполнить ход и подсчитать его эффективность
				FigureMove move;
				move.StartI = figure->i;
				move.StartJ = figure->j;
				move.FinishI = i;
				move.FinishJ = j;

				//—оздать тестовое поле копированием текущего пол€
				Field* testedField = new Field(field);
				//вычислить на нем позицию
				int oldPosition = testedField->CalcPosition(figure->FigureColor);

				//сделать на нем ход
				testedField->SelectFigure(move.StartI, move.StartJ);
				bool moveResult = testedField->Move(move.FinishI, move.FinishJ);
				if (!moveResult)
				{
					//если сделать ход не получилось - не добавл€ть этот ход в очередь
					//удалить тестовое поле и продолжить искать другие ходы
					delete testedField;
					continue;
				}
				
				//посчитать его эффективность
				int newPosition = testedField->CalcPosition(figure->FigureColor);

				move.efficiency = oldPosition - newPosition;

				//ƒобавить случайную маленькую величину, чтобы при одинаковых эффективност€х 
				//выбиралс€ случайный ход. Ёто делаетс€ благодар€ сортировке
				move.efficiency += (double)rand() / (RAND_MAX-1);

				//удалить тестовое поле
				delete testedField;

				//ѕоложить ход в очередь
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
	//—обрать список всех возможных ходов

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
