#include "AI.h"
#include <algorithm>    // std::sort


FigureMove* AI::RandomMove(Field*field,int color)
{
	
	CreateMoveList(field, color);

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

bool CompareFunc(FigureMove i, FigureMove j) 
{ 
	return (i.efficiency < j.efficiency); 
}

FigureMove* AI::BestMove(Field* field, int color)
{

	CreateMoveList(field, color);
	
	//Отсортировать очередь
	//Как работает эта сортировка с примерами https://cplusplus.com/reference/algorithm/sort/
	std::sort(Moves.begin(), Moves.end(), CompareFunc);

	//пока ход не получится
	//Сделано на случай ошибочных ходов при шахе
	bool Done = true;
	while (Done)
	{
		//Это мат
		if (Moves.size() == 0)
			return nullptr;

		bestMove = Moves[0];

		//Сделать ход
		field->SelectFigure(bestMove.StartI, bestMove.StartJ);
		Done = !field->Move(bestMove.FinishI, bestMove.FinishJ);

		//Если ход не удался
		if (!Done)
		{
			//Удалить его из вектора
			Moves.erase(Moves.begin());
		}
	}
	return &bestMove;
}

//Добавляет все возможные ходы фигуры в очередь
void AI::AllFigureMovesToDeque(Figure* figure,Field *field)
{
	figure->FillMovesMapWithClear(figure->i, figure->j);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			//Есди в карте ходов есть этот ход
			if (field->Moves[i][j])
			{
				//заполнить ход и подсчитать его эффективность
				FigureMove move;
				move.StartI = figure->i;
				move.StartJ = figure->j;
				move.FinishI = i;
				move.FinishJ = j;

				//Создать тестовое поле копированием текущего поля
				Field* testedField = new Field(field);
				//вычислить на нем позицию
				int oldPosition = testedField->CalcPosition(figure->FigureColor);

				//сделать на нем ход
				testedField->SelectFigure(move.StartI, move.StartJ);
				bool moveResult = testedField->Move(move.FinishI, move.FinishJ);
				if (!moveResult)
				{
					//если сделать ход не получилось - не добавлять этот ход в очередь
					//удалить тестовое поле и продолжить искать другие ходы
					delete testedField;
					continue;
				}
				
				//посчитать его эффективность
				int newPosition = testedField->CalcPosition(figure->FigureColor);

				move.efficiency = oldPosition - newPosition;
				//Добавить случайную маленькую величину, чтобы при одинаковых эффективностях 
				//выбирался случайный ход. Случайный ход выбирается благодаря сортировке
				move.efficiency += (double)rand() / (RAND_MAX-1);

				
				//Сгенерировать карту ходов противника на тестовом поле
				testedField->GetAllAttackMap(Figure::InverseColor( figure->FigureColor));
				
				//Если это поле атакуется
				if (testedField->Moves[move.FinishI][move.FinishJ])
				{
					//Вычесть силу фигуры из эффективности
					move.efficiency += figure->FigureType;
				}


				//удалить тестовое поле
				delete testedField;

				//Положить ход в очередь
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
					AllFigureMovesToDeque(figure, field);
				}
			}
		}
	}
	return;
}
