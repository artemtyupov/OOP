//
//		��������� ����� �������
//
#pragma once

#include "base.h"



//��������� ����� - ������� ��������� ������������� ����
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

        T *data; //��������������� ��� ������
        int size;
    };

	//����������� �� ���������
	cMatrix();

	//����������� ��������
	cMatrix(int m, int n);

	//����������� �������� � ��������������
	cMatrix(int m, int n, T first, ...);

	//����������� �����������
	cMatrix(const cMatrix &mtr);

    cMatrix(cMatrix<T>&& mtr);

	//����������
	~cMatrix();

	//�������� ������
	static cMatrix<T> addMatrix(const cMatrix<T>& left, const cMatrix<T>& right);

	//��������� ������
	static cMatrix<T> subMatrix(const cMatrix<T>& left, const cMatrix<T>& right);

	//��������� ������
	static cMatrix<T> multMatrix(const cMatrix<T>& left, const cMatrix<T>& right);

    //�������� ������
    cMatrix<T> addMatrix(const cMatrix<T>& right);

    //��������� ������
    cMatrix<T> subMatrix(const cMatrix<T>& right);

    //��������� ������
    cMatrix<T> multMatrix(const cMatrix<T>& right);

	//������������� ���������
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

    T **data; //��������������� ���� ������� ���������

};

#include "matrix.hpp" //���������� �������