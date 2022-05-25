#include "Field.h"

Field::Field()
{
	//Очистка поля
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			Figures[i][j] = 0;
		}
	}

	//Очистка ходов 
	ClearMove();

	//здесь создаю и настраиваю фигуру
	Figure* figure;


	//расстановка фигур
	//черные
	//пешки
	for (int j = 0; j < 8; j++)
	{
		figure = new Pawn(this);
		figure->FigureColor = FigureColors::black;
		Figures[1][j] = figure;
	}

	//ладьи
	figure = new Rock(this);
	figure->FigureColor = FigureColors::black;
	Figures[0][0] = figure;

	figure = new Rock(this);
	figure->FigureColor = FigureColors::black;
	Figures[0][7] = figure;

	//кони
	figure = new Knight(this);
	figure->FigureColor = FigureColors::black;
	Figures[0][1] = figure;

	figure = new Knight(this);
	figure->FigureColor = FigureColors::black;
	Figures[0][6] = figure;

	//слоны
	figure = new Bishop(this);
	figure->FigureColor = FigureColors::black;
	Figures[0][2] = figure;

	figure = new Bishop(this);
	figure->FigureColor = FigureColors::black;
	Figures[0][5] = figure;

	//король
	figure = new King(this);
	figure->FigureColor = FigureColors::black;
	Figures[0][4] = figure;

	//ферзь
	figure = new Queen(this);
	figure->FigureColor = FigureColors::black;
	Figures[0][3] = figure;

	//Белые
	for (int j = 0; j < 8; j++)
	{
		figure = new Pawn(this);
		figure->FigureColor = FigureColors::white;
		Figures[6][j] = figure;
	}

	//ладьи
	figure = new Rock(this);
	figure->FigureColor = FigureColors::white;
	Figures[7][0] = figure;

	figure = new Rock(this);
	figure->FigureColor = FigureColors::white;
	Figures[7][7] = figure;

	//кони
	figure = new Knight(this);
	figure->FigureColor = FigureColors::white;
	Figures[7][1] = figure;

	figure = new Knight(this);
	figure->FigureColor = FigureColors::white;
	Figures[7][6] = figure;

	//слоны
	figure = new Bishop(this);
	figure->FigureColor = FigureColors::white;
	Figures[7][2] = figure;

	figure = new Bishop(this);
	figure->FigureColor = FigureColors::white;
	Figures[7][5] = figure;

	//король
	figure = new King(this);
	figure->FigureColor = FigureColors::white;
	Figures[7][4] = figure;

	//ферзь
	figure = new Queen(this);
	figure->FigureColor = FigureColors::white;
	Figures[7][3] = figure;

}

bool Field::CellIsValid(int i, int j)
{
	//проверка, попали ли координаты клетки в игровое поле
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
//Выбрать фигуру
bool Field::SelectFigure(int i, int j)
{
	//Если координата не валидная - выходит за пределы поля
	//то не делать ничего
	if (!CellIsValid(i, j))
		return false;

	//Если в выбранном поле нет фигуры
	//то не делать ничего
	Figure* figure = Figures[i][j];
	if (figure == nullptr)
		return false;

	//если выбрана фигура того цвета, который ходит
	//то меняю карту возможных ходов
	if (figure->FigureColor == CurrentMoveColor)
	{
		SelectedFigure = figure;
		SelectedFigureI = i;
		SelectedFigureJ = j;
		figure->AllMoves(i,j);
	}
	return true;
}

//Сделать ход выделенной фигурой
bool Field::Move(int i, int j)
{
	//проверить поле на валидность
	if (!CellIsValid(i, j))
		return false;

	//Удалить фигуру, если была сбита
	if (Figures[i][j] != nullptr)
	{
		delete Figures[i][j];
	}
	
	//переместить фигуру
	Figures[i][j] = SelectedFigure;
	
	//очистить все переменые
	Figures[SelectedFigureI][SelectedFigureJ] = nullptr;
	SelectedFigure = nullptr;

	//переключить цвет
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

//деструктор
Field::~Field()
{
	//Удалить все фигуры
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (Figures[i][j] != nullptr)
			{
				//Удалить фигуру
				delete Figures[i][j];
			}
		}
	}
}