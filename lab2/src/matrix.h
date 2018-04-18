//
//		��������� ����� �������
//
#pragma once

#include "base.h"

template<typename T>
class cArray
{
protected:
	T *data; //��������������� ��� ������
public:
	cArray();
	const T& operator [] (int m) const;
};

//��������� ����� - ������� ��������� ������������� ����
template<typename T>
class cMatrix : public _cMatrixBase
{
protected:
	T **data; //��������������� ���� ������� ���������

public:
	//����������� �� ���������
	cMatrix();

	//����������� ��������
	cMatrix(int m, int n);

	//����������� �������� � ��������������
	cMatrix(int m, int n, T first, ...);

	//����������� �����������
	cMatrix(const cMatrix &mtr);

	//����������
	~cMatrix();

	//�������� ������
	static cMatrix<T> addMatrix(const cMatrix<T>& left, const cMatrix<T>& right);

	//��������� ������
	static cMatrix<T> subMatrix(const cMatrix<T>& left, const cMatrix<T>& right);

	//��������� ������
	static cMatrix<T> multMatrix(const cMatrix<T>& left, const cMatrix<T>& right);

	//������������� ���������
	cArray<T>& operator [] (int m) const;
	//const T& operator [] (int m) const;
	cMatrix<T> operator = (const cMatrix<T>& right);
	bool operator == (const cMatrix<T>& with) const;
	friend cMatrix<T> operator + (const cMatrix<T>& left, const cMatrix<T>& right);
	friend cMatrix<T> operator - (const cMatrix<T>& left, const cMatrix<T>& right);
	friend cMatrix<T> operator * (const cMatrix<T>& left, const cMatrix<T>& right);
};

#include "matrix.hpp" //���������� �������