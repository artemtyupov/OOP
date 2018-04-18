#pragma once
#include "canvasworks.h"
#include "conversions.h"

//инициализация холста на мольберте
void SetCanvas(sEasel *easel, sCanvasContainer *canv);

//изменение масштаба модели
void ChangeScale(sRenderData *renderdata, double scale);

//поворот модели
void ChangeRotation(sRenderData *renderdata, sMove move);

//установка углов модели
void SetRotation(sRenderData *renderdata, sMove move);

//смещение модели
void ChangeShift(sRenderData *renderdata, sMove move);