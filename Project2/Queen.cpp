#include "Queen.h"

Queen::Queen(Field* field)
{
    FigureType = FigureTypes::queen;
    _field = field;
}



void Queen::AllMoves(int i, int j)
{
    _field->ClearMove();
    //����
    for (int x = i + 1; x < 8; x++)
    {
        if (CheckCell(x, j))
        {
            continue;
        }
        else
        {
            break;
        }
    }
    //�����
    for (int x = i - 1; x >= 0; x--)
    {
        if (CheckCell(x, j))
        {
            continue;
        }
        else
        {
            break;
        }
    }
    //������
    for (int x = j + 1; x < 8; x++)
    {
        if (CheckCell(i, x))
        {
            continue;
        }
        else
        {
            break;
        }
    }
    //�����
    for (int x = j - 1; x >= 0; x--)
    {
        if (CheckCell(i, x))
        {
            continue;
        }
        else
        {
            break;
        }
    }

    //� ��� �� ����������
    for (int x = i + 1, y = j + 1; x < 8; x++, y++)
    {
        if (CheckCell(x, y))
            continue;
        else
            break;
    }
    for (int x = i - 1, y = j + 1; x < 8; x--, y++)
    {
        if (CheckCell(x, y))
            continue;
        else
            break;
    }
    for (int x = i + 1, y = j - 1; x < 8; x++, y--)
    {
        if (CheckCell(x, y))
            continue;
        else
            break;
    }
    for (int x = i - 1, y = j - 1; x < 8; x--, y--)
    {
        if (CheckCell(x, y))
            continue;
        else
            break;
    }
}