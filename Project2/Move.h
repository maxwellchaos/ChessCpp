#pragma once

//Класс хода
//Представляет собой координаты фигуры и координаты, куда она должна пойти
//Так же хранит эффективность хода
class Move
{
public:
	int StartI;
	int StartJ;
	int FinishI;
	int FinishJ;
	double efficiency = 0;
};

