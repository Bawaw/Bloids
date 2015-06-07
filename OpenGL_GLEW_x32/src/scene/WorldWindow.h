#ifndef WORLDWINDOW_H_
#define WORLDWINDOW_H_
#include "../shape/IDrawable.h"

class WorldWindow : public IDrawable{
	double left, right, bottom, top;
public:
	WorldWindow(double left=0, double right=0, double bottom=0, double top=0):left(left),right(right),bottom(bottom),top(top){}
	double getBottom() const {return bottom;}
	void setBottom(double bottom) {this->bottom = bottom;}
	double getLeft() const {return left;}
	void setLeft(double left) {this->left = left;}
	double getRight() const {return right;}
	void setRight(double right) {this->right = right;}
	double getTop() const {return top;}
	void setTop(double top) {this->top = top;}
	double getRatio(){return (right-left)/(top-bottom);}
	virtual void Intersect(DynamicCircle * dynamicCircle) const;
	virtual void Draw() const {};
};

#endif /* WORLDWINDOW_H_ */
