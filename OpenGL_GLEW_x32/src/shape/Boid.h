#ifndef BOID_H
#define BOID_H
#include "Shape.h"
#include "IAnimatable.h"
#include "../util/Vector.h"
#include "../scene/scene.h"

class Boid : public IAnimatable, public Shape{
private:
	double size;
	Point centre;
	Vector velocity;
public:
	Boid(const Point &centre, double size, const Vector &velocity, const Colour &colour) : velocity(velocity), size(size), centre(centre), Shape(colour){}

	Vector getVelocity() const{ return velocity; }
	void setVelocity(const Vector &velocity) { this->velocity = velocity; }
	Point getCentre() const{ return centre; }
	void setCentre(const Point &centre) { this->centre = centre; }
	double getsize() const{ return size; }
	void setSize(double size) { this->size = size; }
	virtual void Draw() const;
	void update(const Scene& scene);
	virtual ~Boid(){};
	virtual void Intersect(DynamicCircle * dynamicCircle)const;
};

#endif
