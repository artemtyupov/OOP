#pragma once

#include <exception>
using namespace std;

class cEBaseException : public std::exception
{
public:
	virtual const char* what()
	{
		return "my base exception";
	}
};
class cEIndexException : public cEBaseException
{
public:
	const char* what()
	{
		return "Array index is out of range!";
	}
};
class cESizeException : public cEBaseException
{
public:
	const char* what()
	{
		return "Trying to create array with negative size!";
	}
};
class cEMemoryException : public cEBaseException
{
public:
	const char* what()
	{
		return "Couldn't allocate memory for array data!";
	}
};