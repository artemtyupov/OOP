//
//		������ � ������� - �������� �� �����, ��������
//

#include "stdafx.h"
#include "model.h"

//����������� ������ ��-��� ����������� ������
void ClearModel(sModel *mdl)
{
	ClearPointsList(&(mdl->points));
	ClearEdgesList(&(mdl->edges));
}


//�������� ������ ��� ������ � �������������� � ��������
sModel InitializeModel()
{
	sModel mdl[1];

	mdl->edges.count = 0;
	mdl->edges.edgesArray = nullptr;
	mdl->points.count = 0;
	mdl->points.pointsArray = nullptr;
	return mdl[0];
}

//��������� ������ �� �����
eCodeFile LoadModel(sModel *mdl, char *filename)
{
	FILE *fl = fopen(filename, "r");
	if (!fl)
		return cfNotFound;

	//��������� �������� ����� � "��������" ������
	sModel newmodel = InitializeModel();


	eCodeFile res = TryLoadAll(&newmodel, fl); //�������� ��������� ���
	if (res != cfFine)
	{
		return res;
	}

	//������� ������������ ������, ���� ��� ����
	if (mdl)
	{
		ClearModel(mdl);
	}

	*mdl = newmodel; //���������� ��������
	fclose(fl);
	return cfFine;
}


//������ � ������ ������: ��������, ���������� (�������������)
eCodeFile ReadFile(sModel *mdl, char *filename, eFileAction action)
{
	switch(action)
	{
	case faLoad: //��������� ������
		{
			return LoadModel(mdl, filename);
		}
	case faSave: //��������� ������
		{
			return cfUnknownAction;
		}
	default:
		{
			return cfUnknownAction;
		}
	}
	return cfFine;
}