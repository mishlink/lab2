#ifndef _NEPHROID_H_
#define _NEPHROID_H_
#include <math.h>

namespace Prog2 {
	const double PI = 3.14159265;

	struct Point {
		double x, y;
		Point(double x0 = 0, double y0 = 0) :x(x0), y(y0) {}
	};

	class NEPHROID {
	private:
		double r;
	public:
		NEPHROID(double rad = 1);
		NEPHROID& setR(double r0);
		double getR() const { return r; }
		double area() const { return 12 * PI * r * r; }
		double perimeter() const { return 24 * r; }
		double curvature(double t) const { return abs(3 * r * sin(t)); }
		Point f(double t) const;
		char* frm() const;
	};
}
#endif