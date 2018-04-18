// src.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "matrix.h"
#include "matrixworks.h"
#include "my_exceptions.h"

#include <conio.h>
#include <stdio.h>

int main()
{
	
	try
	{
		
		cMatrix<int> mtr1(5, 5,
						  1, 2, 3, 4, 5,
						  5, 4, 3, 2, 1,
						  3, 3, 3, 3, 3,
						  5, 4, 3, 2, 1,
						  1, 2, 3, 4, 5);
		
		PrintMtr(&mtr1, TInt);
	}
	catch (cEBaseException &ex)
	{
		printf("Exception: %s\n", ex.what());
	}
	
	_getch();
	return 0;
}

