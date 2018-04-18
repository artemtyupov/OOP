#pragma once

#include <gcroot.h>
#include "render.h"
#include "model.h"
#include "actions.h"


//перечислитель команд: инициализировать данные, загрузить из файла, масштабировать, вращать,
//установить угол поворота, перемещать
enum eChangeAction {caInit, caLoad, caScale, caRotate, caSetRot, caShift, caFreeMem, caDrawMod};

//передаваемые вместе с командой данные
union uChangeData
{
	sMove move;		//смещение
	double scale;	//масштаб
	char mb;		//зажата€ кнопка мыши
	sCanvasContainer *canvas;	//обЄртка дл€ холста
	char *filename;	//им€ файла дл€ открыти€
};


//непосредственно обработчик всех и вс€ческих изменений
eCodeFile Apply(eChangeAction action, uChangeData *data);