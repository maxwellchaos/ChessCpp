#pragma once

class Field;

//����������� ����� ������
class Figure
{
public:
    class Field* _field = nullptr;


    int FigureType;
    int FigureColor;
    

    //��� ����������� �����, ��� ����������� ����� �������������� � ������� - � ������ ������-�������
    // ��� ������ ������ ����� ����� ����� �������� ������ ����
    //���� ����� �������� ��� ���� �� ����, ���� ����� ������ ��� ������
    //��������� ���������� ������
    virtual void AllMoves(int i,int j) = 0;

};

//��� ������
//�������� ������ - ��� �� �������� ��� ���������� �������
enum FigureTypes
{
    king = 9000,//������
    queen = 90,//�����
    bishop = 35,//����
    knight = 30,//����
    rock = 50,//�����
    pawn = 10//�����
};

//���� ������
enum FigureColors
{
    black,
    white 
};

