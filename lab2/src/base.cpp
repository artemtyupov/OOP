//
//		Реализация методов базового класса
//
#include "stdafx.h"
#include "base.h"

//конструктор по умолчанию
_cMatrixBase::_cMatrixBase()
{
	size.row = 0;
	size.column = 0;
}

//конструктор создания
_cMatrixBase::_cMatrixBase(int m, int n)
{
	size.row = m;
	size.column = n;
}

//конструктор копирования
_cMatrixBase::_cMatrixBase(_cMatrixBase &mtr)
{
	size.row = mtr.size.row;
	size.column = mtr.size.column;
}

//получение размера матрицы
sizeMtr _cMatrixBase::getSize() const
{	
	return size;	
}