#pragma once

#include <gcroot.h>

using namespace System;
using namespace System::Drawing;

//����� �� ������
struct sCanvasPoint
{
	int x;
	int y;
};

//������ ��� ������
struct sCanvasContainer
{
	gcroot<System::Windows::Forms::PictureBox^> pb;
};

//�������� ��� ���������
struct sEasel
{
	gcroot<Graphics^> canvas;	//��� �����
	gcroot<Color> backcolor;	//���� ����
	//Graphics^ canvas;
	//Color backcolor;
	int cx, cy;					//����� ������
};

//������ 2�-����� �� ���� ���������
sCanvasPoint CanvasPoint(int fromX, int fromY);

//������ ����� �� ������ ����� ����� �������
void DrawLine(Graphics^ canvas, sCanvasPoint &from, sCanvasPoint &to, Color clr = Color::Black);

//�������� �������
void PrepareCanvas(sEasel *easel);