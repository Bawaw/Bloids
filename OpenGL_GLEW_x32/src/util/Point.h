#ifndef POINT_H_
#define POINT_H_

class Point {
public:
	double x;
	double y;
	Point(double x=0, double y=0): x(x), y(y) { }
	void operator/=(double a){x/=a; y/=a;}
	double distance(const Point & p) const;
	friend Point operator+(const Point & p1, const Point & p2);
};

#endif /* POINT_H_ */
