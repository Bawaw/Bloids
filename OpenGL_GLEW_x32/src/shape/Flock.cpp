#include "Flock.h"

void Flock::update(const Scene& scene) {
	for (int i = 0; i < boids.size(); i++)
	{
		Vector u = rule1(i) + rule2(i) + rule3(i);
		u = u * damping;
		u = u + boids[i]->getVelocity();
		if (u.length() > maxSpeed) u = u * (maxSpeed / u.length());
		
		if (boids[i]->getCentre().x < -100){
			boids[i]->setCentre(Point(1100, boids[i]->getCentre().y));
			boids[i]->setColour(Colour(1,0,1));
		}

		if (boids[i]->getCentre().x > 1100){
			boids[i]->setCentre(Point(-100, boids[i]->getCentre().y));
			boids[i]->setColour(Colour(0, 1, 0));
		}

		if (boids[i]->getCentre().y > 550){
			boids[i]->setCentre(Point(boids[i]->getCentre().x, -50));
			boids[i]->setColour(Colour(1, 1, 0));
		}

		if (boids[i]->getCentre().y < -50){
			boids[i]->setCentre(Point(boids[i]->getCentre().x, 550));
			boids[i]->setColour(Colour(0, 1, 1));
		}

		/*if (boids[i]->getCentre().y > 250)
			u = u + Vector(0, -0.08);
		if (boids[i]->getCentre().y < 150)
			u = u + Vector(0, 0.08);
		if (boids[i]->getCentre().x < 100)
			u = u + Vector(0.12, 0);
		if (boids[i]->getCentre().x > 900)
			u = u + Vector(-0.12, 0); */

		boids[i]->setVelocity(u);
		boids[i]->setCentre(boids[i]->getCentre() + boids[i]->getVelocity());
	}
}

Vector Flock::rule1(unsigned index) const{
	Point flockCentre;
	for (int i = 0; i < boids.size(); i++)
		if (i != index)
			flockCentre = flockCentre + boids[i]->getCentre();
	flockCentre = Point(flockCentre.x / boids.size(), flockCentre.y / boids.size());
	return Vector(boids[index]->getCentre(), flockCentre) * cohesion;
}

Vector Flock::rule2(unsigned index) const{
	Vector res;
	for (int i = 0; i < boids.size(); i++)
		if (i != index && boids[i]->getCentre().distance(boids[index]->getCentre()) < separation){
			Vector u = Vector(boids[i]->getCentre(), boids[index]->getCentre());
			double factor = (separation / pow(u.length(), 2) <= 100) ? separation / pow(u.length(), 2) : 100;
			res = res + u* factor;
		}
	return res;
}

Vector Flock::rule3(unsigned index)const{
	Vector avgVelocity;
	for (int i = 0; i < boids.size(); i++)
		if (i != index)
			avgVelocity = avgVelocity + boids[i]->getVelocity();
	avgVelocity = Vector(avgVelocity.x / boids.size(), avgVelocity.y / boids.size());
	return (Vector(avgVelocity.x - boids[index]->getVelocity().x, avgVelocity.y - boids[index]->getVelocity().y)) * alignment;
}