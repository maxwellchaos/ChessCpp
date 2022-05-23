#pragma once

//����� ������� ����
class Field
{
public:
	///�� ���� �������� ������ ����� - ������ �����
	///					������ ����� - ������ ��������
	///����� ������ ����� - ����� �������� �� ����� 6-7, ������ �������� �� ����� 0-1

	///��� �� ��� ���������� ���� ������������ ������ i ��� �����
	///												  j ��� ��������

	//������ �����
	Figure* Figures[8][8];
	//����� ������ ��������� �����
	bool Moves[8][8];

	//��������� ������
	Figure* SelectedFigure = 0;


	Field()
	{
		//������� ����
		for(int i = 0;i<8;i++)
		{ 
			for (int j = 0; j < 8; j++)
			{
				Figures[i][j] = 0;
			}
		}
		//����������� �����
		//�����
		//������
		for (int j = 0; j < 8; j++)
		{
			Figure *figure = new Pawn(this);
			figure->FigureColor = FigureColors::black;
			Figures[1][j] = figure;
		}
		//�����
		for (int j = 0; j < 8; j++)
		{
			Figure* figure = new Pawn(this);
			figure->FigureColor = FigureColors::white;
			Figures[6][j] = figure;
		}
	}

};

