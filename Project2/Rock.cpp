#include "Rock.h"

Rock::Rock(Field* field)
{
    FigureType = FigureTypes::rock;
    _field = field;
}

void Rock::AllMoves(int i, int j)
{
    _field->ClearMove();
    //����
    for (int x = i; x < 8; x++)
    {
        if (_field->CellIsValid(x, j))
        {
            Figure* figure = _field->Figures[x][j];
            //���� ������ ���������, �� �������� �� ��������� ��� ����
            if (figure == 0)
            {
                _field->Moves[x][j] = true;
                continue;
            }
            //���� ������ ������ ����� �������, �� ������ ��� �� �������
            if (figure->FigureColor == this->FigureColor)
            {
                break;
            }
            else
            {
                //���� ������ ������ ����� �������, ��  �������� ��������� ��� ���� 
                //� ������ ��� �� �������
                _field->Moves[x][j] = true;
                break;
            }
        }
    }
    //�����
    for (int x = i; x >= 0; x--)
    {
        if (_field->CellIsValid(x, j))
        {
            Figure* figure = _field->Figures[x][j];
            //���� ������ ���������, �� �������� �� ��������� ��� ����
            if (figure == 0)
            {
                _field->Moves[x][j] = true;
                continue;
            }
            //���� ������ ������ ����� �������, �� ������ ��� �� �������
            if (figure->FigureColor == this->FigureColor)
            {
                break;
            }
            else
            {
                //���� ������ ������ ����� �������, ��  �������� ��������� ��� ���� 
                //� ������ ��� �� �������
                _field->Moves[x][j] = true;
                break;
            }
        }
    }
    //������
    for (int x = j; x < 8; x++)
    {
        if (_field->CellIsValid(x, j))
        {
            Figure* figure = _field->Figures[x][j];
            //���� ������ ���������, �� �������� �� ��������� ��� ����
            if (figure == 0)
            {
                _field->Moves[x][j] = true;
                continue;
            }
            //���� ������ ������ ����� �������, �� ������ ��� �� �������
            if (figure->FigureColor == this->FigureColor)
            {
                break;
            }
            else
            {
                //���� ������ ������ ����� �������, ��  �������� ��������� ��� ���� 
                //� ������ ��� �� �������
                _field->Moves[x][j] = true;
                break;
            }
        }
    }
    //�����
    for (int x = j; x >= 0; x--)
    {
        if (_field->CellIsValid(x, j))
        {
            Figure* figure = _field->Figures[x][j];
            //���� ������ ���������, �� �������� �� ��������� ��� ����
            if (figure == 0)
            {
                _field->Moves[x][j] = true;
                continue;
            }
            //���� ������ ������ ����� �������, �� ������ ��� �� �������
            if (figure->FigureColor == this->FigureColor)
            {
                break;
            }
            else
            {
                //���� ������ ������ ����� �������, ��  �������� ��������� ��� ���� 
                //� ������ ��� �� �������
                _field->Moves[x][j] = true;
                break;
            }
        }
    }
}