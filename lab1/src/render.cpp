//
//		Непосредственно отрисовка модели
//

#include "stdafx.h"
#include "render.h"



//отрисовка рёбер модели
void DrawEdges(sConvertedPoints *converted, sEasel *easel, sEdgesList *links)
{
	for (int i=0; i<links->count; i++)
	{
		DrawSingleEdge(converted, easel, &(links->edgesArray[i]));
	}
}

//отрисовка модели на мольберте с указанными параметрами
void DrawModel(sModel *mdl, sEasel *easel, sRenderData *params)
{
	if (!mdl || !easel || !params)
		return;

	//переводим точки модели в точки холста, с учётом "параметров экрана"
	sConvertedPoints *conv = ConvertPoints(&(mdl->points), params);
	if (!conv) return;

	PrepareCanvas(easel);

	//отрисовываем рёбра модели
	DrawEdges(conv, easel, &(mdl->edges));

	ClearConvertedPoints(conv);

	return;
}