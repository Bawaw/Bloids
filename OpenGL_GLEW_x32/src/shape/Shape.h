#ifndef SHAPE_H
#define SHAPE_H
#include "../util/Colour.h"
#include "IDrawable.h"

class Shape : public IDrawable {
	Colour colour;
public:
	Shape(const Colour& colour) :colour(colour) {}
	virtual ~Shape(){};
	Colour getColour()const { return colour; }
	void setColour(const Colour& colour){ this->colour = colour; }
	virtual void Intersect(DynamicCircle* dynamicCircle) const = 0;
	virtual void Draw() const = 0;
};

#endif 
