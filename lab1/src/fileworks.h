#pragma once

#include <stdio.h>

//��������� �����
struct sEdge
{
	int from, to; //������ ����� � �������, ���������� ������
};

//��������� �����
struct sPoint3d
{
	double x, y, z; //���������� �����
};

//������������� ���������� ��������� ����� � �������: ������ ���, ���� �� ������, ���������,
//�� ������� ������, ����������� ������
enum eCodeFile {cfFine, cfNotFound, cfCorrupted, cfOutOfMemory, cfUnknownAction};


eCodeFile LoadPointsCount(int &n, FILE *fl);
eCodeFile LoadEdgesCount(int &n, FILE *fl);
eCodeFile LoadSinglePoint(sPoint3d *point, FILE *fl);
eCodeFile LoadSingleEdge(sEdge *edge, FILE *fl);
