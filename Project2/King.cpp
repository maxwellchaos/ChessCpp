#include "King.h"

King::King(Field* field)
{
    FigureType = FigureTypes::king;
    _field = field;
}

void King::FillMovesMap(int i, int j)
{
    //проверить все клетки вокруг короля
    for (int x = i - 1; x <= i + 1; x++)
        for (int y = j - 1; y <= j + 1; y++)
        {
            CheckCell(x, y,false);
        }
}

//Получает все ходы, предварительно очистив ходы, записанные на доске
//Если вызван этот метод для короля, то он вычисляет все возможные ходы короля с учетом шахов
void King::FillMovesMapWithClear(int i, int j)
{
    //Получить карту всех ходов всех фигур противоположного цвета
    _field->GetAllAttackMap(  Figure::InverseColor(FigureColor));

    //булев массив возможных ходов 
    //Нужен чтобы сохранить возможные ходы, вычисленные ранее
    bool Moves[8][8];

    //Копирую массив возможных ходов в свой собственный
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            Moves[i][j] = _field->Moves[i][j];
        }
    }

    //Чищу массив ходов, ведь его копия уже есть 
    _field->ClearMovesMap();

    //Получаю все возможные ходы короля
    FillMovesMap(i, j);

    //Если возможный ход короля совпадает с возможным ходом фигуры противника
    //То убираю этот ход короля
    //ставлю false везде, где карта ходов короля и противоположной команды совпадают
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (Moves[i][j] == _field->Moves[i][j])
                _field->Moves[i][j] = false;
        }
    }

}

//Считает карту атак фигуры
//Заполняет все поля массива Moves на которые следующим ходом может атаковать фигура
//Этот метод нужен только чтобы определить возможные ходы короля
void King::FillAttackMap(int i, int j)
{
    //проверить все клетки вокруг короля
    for (int x = i - 1; x <= i + 1; x++)
        for (int y = j - 1; y <= j + 1; y++)
        {
            CheckCell(x, y, true);
        }
    //исключить себя
    _field->Moves[i][j] = false;
}