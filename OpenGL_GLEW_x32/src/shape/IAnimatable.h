#ifndef IANIMATABLE_H
#define IANIMATABLE_H
#include <iostream>
class Scene;
class IAnimatable {
public:
	virtual void update(const Scene & scene) = 0;
};
#endif