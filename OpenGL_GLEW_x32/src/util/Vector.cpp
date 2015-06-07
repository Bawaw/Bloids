#include "Vector.h"
#include <cmath>

Vector::Vector(const Point& from, const Point& to){
	this->x = to.x - from.x;
	this->y = to.y - from.y;
}

Point operator+(const Vector & v, const Point & p){

	return Point(p.x + v.x, p.y + v.y);
}

Point operator+(const Point & p, const Vector & v){
	return Point(p.x + v.x, p.y + v.y);
}

Vector operator+(const Vector & v, const Vector & p){

	return Vector(p.x + v.x, p.y + v.y);
}

Point operator-(const Vector & v, const Point & p){
	return Point(p.x - v.x, p.y - v.y);
}

Point operator-(const Point & v, const Vector & p){
	return Point(p.x - v.x, p.y - v.y);
}

Vector operator-(const Vector & v, const Vector & p){
	return Vector(p.x - v.x, p.y - v.y);
}

Vector operator*(const Vector & v, double p){
	return Vector(p * v.x, p * v.y);
}

Vector operator*(double p, const Vector & v){
	return Vector(p * v.x, p * v.y);
}




