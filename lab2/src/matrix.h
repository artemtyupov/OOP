//
//		Шаблонный класс матрицы
//
#pragma once

#include "base.h"



//шаблонный класс - матрица элементов произвольного типа
template<typename T>
class cMatrix : public _cMatrixBase
{
   
public:

    template<typename T>
    class cArra
    {
    public:

        cArray();
        ~cArray();
        T& operator [] (int m);
        const T& operator [] (int m) const;

    protected:

        T *data; //непосредственно сам массив
        int size;
    };

	//конструктор по умолчанию
	cMatrix();

	//конструктор создания
	cMatrix(int m, int n);

	//конструктор создания с инициализацией
	cMatrix(int m, int n, T first, ...);

	//конструктор копирования
	cMatrix(const cMatrix &mtr);

    cMatrix(cMatrix<T>&& mtr);

	//деструктор
	~cMatrix();

	//сложение матриц
	static cMatrix<T> addMatrix(const cMatrix<T>& left, const cMatrix<T>& right);

	//вычитание матриц
	static cMatrix<T> subMatrix(const cMatrix<T>& left, const cMatrix<T>& right);

	//умножение матриц
	static cMatrix<T> multMatrix(const cMatrix<T>& left, const cMatrix<T>& right);

    //сложение матриц
    cMatrix<T> addMatrix(const cMatrix<T>& right);

    //вычитание матриц
    cMatrix<T> subMatrix(const cMatrix<T>& right);

    //умножение матриц
    cMatrix<T> multMatrix(const cMatrix<T>& right);

	//перегруженные операторы
	cArray<T>& operator [] (int m);
	const cArray<T>& operator [] (int m) const;
    cMatrix<T>& operator ()() (int m, int n);
    const cMatrix<T>& operator ()() (int m, int n) const;
	cMatrix<T> operator = (const cMatrix<T>& right);
	bool operator == (const cMatrix<T>& with) const;
	friend cMatrix<T> operator + (const cMatrix<T>& left, const cMatrix<T>& right);
	friend cMatrix<T> operator - (const cMatrix<T>& left, const cMatrix<T>& right);
	friend cMatrix<T> operator * (const cMatrix<T>& left, const cMatrix<T>& right);
    friend cMatrix<T> operator += (const cMatrix<T>& left, const cMatrix<T>& right);
    friend cMatrix<T> operator -= (const cMatrix<T>& left, const cMatrix<T>& right);
    friend cMatrix<T> operator *= (const cMatrix<T>& left, const cMatrix<T>& right);

protected:

    T **data; //непосредственно сама матрица элементов

};

#include "matrix.hpp" //реализация методов