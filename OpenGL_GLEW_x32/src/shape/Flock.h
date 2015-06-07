#ifndef FLOCK_H
#define FLOCK_H
#include "Shape.h"
#include "Boid.h"
#include "IAnimatable.h"
#include "../util/Vector.h"
#include "../scene/scene.h"

class Flock : public IAnimatable, public Shape{
private:
	std::vector<Boid *> boids;
	double cohesion, separation, alignment, damping, maxSpeed;	
public:
	Flock(const Colour &colour): Shape(colour){
		cohesion = 0.008;
		separation = 30;
		alignment = 0.025;
		damping = 0.15;
		maxSpeed = 8;
	}

	void addBoid(Boid* boid){ boids.push_back(boid); }
	virtual void Draw() const{
		for each (Boid* b in boids) b->Draw();
	}
	void update(const Scene& scene);
	virtual void Intersect(DynamicCircle* dynamicCircle)const{}
	Vector rule1(unsigned index)const;
	Vector rule2(unsigned index)const;
	Vector rule3(unsigned index)const;
};

#endif
