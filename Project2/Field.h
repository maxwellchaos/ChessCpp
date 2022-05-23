#pragma once

//Класс игровое поле
class Field
{
public:
	///Во всех массивах первое число - номера строк
	///					второе читло - номера столбцов
	///внизу всегда белые - Белые стартуют из строк 6-7, черные стартуют из строк 0-1

	///так же для понятности буду использовать индекс i для строк
	///												  j для столбцов

	//массив фигур
	Figure* Figures[8][8];
	//булев массив возможных ходов
	bool Moves[8][8];

	//Выбранная фигура
	Figure* SelectedFigure = 0;


	Field()
	{
		//Очистка поля
		for(int i = 0;i<8;i++)
		{ 
			for (int j = 0; j < 8; j++)
			{
				Figures[i][j] = 0;
			}
		}
		//расстановка фигур
		//пешки
		//черные
		for (int j = 0; j < 8; j++)
		{
			Figure *figure = new Pawn(this);
			figure->FigureColor = FigureColors::black;
			Figures[1][j] = figure;
		}
		//Белые
		for (int j = 0; j < 8; j++)
		{
			Figure* figure = new Pawn(this);
			figure->FigureColor = FigureColors::white;
			Figures[6][j] = figure;
		}
	}

};

