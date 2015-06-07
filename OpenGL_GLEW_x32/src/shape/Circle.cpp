#define _USE_MATH_DEFINES
#include "Circle.h"
#include <glew.h>
#include <glut.h>
#include <cmath>
#include "DynamicCircle.h"

void Circle::Draw() const {
	glColor3f(getColour().r, getColour().g, getColour().b);
		glBegin(GL_POLYGON);
		for (int i = 1; i < 360; i+=7.2)
		{
			int xCoord = centre.x + radius * cos(i*M_PI/180);
			int yCoord = centre.y + radius * sin(i*M_PI/180);
			glVertex2f(xCoord, yCoord);
		}
		glEnd();
}

void Circle::Intersect(DynamicCircle * dynamicCircle)const{
	if (getCentre().distance(dynamicCircle->getCentre()) < this->radius + dynamicCircle->getRadius()){
		//STEP 1
		Vector u1(getCentre(), dynamicCircle->getCentre());
		double a = dynamicCircle->getVelocity().dot(dynamicCircle->getVelocity());
		double b = 2 * (dynamicCircle->getVelocity().dot(Vector(getCentre(), dynamicCircle->getCentre())));
		double c = u1.dot(u1) - pow(dynamicCircle->getRadius() + this->getRadius(), 2);
		double t1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
		double t2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
		double t = (t1 < t2) ? t1 : t2;
		dynamicCircle->setCentre(dynamicCircle->getCentre() + t*dynamicCircle->getVelocity());

		//STEP 2
		Vector u2(this->getCentre(), dynamicCircle->getCentre());
		u2.normalize();
		dynamicCircle->setVelocity(dynamicCircle->getVelocity() - 2*(dynamicCircle->getVelocity().dot(u2)) * u2);
	}
		
	
}


