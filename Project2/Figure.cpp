#include "Figure.h"
#include "Field.h"

//���� ����� ����� ��� ���������� �����, ������� �� � ������������ ������
    //����� ��� �������� ������ ������ �� ��������� �� ��� ��������� ��� ����
    //���������� ����� �� �������� ������
bool Figure::CheckCell(int i, int j)
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