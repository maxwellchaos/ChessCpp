#pragma once
#include "Figure.h"
#include "Field.h"

class King :
    public Figure
{
private:
    //� ���� ������� ��������� ��� ��������� ���� ����������, 
    //����� ����� ���� ��������� ��������� ���� ������
    int Moves[8][8];
public:
    //�����������
    King(Field* field);

    void FillMovesMap(int i, int j);

    void FillMovesMapWithClear(int i, int j);

    void FillAttackMap(int i, int j);
};

