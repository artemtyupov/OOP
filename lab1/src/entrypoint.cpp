//
//		Точка входа, через которую применяются любые действия из интерфейса
//

#include "stdafx.h"
#include "entrypoint.h"


//применяем действие, переданное из интерфейса
eCodeFile Apply(eChangeAction action, uChangeData *data)
{

	static sRenderData changes; //изменения производимые в модели
	static sEasel easel;		//мольберт на котором отрисовывать
	static sModel model = InitializeModel();		//редактируемая модель

	eCodeFile res = cfFine;

	switch (action)
	{
	case caInit: //инициализация холста
		{
			SetCanvas(&easel, data->canvas);
			break;
		}
	case caLoad: //загрузка модели из файла
		{
			res = ReadFile(&model, data->filename, faLoad);
			break;
		}
	case caScale: //изменение масштаба модели
		{
			ChangeScale(&changes, data->scale);
			break;
		}
	case caRotate: //изменение углов поворота модели
		{
			ChangeRotation(&changes, data->move);
			break;
		}
	case caSetRot: //установка углов поворота модели
		{
			SetRotation(&changes, data->move);
			break;
		}
	case caShift: //изменение смещения модели
		{
			ChangeShift(&changes, data->move);
			break;
		}
	case caFreeMem: //очистка памяти
		{
			ClearModel(&model);
			break;
		}
	case caDrawMod: //Отрисовка
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
#1 Проверка 05.04
+	1. Добавить кейс отрисовки и кейс очистики памяти в точку входа.
+	2. Убрать указатель с model. 
+	3. Сначала параметры изменяемые/возвращаемые, потом другие. 
+	4. Название функции FileProcess не подходит.
+	5. TryLoadPoints и TryLoadEdges вынести в отдельный уровень абстракции
+	6. Почему if (!model) return cfOutOfMemory; не нужен?! нужно сделать статику?!
*/

/*
#2 Проверка 12.04
+	1. В функции TryLoadAll закрывать поток на этом же уровне.
+	2. В функции TryLoadAll не очищать память, тк используем статику.
+	3. Самые конечные отрисовки использующие std переместить на более низкий уровень.
+	4. Все заголовочные файлы должны соответствовать уровням, сделать все более структурно по самим заголовкам.
+	5. Убрать указатель с model. 
*/