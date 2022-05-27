#pragma once
#include "Field.h"
#include "Figure.h"


class Pawn :
    public Figure
{
public:
    //�����������
    Pawn(Field* field);

    //������� ����� ����� ������
    void FillMovesMap(int i, int j);

    //������� ����� ���� ������
//��������� ��� ���� ������� Moves �� ������� ��������� ����� ����� ��������� ������
//���� ����� ����� ������ ����� ���������� ��������� ���� ������
    void FillAttackMap(int i, int j);
    
};

