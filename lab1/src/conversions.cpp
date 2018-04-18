//
//		Преобразования модели в набор точек на экране
//

#include "stdafx.h"

#include "conversions.h"
#include "canvasworks.h"
#include "matrixworks.h"
#include "fileworks.h"

//создаёт матрицу преобразований: сдвиг х ротЗ х ротУ х ротХ х масштаб
double *GetConversionMatrix(sRenderData *data)
{
	double *ShiftMatrix = Get3DShiftMatrix(data->dx, data->dy, data->dz); //смещение от О
	if (!ShiftMatrix)
	{
		return nullptr;
	}
	double *RotateZMatrix = Get3DRotateZMatrix(data->fz); //поворот вокруг OZ
	if (!RotateZMatrix)
	{
		delete ShiftMatrix;
		return nullptr;
	}
	double *RotateYMatrix = Get3DRotateYMatrix(data->fy); //поворот вокруг OY
	if (!RotateYMatrix)
	{
		delete RotateZMatrix;
		delete ShiftMatrix;
		return nullptr;
	}
	double *RotateXMatrix = Get3DRotateXMatrix(data->fx); //поворот вокруг OX
	if (!RotateXMatrix)
	{
		delete ShiftMatrix;
		delete RotateYMatrix;
		delete RotateZMatrix;
		return nullptr;
	}
	double *ScaleMatrix = Get3DScaleMatrix(data->M); //масштабировние относительно О
	if (!ScaleMatrix)
	{
		delete ShiftMatrix;
		delete RotateZMatrix;
		delete RotateYMatrix;
		delete RotateXMatrix;
		return nullptr;
	}
	
	//матрицы получены - собираем из них исходную

	double *matr1 = MultMatrixXMatrix(ShiftMatrix, RotateZMatrix, 3); //Shift х Z
	if (!matr1)
	{
		delete ShiftMatrix;
		delete RotateZMatrix;
		delete RotateYMatrix;
		delete RotateXMatrix;
		delete ScaleMatrix;
		return nullptr;
	}
	double *matr2 = MultMatrixXMatrix(matr1, RotateYMatrix, 3); // x Y
	if (!matr2)
	{
		delete ShiftMatrix;
		delete RotateZMatrix;
		delete RotateYMatrix;
		delete RotateXMatrix;
		delete ScaleMatrix;
		delete matr1;
		return nullptr;
	}
	double *matr3 = MultMatrixXMatrix(matr2, RotateXMatrix, 3); //x X
	if (!matr3)
	{
		delete ShiftMatrix;
		delete RotateZMatrix;
		delete RotateYMatrix;
		delete RotateXMatrix;
		delete ScaleMatrix;
		delete matr2;
		delete matr1;
		return nullptr;
	}
	double *res = MultMatrixXMatrix(matr3, ScaleMatrix, 3); //x Scale
	if (!res)
	{
		delete ShiftMatrix;
		delete RotateZMatrix;
		delete RotateYMatrix;
		delete RotateXMatrix;
		delete ScaleMatrix;
		delete matr1;
		delete matr2;
		delete matr3;
		return nullptr;
	}

	delete ShiftMatrix;
	delete RotateZMatrix;
	delete RotateYMatrix;
	delete RotateXMatrix;
	delete ScaleMatrix;
	delete matr1;
	delete matr2;
	delete matr3;

	return res;
}

//преобразует единственную точку в точку на экране
sCanvasPoint* ConvertSinglePoint(sPoint3d *p, double *ConvMatrix)
{
	double *pVector = new double[4];	//представление точки в виде вектора
	if (!pVector)						//4 координаты нужны для использования матрицы переноса
		return nullptr;
	
	pVector[0] = p->x;
	pVector[1] = p->y;
	pVector[2] = p->z;
	pVector[3] = 1;

	//умножаем вектор точки на матрицу преобразований - получаем новую точку в векторном представлении
	double *conversion = MultVectorXMatrix(pVector, ConvMatrix, 3);
	delete pVector;

	if (!conversion) return nullptr;

	sCanvasPoint *res = new sCanvasPoint;
	if (!res)
	{
		delete conversion;
		return nullptr;
	}

	res->x = (int) conversion[0];
	res->y = (int) conversion[1];
	delete conversion;

	return res;
}

sConvertedPoints* AllocateConvertedPoints(int count)
{
	sConvertedPoints *conv = new sConvertedPoints;
	if (!conv) return nullptr;

	int *Xs = new int [count]; //массив координат Х
	if (!Xs)
	{
		delete conv;
		return nullptr;
	}
	int *Ys = new int [count]; //массив координат У
	if (!Ys)
	{
		delete conv;
		delete Xs;
		return nullptr;
	}

	conv->count = count;
	conv->Xs = Xs;
	conv->Ys = Ys;
	return conv;
}

//преобразует трёхмерные точки в точки на экране
sConvertedPoints* ConvertPoints(sPointsList *points, sRenderData *params)
{
	sConvertedPoints *conv = AllocateConvertedPoints(points->count); //структура точек на экране

	if (!conv) return nullptr;

	double *ConvMatrix = GetConversionMatrix(params); //матрица преобразований
	if (!ConvMatrix)
	{
		delete conv;
		return nullptr;
	}

	//преобразуем точки; новая Z будет символизировать расстояние
	for (int i=0; i<points->count; i++)
	{
		sCanvasPoint *point = ConvertSinglePoint(points->pointsArray + i, ConvMatrix);
		conv->Xs[i] = point->x;
		conv->Ys[i] = point->y;
		delete point;
	}

	delete ConvMatrix;

	return conv;
}

//очищает структуру преобразованных точки
void ClearConvertedPoints(sConvertedPoints *converted)
{
	delete converted->Xs;
	delete converted->Ys;
	delete converted;
}