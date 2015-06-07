#ifndef VECTOR_H_
#define VECTOR_H_
#include "Point.h"

class Vector
{
public:
	double x;
	double y;
	Vector(double x = 0, double y = 0) : x(x), y(y) { }
	friend Vector operator+(const Point & p, const Vector & v);
};

#endif

