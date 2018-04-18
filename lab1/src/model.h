#pragma once


#include <stdio.h>
#include "model_loadparts.h"


//������������� �������� ��� ������ ������: ��������, ����������
enum eFileAction {faLoad, faSave};

//�������� ������ ��� ������ � �������������� � ��������
sModel InitializeModel();

//������ � ������ ������: ��������, ����������
eCodeFile ReadFile(sModel *mdl, char *filename, eFileAction action);

//������� ������ �� ��� ������
void ClearModel(sModel *mdl);