#pragma once

#include "model_loadparts.h"

//смещение модели
struct sMove
{
	double dx;
	double dy;
	double dz;
};

//параметры переотрисовки
struct sRenderData
{
	double fx, fy, fz; //угол поворота
	double dx, dy, dz; //смещение модели
	double M; //масштаб отрисовки
};

//точки в целочисленных координатах
//используются при непосредственно отрисовке
struct sConvertedPoints
{
	int count;	//число точек
	int *Xs;	//X i-й точки
	int *Ys;	//Y i-й точки
};

sConvertedPoints* ConvertPoints(sPointsList *points, sRenderData *params);

void ClearConvertedPoints(sConvertedPoints *converted);