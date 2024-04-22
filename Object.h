#pragma once
#include <iostream>
#include <exception>
using namespace std;

class VectorException : public exception {

public:
	VectorException(const char* msg) : exception(msg) {
		throw invalid_argument("Incorrect value");
	}
};

class Object
{
	static unsigned int count;
public:


	static unsigned int Count()
	{
		return count;
	}
	Object()
	{
		count++;
	}
	~Object()
	{
		count--;
	}
};