#include "Rock.h"

Rock::Rock(Field* field)
{
    FigureType = FigureTypes::rock;
    _field = field;
}

//����� ��� �������� ������ ������ �� ��������� ��
//���������� ����� �� �������� ������
bool Rock::CheckCell(int i, int j)
{
    if (_field->CellIsValid(i, j))
    {
        Figure* figure = _field->Figures[i][j];
        //���� ������ ���������, �� �������� �� ��������� ��� ����
        if (figure == 0)
        {
            _field->Moves[i][j] = true;
            return true;
        }
        //���� ������ ������ ����� �������, �� ������ ��� �� �������
        if (figure->FigureColor == this->FigureColor)
        {
            return false;
        }
        else
        {
            //���� ������ ������ ����� �������, ��  �������� ��������� ��� ���� 
            //� ������ ��� �� �������
            _field->Moves[i][j] = true;
            return false;
        }
    }
    return false;
}

void Rock::AllMoves(int i, int j)
{
    _field->ClearMove();
    //����
    for (int x = i+1; x < 8; x++)
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
    for (int x = i-1; x >= 0; x--)
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
    for (int x = j+1; x < 8; x++)
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
    for (int x = j-1; x >= 0; x--)
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
}