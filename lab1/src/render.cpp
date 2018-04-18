//
//		��������������� ��������� ������
//

#include "stdafx.h"
#include "render.h"



//��������� ���� ������
void DrawEdges(sConvertedPoints *converted, sEasel *easel, sEdgesList *links)
{
	for (int i=0; i<links->count; i++)
	{
		DrawSingleEdge(converted, easel, &(links->edgesArray[i]));
	}
}

//��������� ������ �� ��������� � ���������� �����������
void DrawModel(sModel *mdl, sEasel *easel, sRenderData *params)
{
	if (!mdl || !easel || !params)
		return;

	//��������� ����� ������ � ����� ������, � ������ "���������� ������"
	sConvertedPoints *conv = ConvertPoints(&(mdl->points), params);
	if (!conv) return;

	PrepareCanvas(easel);

	//������������ ���� ������
	DrawEdges(conv, easel, &(mdl->edges));

	ClearConvertedPoints(conv);

	return;
}