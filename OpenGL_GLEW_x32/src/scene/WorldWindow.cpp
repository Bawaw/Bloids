#ifndef WORLD_WINDOW
#define WORLD_WINDOW
#include "WorldWindow.h"
#include "../shape/DynamicCircle.h"

void WorldWindow::Intersect(DynamicCircle * dynamicCircle) const{
	if (dynamicCircle->getCentre().x + dynamicCircle->getVelocity().x + dynamicCircle->getRadius() > getRight())
		dynamicCircle->setVelocity(dynamicCircle->getVelocity() - 2 * (dynamicCircle->getVelocity().dot(Vector(0, -1))) *Vector(0, -1));
	if (dynamicCircle->getCentre().x - dynamicCircle->getRadius() + dynamicCircle->getVelocity().x < getLeft())
		dynamicCircle->setVelocity(dynamicCircle->getVelocity() - 2 * (dynamicCircle->getVelocity().dot(Vector(0, 1))) *Vector(0, 1));
	if (dynamicCircle->getCentre().y + dynamicCircle->getVelocity().y + dynamicCircle->getRadius() > getTop())
		dynamicCircle->setVelocity(dynamicCircle->getVelocity() - 2 * (dynamicCircle->getVelocity().dot(Vector(-1, 0))) *Vector(-1, 0));
	if (dynamicCircle->getCentre().y - dynamicCircle->getRadius() + dynamicCircle->getVelocity().y < getBottom())
		dynamicCircle->setVelocity(dynamicCircle->getVelocity() - 2 * (dynamicCircle->getVelocity().dot(Vector(1, 0))) *Vector(1, 0));
	dynamicCircle->setCentre(dynamicCircle->getCentre() + dynamicCircle->getVelocity());
}


#endif
