#include "King.h"

King::King(Field* field)
{
    FigureType = FigureTypes::king;
    _field = field;
}

void King::FillMovesMap(int i, int j)
{
    //��������� ��� ������ ������ ������
    for (int x = i - 1; x <= i + 1; x++)
        for (int y = j - 1; y <= j + 1; y++)
        {
            CheckCell(x, y,false);
        }

    //���������
    if (FigureColor == FigureColors::white)
    {
        //������ �� �����
        if (i == 7 && j == 4)
        {
            //���� ������ �� ����� ������ ������
            if (_field->Figures[7][6] == nullptr && _field->Figures[7][5] == nullptr)
            {
                //���� ����� ���� ����� �����
                if (_field->Figures[7][7] != nullptr && _field->Figures[7][7]->FigureType == FigureTypes::rock)
                {
                    _field->Moves[7][6] = true;
                }

            }
            //���� ����� �� ����� ������ ������
            if (_field->Figures[7][3] == nullptr
                && _field->Figures[7][2] == nullptr
                && _field->Figures[7][1] == nullptr)
            {
                //���� ����� ���� ����� �����
                if (_field->Figures[7][0] != nullptr 
                    && _field->Figures[7][0]->FigureType == FigureTypes::rock)
                {
                    _field->Moves[7][2] = true;
                }
            }
        }
    }
    else
    {
        //������ �� �����
        if (i == 0 && j == 4)
        {
            //���� ������ �� ����� ������ ������
            if (_field->Figures[0][6] == nullptr && _field->Figures[0][5] == nullptr)
            {
                //���� ����� ���� ����� �����
                if (_field->Figures[0][7] != nullptr && _field->Figures[0][7]->FigureType == FigureTypes::rock)
                {
                    _field->Moves[0][6] = true;
                }

            }
            //���� ����� �� ����� ������ ������
            if (_field->Figures[0][3] == nullptr
                && _field->Figures[0][2] == nullptr
                && _field->Figures[0][1] == nullptr)
            {
                //���� ����� ���� ����� �����
                if (_field->Figures[0][0] != nullptr 
                    && _field->Figures[0][0]->FigureType == FigureTypes::rock)
                {
                    _field->Moves[0][2] = true;
                }
            }
        }
    }
}

//�������� ��� ����, �������������� ������� ����, ���������� �� �����
//���� ������ ���� ����� ��� ������, �� �� ��������� ��� ��������� ���� ������ � ������ �����
void King::FillMovesMapWithClear(int i, int j)
{
    //�������� ����� ���� ����� ���� ����� ���������������� �����
    _field->GetAllAttackMap(  Figure::InverseColor(FigureColor));

    //����� ������ ��������� ����� 
    //����� ����� ��������� ��������� ����, ����������� �����
    bool Moves[8][8];

    //������� ������ ��������� ����� � ���� �����������
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            Moves[i][j] = _field->Moves[i][j];
        }
    }

    //���� ������ �����, ���� ��� ����� ��� ���� 
    _field->ClearMovesMap();

    //������� ��� ��������� ���� ������
    FillMovesMap(i, j);

    //���� ��������� ��� ������ ��������� � ��������� ����� ������ ����������
    //�� ������ ���� ��� ������
    //������ false �����, ��� ����� ����� ������ � ��������������� ������� ���������
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (Moves[i][j] == _field->Moves[i][j])
                _field->Moves[i][j] = false;
        }
    }

}

//������� ����� ���� ������
//��������� ��� ���� ������� Moves �� ������� ��������� ����� ����� ��������� ������
//���� ����� ����� ������ ����� ���������� ��������� ���� ������
void King::FillAttackMap(int i, int j)
{
    //��������� ��� ������ ������ ������
    for (int x = i - 1; x <= i + 1; x++)
        for (int y = j - 1; y <= j + 1; y++)
        {
            CheckCell(x, y, true);
        }
    //��������� ����
    _field->Moves[i][j] = false;

   
}