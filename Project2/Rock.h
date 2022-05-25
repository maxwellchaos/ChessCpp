#pragma once
#include "Figure.h"
#include "Field.h"

class Rock :
    public Figure
{
private:
    //����� ��� �������� ������ ������ �� ��������� ��
    //���������� ����� �� �������� ������
    bool CheckCell(int i, int j);
public:
    //�����������
    Rock(Field* field);
    

    void AllMoves(int i, int j);
   
};

