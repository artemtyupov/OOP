
#include "stdafx.h"
#include "low_render.h"


//отрисовка единственного ребра
void DrawSingleEdge(sConvertedPoints *converted, sEasel *easel, sEdge *edge)
{
	DrawLine(easel->canvas,
		CanvasPoint(easel->cx + converted->Xs[edge->from], easel->cy - converted->Ys[edge->from]),
		CanvasPoint(easel->cx + converted->Xs[edge->to], easel->cy - converted->Ys[edge->to])
		);
}

