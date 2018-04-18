#pragma once
#include "canvasworks.h"
#include "conversions.h"

//������������� ������ �� ���������
void SetCanvas(sEasel *easel, sCanvasContainer *canv);

//��������� �������� ������
void ChangeScale(sRenderData *renderdata, double scale);

//������� ������
void ChangeRotation(sRenderData *renderdata, sMove move);

//��������� ����� ������
void SetRotation(sRenderData *renderdata, sMove move);

//�������� ������
void ChangeShift(sRenderData *renderdata, sMove move);