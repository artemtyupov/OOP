//
//		Отрисовка линий непосредственно на холсте
//
#include "stdafx.h"
#include "canvasworks.h"

//создаёт 2д-точку из двух координат
sCanvasPoint CanvasPoint(int fromX, int fromY)
{
	sCanvasPoint pt;
	pt.x = fromX;
	pt.y = fromY;
	return pt;
}

//рисует линию на холсте между двумя точками
void DrawLine(Graphics^ canvas, sCanvasPoint &from, sCanvasPoint &to, Color clr)
{
	Pen^ drawpen = gcnew Pen(clr);
	canvas->DrawLine(drawpen, from.x, from.y,  to.x, to.y);
	delete drawpen;
}

//Очищение канваса
void PrepareCanvas(sEasel *easel)
{
	easel->canvas->Clear(easel->backcolor);
}