//
//		Шаблонный класс матрицы
//
#pragma once

#include "base.h"

template<typename T>
class cArray
{
protected:
	T *data; //непосредственно сам массив
public:
	cArray();
	const T& operator [] (int m) const;
};

//шаблонный класс - матрица элементов произвольного типа
template<typename T>
class cMatrix : public _cMatrixBase
{
protected:
	T **data; //непосредственно сама матрица элементов

public:
	//конструктор по умолчанию
	cMatrix();

	//конструктор создания
	cMatrix(int m, int n);

	//конструктор создания с инициализацией
	cMatrix(int m, int n, T first, ...);

	//конструктор копирования
	cMatrix(const cMatrix &mtr);

	//деструктор
	~cMatrix();

	//сложение матриц
	static cMatrix<T> addMatrix(const cMatrix<T>& left, const cMatrix<T>& right);

	//вычитание матриц
	static cMatrix<T> subMatrix(const cMatrix<T>& left, const cMatrix<T>& right);

	//умножение матриц
	static cMatrix<T> multMatrix(const cMatrix<T>& left, const cMatrix<T>& right);

	//перегруженные операторы
	cArray<T>& operator [] (int m) const;
	//const T& operator [] (int m) const;
	cMatrix<T> operator = (const cMatrix<T>& right);
	bool operator == (const cMatrix<T>& with) const;
	friend cMatrix<T> operator + (const cMatrix<T>& left, const cMatrix<T>& right);
	friend cMatrix<T> operator - (const cMatrix<T>& left, const cMatrix<T>& right);
	friend cMatrix<T> operator * (const cMatrix<T>& left, const cMatrix<T>& right);
};

#include "matrix.hpp" //реализация методов