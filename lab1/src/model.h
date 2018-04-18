#pragma once


#include <stdio.h>
#include "model_loadparts.h"


//перечислитель действий над файлом модели: загрузка, сохранение
enum eFileAction {faLoad, faSave};

//выдел€ет пам€ть под модель и инициализирует еЄ пустотой
sModel InitializeModel();

//работа с файлом модели: загрузка, сохранение
eCodeFile ReadFile(sModel *mdl, char *filename, eFileAction action);

//очищает пам€ть из под модели
void ClearModel(sModel *mdl);