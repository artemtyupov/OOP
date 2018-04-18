//
//		Изменение параметров отрисовки модели
//

#include "stdafx.h"
#include "actions.h"



// ---------------------------------------------------------------------------

//инициализация холста на мольберте
void SetCanvas(sEasel *easel, sCanvasContainer *canv)
{
	easel->canvas = canv->pb->CreateGraphics();
	easel->cx = canv->pb->Width / 2;
	easel->cy = canv->pb->Height / 2;
	easel->backcolor = canv->pb->BackColor;
}

//изменение масштаба модели
void ChangeScale(sRenderData *renderdata, double scale)
{
	renderdata->M = scale;
}

//поворот модели
void ChangeRotation(sRenderData *renderdata, sMove move)
{
	renderdata->fx += move.dx;
	renderdata->fy += move.dy;
	renderdata->fz += move.dz;
}

//установка углов модели
void SetRotation(sRenderData *renderdata, sMove move)
{
	renderdata->fx = move.dx;
	renderdata->fy = move.dy;
	renderdata->fz = move.dz;
}

//смещение модели
void ChangeShift(sRenderData *renderdata, sMove move)
{
	renderdata->dx += move.dx;
	renderdata->dy += move.dy;
	renderdata->dz += move.dz;
}