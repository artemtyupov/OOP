#pragma once

#include <gcroot.h>
#include "render.h"
#include "model.h"
#include "actions.h"


//������������� ������: ���������������� ������, ��������� �� �����, ��������������, �������,
//���������� ���� ��������, ����������
enum eChangeAction {caInit, caLoad, caScale, caRotate, caSetRot, caShift, caFreeMem, caDrawMod};

//������������ ������ � �������� ������
union uChangeData
{
	sMove move;		//��������
	double scale;	//�������
	char mb;		//������� ������ ����
	sCanvasContainer *canvas;	//������ ��� ������
	char *filename;	//��� ����� ��� ��������
};


//��������������� ���������� ���� � ��������� ���������
eCodeFile Apply(eChangeAction action, uChangeData *data);