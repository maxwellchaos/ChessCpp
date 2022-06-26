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