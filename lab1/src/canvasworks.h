#pragma once

#include <gcroot.h>

using namespace System;
using namespace System::Drawing;

//точка на экране
struct sCanvasPoint
{
	int x;
	int y;
};

//обёртка для холста
struct sCanvasContainer
{
	gcroot<System::Windows::Forms::PictureBox^> pb;
};

//мольберт для рисования
struct sEasel
{
	gcroot<Graphics^> canvas;	//сам холст
	gcroot<Color> backcolor;	//цвет фона
	//Graphics^ canvas;
	//Color backcolor;
	int cx, cy;					//центр холста
};

//создаёт 2д-точку из двух координат
sCanvasPoint CanvasPoint(int fromX, int fromY);

//рисует линию на холсте между двумя точками
void DrawLine(Graphics^ canvas, sCanvasPoint &from, sCanvasPoint &to, Color clr = Color::Black);

//Очищение канваса
void PrepareCanvas(sEasel *easel);