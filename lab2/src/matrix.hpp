//
//		Реализация методов шаблонного класса
//
#pragma once

#include "matrix.h"
#include "my_exceptions.h"
#include <stdarg.h>


//конструктор матрицы по умолчанию
template<typename T>
cMatrix<T>::cMatrix()
{
	size = 0;
	data = nullptr;
}

//конструктор создания матрицы
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
//конструктор создания матрицы с инициализацией
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

//конструктор копирования матрицы
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

//конструктор переноса матрицы
template<typename T>
cMatrix<T>::cMatrix(cMatrix<T>&& mtr)
{
    size = mtr.size;


    for (int i = 0; i < size.column; i++)
        for (int j = 0; j < size.row; i++)
            this->T[i][j] = mtr[i][j];

    return this->T;
}

//деструктор матрицы
template<typename T>
cMatrix<T>::~cMatrix()
{
	if (data)
		delete [] data;
}

//сложение матриц(функция)
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

//вычитание матриц(функция)
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


//умножение матриц(функция)
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

//сложение матриц(метод)
template<typename T>
cMatrix<T> cMatrix<T>::addMatrix(const cMatrix<T>& right)
{
    if (this->size.column != right.size.column || this->left.size.row != right.size.row)
    {
        cEIndexException ex;
        throw ex;
    }
    int size = right.size;
    cMatrix<T> res(size);
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; i++)
            res[i][j] = this->T[i][j] + right[i][j];
    return res;
}

//вычитание матриц(метод)
template<typename T>
cMatrix<T> cMatrix<T>::subMatrix(const cMatrix<T>& right)
{
    if (this->size.column != right.size.column || this->size.row != right.size.row)
    {
        cEIndexException ex;
        throw ex;
    }
    int size = right.size;
    cMatrix<T> res(size);
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; i++)
            res[i][j] = this->T[i][j] - right[i][j];
    return res;
}

//умножение матриц(метод)
template<typename T>
cMatrix<T> cMatrix<T>::multMatrix(const cMatrix<T>& right)
{
    if (left.size.column != right.size.row)
    {
        cEIndexException ex;
        throw ex;
    }
    int size = right.size;
    cMatrix<T> res(size);
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; i++)
            res[i][j] = this->T[i][j] + right[i][j];
    return res;
}

//оператор присваивания матрицы
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

//оператор равенства матриц
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

//оператор сложения матриц
template<typename T>
cMatrix<T>	operator + (const cMatrix<T>& left, const cMatrix<T>& right)
{
	sizeMtr size_left = left.getSize();
	sizeMtr size_right = right.getSize();
	cMatrix<T> res(size_left);
	res = addMatrix(left, right)
	return res;
}

//оператор вычитания матриц
template<typename T>
cMatrix<T>	operator - (const cMatrix<T>& left, const cMatrix<T>& right)
{
	sizeMtr size_left = left.getSize();
	sizeMtr size_right = right.getSize();
	cMatrix<T> res(size_left);
	res = subMatrix(left, right)
	return res;
}

//оператор умножения матриц
template<typename T>
cMatrix<T>	operator * (const cMatrix<T>& left, const cMatrix<T>& right)
{
	sizeMtr size_left = left.getSize();
	sizeMtr size_right = right.getSize();
	cMatrix<T> res(size_left);
	res = multMatrix(left, right)
	return res;
}

//Оператор присваивания сложения матриц
template<typename T>
cMatrix<T>  operator += (const cMatrix<T>& left, const cMatrix<T>& right)
{
    sizeMtr size_left = left.getSize();
    sizeMtr size_right = right.getSize();
    cMatrix<T> res(size_left);
    res = addSelfMatrix(left, right)
    return res;
}

//Оператор присваивания вычитания матриц
template<typename T>
cMatrix<T>  operator -= (const cMatrix<T>& left, const cMatrix<T>& right)
{
    sizeMtr size_left = left.getSize();
    sizeMtr size_right = right.getSize();
    cMatrix<T> res(size_left);
    res = subSelfMatrix(left, right)
    return res;
}

//Оператор присваивания умножения матриц
template<typename T>
cMatrix<T>  operator *= (const cMatrix<T>& left, const cMatrix<T>& right)
{
    sizeMtr size_left = left.getSize();
    sizeMtr size_right = right.getSize();
    cMatrix<T> res(size_left);
    res = multSelfMatrix(left, right)
    return res;
}

//сложение матриц исходной и введенной(для оператора +=)
template<typename T>
cMatrix<T> cMatrix<T>::addSelfMatrix(const cMatrix<T>& right)
{
    if (left.size.column != right.size.column || left.size.row != right.size.row)
    {
        cEIndexException ex;
        throw ex;
    }
    int size = right.size;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; i++)
            this->data[i][j] += right[i][j];
    return this->data;
}

//вычитания матриц исходной и введенной(для оператора -=)
template<typename T>
cMatrix<T> cMatrix<T>::subSelfMatrix(const cMatrix<T>& right)
{
    if (left.size.column != right.size.column || left.size.row != right.size.row)
    {
        cEIndexException ex;
        throw ex;
    }
    int size = left.size;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; i++)
            this->data[i][j] -= right[i][j];
    return this->data;
}

//умножение матриц исходной и введенной(для оператора *=)
template<typename T>
cMatrix<T> cMatrix<T>::multSelfMatrix(const cMatrix<T>& right)
{
    if (left.size.column != right.size.row)
    {
        cEIndexException ex;
        throw ex;
    }
    int size = left.size;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; i++)
            this->data[i][j] *= right[i][j];
    return this->data;
}

template<typename T>
cMatrix<T>& cMatrix<T>::operator() (int i, int j)
{
  if (i >= size.column || j >= size.row)
  {
	  cEIndexException ex;
	  throw ex;
  }
  return data[size.column * i + j];
}

template<typename T>
const cMatrix<T>& cMatrix<T>::operator() (int i, int j) const
{
  if (i >= size.column || j >= size.row)
  {
	  cEIndexException ex;
	  throw ex;
  }
  return data[size.column * i + j];
}