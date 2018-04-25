//
//		Шаблонный класс матрицы
//
#pragma once

#include "base.h"
#include <assert.h>
//шаблонный класс - матрица элементов произвольного типа
template<typename T>
class cMatrix : public _cMatrixBase
{
public:

	template<class U>
    class Helper
    {
        template<typename U> class cMatrix;
        cMatrix<U>& matrix;
        int i;
 
        Helper(cMatrix<U>& _mc,int _i): matrix(_mc), i(_i) {};
        Helper(const cMatrix<U>& _mc,int _i): matrix(const_cast<Matrix&>(_mc)), i(_i) {};
        Helper(const Helper&);
        Helper& operator=(const Helper&);
 
        friend class cMatrix<U>;
 
    public:
        U& operator[](int k) const
        {
            return matrix.data[matrix.cols * i + k];
        }
 
        U& operator[](int k)
        {
            return matrix.data[matrix.cols * i + k];
        }
    };
 
    Helper<T> operator[](int i) const
    {
        return Helper<T>(*this, i);
    }
 
    Helper<T> operator[](int i)
    {
        return Helper<T>(*this, i);
    }

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
	cMatrix<T> addSelfMatrix(const cMatrix<T>& right);
	cMatrix<T> addMatrix(const cMatrix<T>& right);
	friend cMatrix<T> operator + (const cMatrix<T>& left, const cMatrix<T>& right);
	friend cMatrix<T> operator += (const cMatrix<T>& left, const cMatrix<T>& right);

	//вычитание матриц
	static cMatrix<T> subMatrix(const cMatrix<T>& left, const cMatrix<T>& right);
	cMatrix<T> subSelfMatrix(const cMatrix<T>& right);
	cMatrix<T> subMatrix(const cMatrix<T>& right);
	friend cMatrix<T> operator - (const cMatrix<T>& left, const cMatrix<T>& right);
	friend cMatrix<T> operator -= (const cMatrix<T>& left, const cMatrix<T>& right);

	//умножение матриц
	static cMatrix<T> multMatrix(const cMatrix<T>& left, const cMatrix<T>& right);
	cMatrix<T> multSelfMatrix(const cMatrix<T>& right);
	cMatrix<T> multMatrix(const cMatrix<T>& right);
	friend cMatrix<T> operator * (const cMatrix<T>& left, const cMatrix<T>& right);
	friend cMatrix<T> operator *= (const cMatrix<T>& left, const cMatrix<T>& right);
	
    cMatrix<T>& operator () (int m, int n);
    const cMatrix<T>& operator () (int m, int n) const;

	//оператор присваивания матрицы
	cMatrix<T> operator = (const cMatrix<T>& right);

	//оператор равенства матриц
	bool operator == (const cMatrix<T>& with) const;

protected:

    T **data; //непосредственно сама матрица элементов

};

#include "matrix.hpp" //реализация методов