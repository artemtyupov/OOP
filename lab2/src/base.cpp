//
//		���������� ������� �������� ������
//
#include "stdafx.h"
#include "base.h"

//����������� �� ���������
_cMatrixBase::_cMatrixBase()
{
	size.row = 0;
	size.column = 0;
}

//����������� ��������
_cMatrixBase::_cMatrixBase(int m, int n)
{
	size.row = m;
	size.column = n;
}

//����������� �����������
_cMatrixBase::_cMatrixBase(_cMatrixBase &mtr)
{
	size.row = mtr.size.row;
	size.column = mtr.size.column;
}

//��������� ������� �������
sizeMtr _cMatrixBase::getSize() const
{	
	return size;	
}