//
//		Работа с файлами на нижнем уровне - непосредственно загрузка элементов
//

#include "stdafx.h"
#include "fileworks.h"


//считывание из файла числа точек
eCodeFile LoadPointsCount(int &n, FILE *fl)
{
	int count;

	if (fscanf(fl, "%d", &count) != 1)
		return cfCorrupted;
	
	n = count;
	return cfFine;
}

//считывание из файла числа рёбер
eCodeFile LoadEdgesCount(int &n, FILE *fl)
{
	int count;

	if (fscanf(fl, "%d", &count) != 1)
		return cfCorrupted;
	
	n = count;
	return cfFine;
}

//считывание из файла ОДНОЙ точки
eCodeFile LoadSinglePoint(sPoint3d *point, FILE *fl)
{
	if (fscanf(fl, "%lf %lf %lf", &point->x, &point->y, &point->z) != 3)
		return cfCorrupted;
	
	return cfFine;
}

//считывание из файла ОДНОГО ребра
eCodeFile LoadSingleEdge(sEdge *edge, FILE *fl)
{
	if (fscanf(fl, "%d %d", &edge->from, &edge->to) != 2)
		return cfCorrupted;
	
	return cfFine;
}
