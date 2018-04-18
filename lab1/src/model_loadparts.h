#pragma once

#include "fileworks.h"

//����� ������
struct sEdgesList
{
	int count;			//���������� �����
	sEdge *edgesArray;	//������ �����
};

//������� ������
struct sPointsList
{
	int count;			//���������� ������
	sPoint3d *pointsArray;	//������ ������
};

//��������� ������
struct sModel
{
	sPointsList points; //������� ������
	sEdgesList edges; //����� ������
};

//������������� ���������� ��������� ������
enum eAllocError {aeFine, aeOutOfMemory};



//����������� ������ ��-��� ��������� ������ ������
void ClearPointsList(sPointsList *p);

//����������� ������ ��-��� ��������� ����� ������
void ClearEdgesList(sEdgesList *e);


//�������� ��������� ���
eCodeFile TryLoadAll(sModel *newmodel, FILE *fl);

//�������� ��������� ������� ������ �� �����
eCodeFile TryLoadPoints(sPointsList *pd, FILE *fl);

//�������� ��������� ���� ������ �� �����
eCodeFile TryLoadEdges(sEdgesList *adj, FILE *fl);





//�������� �������� ������ ��� ��������� ������ ������
eAllocError AllocPointsList(sPointsList *points);

//�������� �������� ������ ��� ��������� ����� ������
eAllocError AllocEdgesLst(sEdgesList *edges);