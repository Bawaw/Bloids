#ifndef CIRCLE_H
#define CIRCLE_H
#include "../util/Point.h"
#include "../shape/Shape.h"

class Circle : public Shape{
private:
	Point centre;
	double radius;
public:
	Circle(const Point& centre, double radius, const Colour& colour) : Shape(colour), centre(centre), radius(radius) { }
	virtual ~Circle(){};
	Point getCentre()const { return centre; }
	double getRadius()const { return radius; }
	void setCentre(const Point &centre){ this->centre = centre; }
	virtual void Draw() const;
	virtual void Intersect(DynamicCircle * dynamicCircle)const;
};

#endif 
