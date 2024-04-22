#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include "Object.h"

using namespace std;

class Vector3D : public Object
{
private:
	double x;
	double y;
	double z;
public:
	Vector3D();
	Vector3D(double x, double y, double z);
	Vector3D(const char* str) {
		istringstream iss(str);
		char slash;
		if (!(iss >> x >> slash >> y >> slash >> z))
			throw VectorException("Incorerect value!");
	}

	~Vector3D();

	void Init(int day, int month, int year);

	double GetX() const { return x; }
	double GetY() const { return y; }
	double GetZ() const { return z; }

	void SetX(double value) { x = value; }
	void SetY(double value) { y = value; }
	void SetZ(double value) { z = value; }

	Vector3D& operator =(const Vector3D& other);
	friend istream& operator>>(istream& input, Vector3D& vec);
	friend ostream& operator<<(ostream& output, const Vector3D& vec);

	operator string() const;
	friend Vector3D operator*(double scalar, const Vector3D& vec);

	friend bool operator==(const Vector3D& vec1, const Vector3D& vec2);
	friend bool operator ^ (const Vector3D& vec1, const Vector3D& vec2);
	friend bool operator!=(const Vector3D& vec1, const Vector3D& vec2);

	Vector3D& operator ++();
	Vector3D& operator --();
	Vector3D operator ++(int);
	Vector3D operator --(int);

	double operator()() const;
};

