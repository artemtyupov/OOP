//
//		����� �����, ����� ������� ����������� ����� �������� �� ����������
//

#include "stdafx.h"
#include "entrypoint.h"


//��������� ��������, ���������� �� ����������
eCodeFile Apply(eChangeAction action, uChangeData *data)
{

	static sRenderData changes; //��������� ������������ � ������
	static sEasel easel;		//�������� �� ������� ������������
	static sModel model = InitializeModel();		//������������� ������

	eCodeFile res = cfFine;

	switch (action)
	{
	case caInit: //������������� ������
		{
			SetCanvas(&easel, data->canvas);
			break;
		}
	case caLoad: //�������� ������ �� �����
		{
			res = ReadFile(&model, data->filename, faLoad);
			break;
		}
	case caScale: //��������� �������� ������
		{
			ChangeScale(&changes, data->scale);
			break;
		}
	case caRotate: //��������� ����� �������� ������
		{
			ChangeRotation(&changes, data->move);
			break;
		}
	case caSetRot: //��������� ����� �������� ������
		{
			SetRotation(&changes, data->move);
			break;
		}
	case caShift: //��������� �������� ������
		{
			ChangeShift(&changes, data->move);
			break;
		}
	case caFreeMem: //������� ������
		{
			ClearModel(&model);
			break;
		}
	case caDrawMod: //���������
		{
			DrawModel(&model, &easel, &changes);
			break;
		}
	default: 
		return cfUnknownAction;
	}
	DrawModel(&model, &easel, &changes);
	
	return res;
}

//TODO

/*
#1 �������� 05.04
+	1. �������� ���� ��������� � ���� �������� ������ � ����� �����.
+	2. ������ ��������� � model. 
+	3. ������� ��������� ����������/������������, ����� ������. 
+	4. �������� ������� FileProcess �� ��������.
+	5. TryLoadPoints � TryLoadEdges ������� � ��������� ������� ����������
+	6. ������ if (!model) return cfOutOfMemory; �� �����?! ����� ������� �������?!
*/

/*
#2 �������� 12.04
+	1. � ������� TryLoadAll ��������� ����� �� ���� �� ������.
+	2. � ������� TryLoadAll �� ������� ������, �� ���������� �������.
+	3. ����� �������� ��������� ������������ std ����������� �� ����� ������ �������.
+	4. ��� ������������ ����� ������ ��������������� �������, ������� ��� ����� ���������� �� ����� ����������.
+	5. ������ ��������� � model. 
*/