//
//		Работа с моделью - загрузка из файла, удаление
//

#include "stdafx.h"
#include "model.h"

//освобождает память из-под содержимого модели
void ClearModel(sModel *mdl)
{
	ClearPointsList(&(mdl->points));
	ClearEdgesList(&(mdl->edges));
}


//выделяет память под модель и инициализирует её пустотой
sModel InitializeModel()
{
	sModel mdl[1];

	mdl->edges.count = 0;
	mdl->edges.edgesArray = nullptr;
	mdl->points.count = 0;
	mdl->points.pointsArray = nullptr;
	return mdl[0];
}

//загрузить модель из файла
eCodeFile LoadModel(sModel *mdl, char *filename)
{
	FILE *fl = fopen(filename, "r");
	if (!fl)
		return cfNotFound;

	//загружать элементы будем в "буферную" модель
	sModel newmodel = InitializeModel();


	eCodeFile res = TryLoadAll(&newmodel, fl); //пытаемся загрузить все
	if (res != cfFine)
	{
		return res;
	}

	//удаляем существующую модель, если она была
	if (mdl)
	{
		ClearModel(mdl);
	}

	*mdl = newmodel; //возвращаем буферную
	fclose(fl);
	return cfFine;
}


//работа с файлом модели: загрузка, сохранение (нереализовано)
eCodeFile ReadFile(sModel *mdl, char *filename, eFileAction action)
{
	switch(action)
	{
	case faLoad: //загрузить модель
		{
			return LoadModel(mdl, filename);
		}
	case faSave: //сохранить модель
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