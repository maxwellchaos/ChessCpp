#include "Pawn.h"

Pawn::Pawn(Field* field)
{
    FigureType = FigureTypes::pawn;
    _field = field;
}
void Pawn::FillMovesMap(int i, int j)
{
    //���� ����� �����
    if (FigureColor == FigureColors::white)
    {
        if (_field->CellIsValid(i - 1, j))
            if (_field->Figures[i - 1][j] == nullptr)
            {
                _field->Moves[i - 1][j] = true;
                if (i == 6)//���� ����� �� ��� �����, ��� ���� � ������ ������
                {
                    //�� ����� ����� �� 2 ������ ������
                    if (_field->CellIsValid(i - 2, j))
                        if (_field->Figures[i - 2][j] == nullptr)
                            _field->Moves[i - 2][j] = true;
                }
            }
        //����� �����
        if (_field->CellIsValid(i - 1, j - 1))
            if (_field->Figures[i - 1][j - 1] != nullptr)
                if (_field->Figures[i - 1][j - 1]->FigureColor != FigureColor)
                    _field->Moves[i - 1][j - 1] = true;
        //����� ������
        if (_field->CellIsValid(i - 1, j + 1))
            if (_field->Figures[i - 1][j + 1] != nullptr)
                if (_field->Figures[i - 1][j + 1]->FigureColor != FigureColor)
                    _field->Moves[i - 1][j + 1] = true;
    }
    //���� ����� ������
    if (FigureColor == FigureColors::black)
    {
        if (_field->CellIsValid(i + 1, j))
            if (_field->Figures[i + 1][j] == nullptr)
            {
                _field->Moves[i + 1][j] = true;
                if (i == 1)//���� ����� �� ��� �����, ��� ���� � ������ ������
                {
                    //�� ����� ����� �� 2 ������ ������
                    if (_field->CellIsValid(i + 2, j))
                        if (_field->Figures[i + 2][j] == nullptr)
                            _field->Moves[i + 2][j] = true;
                }
            }
        //����� �����
        if (_field->CellIsValid(i + 1, j + 1))
            if (_field->Figures[i + 1][j + 1] != nullptr)
                if (_field->Figures[i + 1][j + 1]->FigureColor != FigureColor)
                    _field->Moves[i + 1][j + 1] = true;
        //����� ������
        if (_field->CellIsValid(i + 1, j - 1))
            if (_field->Figures[i + 1][j - 1] != nullptr)
                if (_field->Figures[i + 1][j - 1]->FigureColor != FigureColor)
                    _field->Moves[i + 1][j - 1] = true;
    }
}

//������� ����� ���� ������
//��������� ��� ���� ������� Moves �� ������� ��������� ����� ����� ��������� ������
//���� ����� ����� ������ ����� ���������� ��������� ���� ������
void Pawn::FillAttackMap(int i, int j)
{
    //���� ����� �����
    if (FigureColor == FigureColors::white)
    {

        //����� �����
        if (_field->CellIsValid(i - 1, j - 1))
            _field->Moves[i - 1][j - 1] = true;
        //����� ������
        if (_field->CellIsValid(i - 1, j + 1))
            _field->Moves[i - 1][j + 1] = true;
    }
    //���� ����� ������
    if (FigureColor == FigureColors::black)
    {

        //����� �����
        if (_field->CellIsValid(i + 1, j + 1))
            _field->Moves[i + 1][j + 1] = true;
        //����� ������
        if (_field->CellIsValid(i + 1, j - 1))
            _field->Moves[i + 1][j - 1] = true;
    }
}