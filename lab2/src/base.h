//
//		Базовый класс матрицы
//
#pragma once

struct sizeMtr
{
	int column;
	int row;
};

//абстрактный класс матрицы
class _cMatrixBase
{
public:
	//конструктор по умолчанию
	_cMatrixBase();

	//конструктор создания
	_cMatrixBase(int m, int n);

	//конструктор копирования
	_cMatrixBase(_cMatrixBase &mtr);

	//получение размера матрицы
	sizeMtr getSize() const;



protected:
	//размеры матрицы
	sizeMtr size; 

};
