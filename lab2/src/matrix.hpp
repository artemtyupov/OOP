//
//		Реализация методов шаблонного класса
//
#pragma once

#include "matrix.h"
#include "my_exceptions.h"
#include <stdarg.h>

template<typename T>
cArray<T>::cArray()
{
	size.column = 0;
	size.row = 0;
	data = nullptr;
}

//конструктор по умолчанию
template<typename T>
cMatrix<T>::cMatrix()
{
	size.column = 0;
	size.row = 0;
	data = nullptr;
}

//конструктор создания
template<typename T>
cMatrix<T>::cMatrix(int m, int n)
{
	if (m < 0 || n < 0)
	{
		cESizeException ex;
		throw ex;
	}

	size.column = m;
	size.row = n;
	data = new T *[m];
	for (int i = 0; i < m; i++)
		data[i] = new T [n];

	if (!data)
	{
		cEMemoryException ex;
		throw ex;
	}
}
//конструктор создания с инициализацией
template<typename T>
cMatrix<T>::cMatrix(int m, int n, T first, ...)
{
	if (m < 0 || n < 0)
	{
		cESizeException ex;
		throw ex;
	}
	size.column = m;
	size.row = n;


	

	data = new T *[m];
	for (int i = 0; i < m; i++)
		data[i] = new T [n];

	if (!data)
	{
		cEMemoryException ex;
		throw ex;
	}

	va_list vl;
	va_start(vl, n);

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			data[i][j] = va_arg(vl, T);

	va_end(vl);
}

//конструктор копирования
template<typename T>
cMatrix<T>::cMatrix(const cMatrix &mtr)
{
	size = mtr.size;
	data = new T [size.column, size.row];

	if (!data)
	{
		cEMemoryException ex;
		throw ex;
	}

	for (int i = 0; i < size.column; i++)
		for (int j = 0; j < size.row; i++)
			data[i][j] = mtr[i][j];
}
//деструктор
template<typename T>
cMatrix<T>::~cMatrix()
{
	if (data)
		delete [] data;
}

//сложение матриц
template<typename T>
cMatrix<T> cMatrix<T>::addMatrix(const cMatrix<T>& left, const cMatrix<T>& right)
{
	if (left.size.column != right.size.column || left.size.row != right.size.row)
	{
		cEIndexException ex;
		throw ex;
	}
	int size = left.size;
	cMatrix<T> res(size);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; i++)
			res[i][j] = left[i][j] + right[i][j];
	return res;
}

//вычитание матриц
template<typename T>
cMatrix<T> cMatrix<T>::subMatrix(const cMatrix<T>& left, const cMatrix<T>& right)
{
	if (left.size.column != right.size.column || left.size.row != right.size.row)
	{
		cEIndexException ex;
		throw ex;
	}
	int size = left.size;
	cMatrix<T> res(size);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; i++)
			res[i][j] = left[i][j] - right[i][j];
	return res;
}


//умножение матриц
template<typename T>
cMatrix<T> cMatrix<T>::multMatrix(const cMatrix<T>& left, const cMatrix<T>& right)
{
	if (left.size.column != right.size.row)
	{
		cEIndexException ex;
		throw ex;
	}
	int size = left.size;
	cMatrix<T> res(size);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; i++)
			res[i][j] = left[i][j] + right[i][j];
	return res;
}


template<typename T>
const T& cArray<T>::operator [] (int i) const
{
	if (i < 0 || i >= size.column || i >= size.row)
	{
		cEIndexException ex;
		throw ex;
	}
	return data[i];
}

template<typename T>
cArray<T>& cMatrix<T>::operator [] (int i) const
{
	if (i < 0 || i >= size.column || i >= size.row)
	{
		cEIndexException ex;
		throw ex;
	}
	const cArray<T> res = new cArray<T>;
	res.data = data[i]
	return res;
}

template<typename T>
const T& cMatrix<T>::operator [] (int i) const
{
	if (i < 0 || i >= size.column)
	{
		cEIndexException ex;
		throw ex;
	}
	return *data[i];
}

template<typename T>
cMatrix<T> cMatrix<T>::operator = (const cMatrix<T>& right)
{
	if (this == &right)
		return right;

	size = right.size;

	if (data)
		delete [] data;

	data = new T [size.column, size.row];
	if (!data)
	{
		cEMemoryException ex;
		throw ex;
	}

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; i++)
			data[i][j] = right.data[i][j];

	return this;
}

template<typename T>
bool cMatrix<T>::operator == (const cMatrix<T>& with) const
{
	int is = with.size;
	if (size.column != with.size.column || size.row != with.size.row)
		return false;

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; i++)
			if (data[i][j] != with[i][j])
				return false;

	return true;
}

template<typename T>
cMatrix<T>	operator + (const cMatrix<T>& left, const cMatrix<T>& right)
{
	sizeMtr size_left = left.getSize();
	sizeMtr size_right = right.getSize();
	cMatrix<T> res(size_left);
	res = addMatrix(left, right)
	return res;
}

template<typename T>
cMatrix<T>	operator - (const cMatrix<T>& left, const cMatrix<T>& right)
{
	sizeMtr size_left = left.getSize();
	sizeMtr size_right = right.getSize();
	cMatrix<T> res(size_left);
	res = addMatrix(left, right)
	return res;
}

template<typename T>
cMatrix<T>	operator * (const cMatrix<T>& left, const cMatrix<T>& right)
{
	sizeMtr size_left = left.getSize();
	sizeMtr size_right = right.getSize();
	cMatrix<T> res(size_left);
	res = multMatrix(left, right)
	return res;
}


