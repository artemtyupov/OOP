#pragma once

#include "fileworks.h"

//ребра модели
struct sEdgesList
{
	int count;			//количество ребер
	sEdge *edgesArray;	//массив ребер
};

//вершины модели
struct sPointsList
{
	int count;			//количество вершин
	sPoint3d *pointsArray;	//массив вершин
};

//структура модели
struct sModel
{
	sPointsList points; //вершины модели
	sEdgesList edges; //ребра модели
};

//перечислитель результата выделения памяти
enum eAllocError {aeFine, aeOutOfMemory};



//освобождает память из-под структуры вершин модели
void ClearPointsList(sPointsList *p);

//освобождает память из-под структуры ребер модели
void ClearEdgesList(sEdgesList *e);


//пытается загрузить все
eCodeFile TryLoadAll(sModel *newmodel, FILE *fl);

//пытается загрузить вершины модели из файла
eCodeFile TryLoadPoints(sPointsList *pd, FILE *fl);

//пытается загрузить рёбра модели из файла
eCodeFile TryLoadEdges(sEdgesList *adj, FILE *fl);





//пытается выделить память под структуру вершин модели
eAllocError AllocPointsList(sPointsList *points);

//пытается выделить память под структуру ребер модели
eAllocError AllocEdgesLst(sEdgesList *edges);