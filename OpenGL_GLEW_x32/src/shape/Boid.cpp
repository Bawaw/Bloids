#define _USE_MATH_DEFINES
#include "Boid.h"
#include <glew.h>
#include <glut.h>
#include <cmath>
#include "DynamicCircle.h"

void Boid::update(const Scene& scene){
	if (getCentre().y > 400)
		setVelocity(getVelocity() + Vector(0,-0.04));
	if (getCentre().y < 100)
		setVelocity(getVelocity() + Vector(0, 0.04));
	if (getCentre().x > 950)
		setVelocity(getVelocity() + Vector(-0.04, 0));
	if (getCentre().x < 50)
		setVelocity(getVelocity() + Vector(0.04, 0));

	setCentre( centre + velocity);
}

void Boid::Intersect(DynamicCircle * dynamicCircle)const{

}

void Boid::Draw() const{
	glColor3f(getColour().r, getColour().g, getColour().b);
	glBegin(GL_POLYGON);
	double angle = acos(velocity.dot(Vector(1, 0)) / this->getVelocity().length());
	angle = (velocity.y > 0) ? angle : angle*-1;
	Point p(getCentre().x + size*cos(angle), getCentre().y + size*sin(angle));
	glVertex2f(p.x, p.y);

	angle += (150*(M_PI/180));
	Point q(getCentre().x + size*cos(angle), getCentre().y + size*sin(angle));
	glVertex2f(q.x, q.y);
	
	angle += (60* (M_PI / 180));
	Point r(getCentre().x + size*cos(angle), getCentre().y + size*sin(angle));
	glVertex2f(r.x, r.y);

	glEnd();
}
