#pragma once
#include "Field.h"

//����������� ����� ������
class Figure
{
protected:
    Field* _field;

public:
    FigureTypes FigureType;
    FigureColors FigureColor;
    

    //��� ����������� �����, ��� ����������� ����� �������������� � ������� - � ������ ������-�������
    // ��� ������ ������ ����� ����� ����� �������� ������ ����
    //���� ����� �������� ��� ���� �� ����, ���� ����� ������ ��� ������
    virtual void AllMoves() = 0;

};

//��� ������
//�������� ������ - ��� �� �������� ��� ���������� �������
enum FigureTypes
{
    king = 9000,//������
    queen = 9,//�����
    bishop = 3,//����
    knight = 3,//����
    rock = 5,//�����
    pawn = 1//�����
};

//���� ������
enum FigureColors
{
    black,
    white 
};

