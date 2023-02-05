#include <strstream>
#include <stdio.h>
#include <string.h>
#include "Nephroid.h"
namespace Prog2 {
	NEPHROID::NEPHROID(double rad)
	{
		if (rad < 0)
			throw std::exception("invalid radius");
		r = rad;
	}
	NEPHROID& NEPHROID::setR(double r0)
	{
		if (r0 < 0)
			throw std::exception("invalid radius");
		r = r0;
		return *this;
	}
	Point NEPHROID::f(double t) const
	{
		double cs = cos(t), sn = sin(t);
		Point res;
		res.x = 6 * r * cs - 4 * r * cs * cs * cs;
		res.y = 4 * r * sn * sn * sn;
		return res;
	}
	char* NEPHROID::frm() const
	{
		const char* s1 = "(x ^ 2 + y ^ 2 - ) ^ 3 = * x^2\n";
		int l = strlen(s1) + 1; 
		size_t Size = 20;
		char num[20];
		sprintf_s(num, 20, "%.2f", 4 * r * r);
		l += strlen(num);
		sprintf_s(num, 20, "%.2f", 108 * r * r * r * r);
		l += strlen(num);
		char* s = new char[l];
		if (r == 0)
			sprintf_s(s, l, "x ^ 2 + y ^ 2 = 0");
		else
			sprintf_s(s, l, "(x ^ 2 + y ^ 2 - %.2f) ^ 3 = %.2f * x^2", 4 * r * r, 108 * r * r * r * r);
		int k = strlen(s);
		return s;
	}
}