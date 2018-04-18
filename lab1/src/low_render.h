#pragma once

#include <gcroot.h>
#include "conversions.h"
#include "canvasworks.h"

using namespace System::Drawing;

//отрисовка единственного ребра
void DrawSingleEdge(sConvertedPoints *converted, sEasel *easel, sEdge *edge);

