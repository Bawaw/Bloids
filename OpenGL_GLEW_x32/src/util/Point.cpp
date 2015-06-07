#include "Point.h"
#include <cmath>

double Point::distance(const Point & p) const{
	return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));
}

Point operator+(const Point & p1, const Point & p2){
	return Point(p1.x+p2.x, p1.y+p2.y);
}


