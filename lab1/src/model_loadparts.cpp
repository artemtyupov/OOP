//
//		Работа с компонентами модели
//

#include "stdafx.h"
#include "model_loadparts.h"

//освобождает память из-под структуры вершин модели
void ClearPointsList(sPointsList *p)
{
	if (!p)
		return;
	delete p->pointsArray;
	p->pointsArray = nullptr;
	p->count = 0;
}

//освобождает память из-под структуры ребер модели
void ClearEdgesList(sEdgesList *e)
{
	if (!e)
		return;
	delete e->edgesArray;
	e->edgesArray = nullptr;
	e->count = 0;
}

//загружает массив точек в структуру
eCodeFile LoadPoints(sPointsList *points, FILE *fl)
{
	eCodeFile res = cfFine;

	for (int i = 0;  (i < points->count) && (res == cfFine);  i++)
	{
		res = LoadSinglePoint(&(points->pointsArray[i]), fl);
	}
	return res;
}

//загружает массив ребер в структуру
eCodeFile LoadEdges(sEdgesList *edges, FILE *fl)
{
	eCodeFile res = cfFine;

	for (int i = 0;  (i < edges->count) && (res == cfFine);  i++)
	{
		res = LoadSingleEdge(&(edges->edgesArray[i]), fl);
	}
	return res;
}


//пытается выделить память под структуру вершин модели
eAllocError AllocPointsList(sPointsList *points)
{
	points->pointsArray = new sPoint3d[points->count];

	if (!points->pointsArray)
		return aeOutOfMemory;

	return aeFine;
}

//пытается выделить память под структуру ребер модели
eAllocError AllocEdgesList(sEdgesList *edges)
{
	edges->edgesArray = new sEdge[edges->count];

	if (!edges->edgesArray)
		return aeOutOfMemory;

	return aeFine;
}



//пытается загрузить вершины модели из файла
eCodeFile TryLoadPoints(sPointsList *points, FILE *fl)
{	
	eCodeFile res = LoadPointsCount(points->count, fl); //пытаемся получить число точек из файла
	if (res != cfFine) 
		return res;
	
	if (AllocPointsList(points) == aeOutOfMemory) //пытаемся выделить память под точки
		return cfOutOfMemory;

	res = LoadPoints(points, fl); //наконец пытаемся загрузить точки

	if (res != cfFine) //если не удалось - очистим память из-под них
		ClearPointsList(points);

	return res;
}

//пытается загрузить рёбра модели из файла
eCodeFile TryLoadEdges(sEdgesList *edges, FILE *fl)
{
	eCodeFile res = LoadEdgesCount(edges->count, fl); //пытаемся получить число ребер из файла
	if (res != cfFine) 
		return res;

	if (AllocEdgesList(edges) == aeOutOfMemory) //пытаемся выделить память под ребра
		return cfOutOfMemory;

	res = LoadEdges(edges, fl); //наконец пытаемся загрузить ребра

	if (res != cfFine) //если не удалось - очистим память из-под них
		ClearEdgesList(edges);

	return res;
}

eCodeFile TryLoadAll(sModel *newmodel, FILE *fl)
{

	eCodeFile res = TryLoadPoints(&(newmodel->points), fl); //пытаемся загрузить точки

	if (res != cfFine)
	{
		return res;
	}

	res = TryLoadEdges(&(newmodel->edges), fl); //пытаемся загрузить рёбра

	if (res != cfFine)
	{
		ClearPointsList(&(newmodel->points));
		return res;
	}
}

