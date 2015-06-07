#ifndef VECTOR_H_
#define VECTOR_H_
#include "Point.h"
#include <cmath>

class Vector {
public:
	double x;
	double y;
	Vector(double x=0, double y=0): x(x), y(y) { }
	Vector(const Point& from, const Point& to);
	double dot(const Vector &v) const { return v.x*this->x+v.y*this->y; }
	double length(){ return sqrt(pow(this->x, 2) + pow(this->y, 2)); }
	void normalize(){ (*this) = (1 / length()) * (*this); }
	friend Point operator+(const Vector& v, const Point& p);
	friend Point operator+(const Point& p, const Vector& v);
	friend Vector operator+(const Vector& p, const Vector& v);

	friend Point operator-(const Vector& v, const Point& p);
	friend Point operator-(const Point& v, const Vector& p);
	friend Vector operator-(const Vector& v, const Vector& p);

	friend Vector operator*(const Vector& v, double p);
	friend Vector operator*(double p, const Vector& v);
};

#endif 
