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
	//Очистка поля
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			Figures[i][j] = 0;
		}
	}

	//Очистка ходов 
	ClearMovesMap();

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
	BlackKing = figure;

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
	WhiteKing = figure;

	//ферзь
	figure = new Queen(this);
	figure->FigureColor = FigureColors::white;
	Figures[7][3] = figure;

	//обновление координат фигур
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
	//Очистка поля
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			Figures[i][j] = 0;
		}
	}

	//Очистка ходов 
	ClearMovesMap();

	//Копирование
	CopyToMe(field);
}


bool Field::CellIsValid(int i, int j)
{
	//проверка, попали ли координаты клетки в игровое поле
	return (i >= 0) && (j >= 0) && (i < 8) && (j < 8);
}

//чищу массив карт
void Field::ClearMovesMap()
{
	//присваивается false всем элементам массива
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
		figure->FillMovesMapWithClear(i,j);
		return true;
	}
	return false;
}

//Сделать ход выделенной фигурой
bool Field::Move(int i, int j,bool withoutCheckmate)
{
	if (Checkmate)
	{
		//мат уже поставлен
		return false;
	}

	//проверить поле на валидность
	if (!CellIsValid(i, j))
	{
		return false;
	}

	//Копирую всю игру
	Field* oldField = new Field(this);

	//Удалить фигуру, если была сбита
	if (Figures[i][j] != nullptr)
	{
		delete Figures[i][j];
	}
	//Рокировка
	//Король пойдет позже - сначала переместить ладью
	if (SelectedFigure->FigureType == FigureTypes::king)
	{
		//Если король должен пойти больше чем на одну клетку, то это рокировка
		if (abs(SelectedFigure->j - j) > 1)
		{
			//В какую сторону пойдет король
			if (SelectedFigure->j - j > 0)
			{
				//Влево
				Figures[i][3] = Figures[i][0];
				Figures[i][3]->j = 3;
				Figures[i][0] = nullptr;
			}
			else
			{
				//Вправо
				Figures[i][5] = Figures[i][7];
				Figures[i][5]->j = 5;
				Figures[i][7] = nullptr;

			}
		}
	}

	//переместить фигуру
	Figures[i][j] = SelectedFigure;

	//Сделать пешку ферзем
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

	
	
	//очистить все переменые связанные с клеткой и выбранной фигурой
	//берутся прошлые ее координаты
	Figures[SelectedFigure->i][SelectedFigure->j] = nullptr;
	//обновляются координаты
	SelectedFigure->i = i;
	SelectedFigure->j = j;
	//Отменяется выделение
	SelectedFigure = nullptr;

	//Если все еще шах
	if (CheckTest(Figure::InverseColor( CurrentMoveColor)))
	{
		//Возвращаю из копии
		CopyToMe(oldField);

		ClearMovesMap();
		//все еще шах, нельзя так ходить
		return false;
	}

	delete oldField;

	//Выставляю шах, если он есть
	CheckTest(CurrentMoveColor);

	//Не проверять на мат
	//Это нужно для проверки на мат, чтобы не уходило в рекурсию
	if (!withoutCheckmate)
	{
		//Проверяю на мат
		CheckmateTest(CurrentMoveColor);
	}
	//переключить цвет
	CurrentMoveColor = Figure::InverseColor(CurrentMoveColor);


	ClearMovesMap();

	return true;
}

//посмотреть все возможные ходы одного цвета
void Field::GetAllAttackMap(int Color)
{
	//очистить все ходы
	ClearMovesMap();

	//перебрать все фигуры
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			//Если фигура есть на этом поле
			if (Figures[i][j] != nullptr)
			{
				//Если фигура нужного цвета
				if (Figures[i][j]->FigureColor == Color)
				{
					//Добавить все ее возможные атаки к общей карте возможных атак
					Figures[i][j]->FillAttackMap(i,j);
				}
			}
		}
	}
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
	//копирование цвета 
	CurrentMoveColor = field->CurrentMoveColor;

	//Очистка поля
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			//Удаляю фигуры, если они есть
			if (Figures[i][j] != nullptr)
			{
				delete Figures[i][j];
				//Figures[i][j] = nullptr;
			}

			//Копирую фигуры
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

					//Настраиваю указатели на королей
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

	//Очистка ходов 
	ClearMovesMap();

	//обновление координат фигур
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

//ПРоверка на мат для заданного цвета
//фигуры заданного цвета поставили мат
bool Field::CheckmateTest(int color)
{
	//Алгоритм проверки на мат:
	//ПРоверить все возможные ходы всех возможных фигур выбранного цвета
	//если после хода каждой сохранятеся шах, то поставлен мат
	
	//Кому поставили мат
	int matedColor = Figure::InverseColor(color);

	//Изначально считаем, что мат
	Checkmate = true;

	//два фора и два иф - проверка всех фигур заданного цвета
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			Figure* figure = Figures[i][j];
			if(figure!= nullptr)
				if (figure->FigureColor == matedColor)
				{
					//Это выполнится для каждой фигуры заданного цвета
					
					//собирает карту ходов фигуры
					figure->FillMovesMapWithClear(i, j);

					
					//Проверяет все возможные ходы фигуры на сохранение шаха
					//Здесь слишком большая вложенность, поэтому дроблю это на функции
					Checkmate = CheckAllMovesFigure(figure, color);
					
					if (!Checkmate)
					{
						//Есть спасительный ход
						return false;
					}
				}
		}
	}
	return Checkmate;
}


//Проверить все ходы одной фигуры и вернуть True, если после каждого хода будет шах
bool Field::CheckAllMovesFigure(Figure* figure,int color)
{
	//Поле для проверки одного хода
	Field* oneMoveField = new Field();

	//Здесь уже есть карта ходов фигуры
	//для всех ходов в карте
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (Moves[i][j])
			{
				// скопировать поле
				oneMoveField->CopyToMe(this);
				//Меняю цвет, чтобы можно было ходить
				oneMoveField->CurrentMoveColor = Figure::InverseColor(oneMoveField->CurrentMoveColor);

				//сделать ход
				oneMoveField->SelectFigure(figure->i, figure->j);
				
				oneMoveField->Move(i, j,true);
				//проверить шах
				if (!oneMoveField->CheckTest(color))
				{
					return false;
				}
			}
		}
	}
	return true;
}

//Подсчитать позицию заданного цвета на доске
int Field::CalcPosition(int color)
{

	int position = 0;
	//Сложить все типы фигур заданного цвета
	//Вычесть все типы фигур вражеского цвета
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
