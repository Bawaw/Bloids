#ifndef DYNAMIC_CIRCLE_H
#define DYNAMIC_CIRCLE_H
#include "Circle.h"
#include "IAnimatable.h"
#include "../util/Vector.h"
#include "../scene/scene.h"

class DynamicCircle : public IAnimatable, public Circle{
private:
	Vector velocity;
public:
	DynamicCircle(const Point& centre, double radius, const Colour& colour, const Vector& velocity) : Circle(centre, radius, colour), velocity(velocity){}
	Vector getVelocity() const{ return velocity; }
	void setVelocity(const Vector &velocity) { this->velocity = velocity; }
	void update(const Scene& scene);
	virtual ~DynamicCircle(){};
	virtual void Intersect(DynamicCircle * dynamicCircle)const;
};

#endif
