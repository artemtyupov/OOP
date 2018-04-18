//
//		������� ����� �������
//
#pragma once

struct sizeMtr
{
	int column;
	int row;
};

//����������� ����� �������
class _cMatrixBase
{
public:
	//����������� �� ���������
	_cMatrixBase();

	//����������� ��������
	_cMatrixBase(int m, int n);

	//����������� �����������
	_cMatrixBase(_cMatrixBase &mtr);

	//��������� ������� �������
	sizeMtr getSize() const;



protected:
	//������� �������
	sizeMtr size; 

};
