#ifndef IDRAWABLE_H
#define IDRAWABLE_H
class DynamicCircle;
class IDrawable {
public:
	virtual void Draw() const {};
	virtual void Intersect(DynamicCircle * dynamicCircle) const = 0;
	virtual ~IDrawable(){};
};
#endif
