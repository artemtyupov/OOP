//
//		Преобразования массивов в строки
//
#include "stdafx.h"
#include "matrixworks.h"


void PrintMtr(_cMatrixBase *mtr, eMtrType type)
{
	if (mtr->getSize().column <= 0 || mtr->getSize().row <= 0) 	printf("<empty>\n");

	printf("array(%d, %d) ", mtr->getSize());

	switch (type)
	{
	case TInt:
		{
			printf("(int):  ");
			//const cMatrix<int> *pMtr = static_cast <const cMatrix<int>*> (mtr);
			for (int i = 0; i < mtr->getSize().column; i++)
				for (int j = 0; j < mtr->getSize().row; j++)
					printf("%d ", mtr[i]);
			break;
		}
	case TDouble:
		{
			printf("(double):  ");
			const cMatrix<double> *pMtr = static_cast <const cMatrix<double>*> (mtr);
			for (int i = 0; i < mtr->getSize().column; i++)
				for (int j = 0; j < mtr->getSize().row; j++)
					printf("%.2lf ", (pMtr)[i][j]);
			break;
		}
	/*case TClass:
		{
			printf("(class):  ");
			const cMatrix<cTest*> *pMtr = static_cast <const cMatrix<cTest*>*> (mtr);
			for (int i = 0; i < mtr->getSize().column; i++)
				for (int j = 0; j < mtr->getSize().row; j++)
					printf("%c ", (pMtr)[i][j]->c);
			break;
		}*/
	default:
		{
			printf("UNKNOWN)");
			break;
		}
	}
	
	printf("\n");
}
