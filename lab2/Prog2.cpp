#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW


#include <iostream>
#include "Nephroid.h"



int main()
{
	Prog2::NEPHROID c(1);
	int fl1 = 1;
	double r;
	char* s = NULL;
	while (fl1) {
		std::cout << "Your nephroid is: " << std::endl;
		s = c.frm();
		std::cout << s << std::endl;
		delete[] s;
		std::cout << "area: " << c.area() << std::endl;
		std::cout << "perimeter: " << c.perimeter() << std::endl;
		std::cout << "radius: " << c.getR() << std::endl;
		int fl2 = 1;
		while (fl2) {
			std::cout << "Enter t for calculate value x(t), y(t) and curvature in t or precc ctrl+Z to quit:" << std::endl;
			double t;
			double cur;
			Prog2::Point y;
			std::cin >> t;
			fl2 = std::cin.good();
			if (!fl2)
				continue;
			try {
				y = c.f(t);
				std::cout << "x = " << y.x << ", y = " << y.y << std::endl;
			}
				catch (std::exception& ex)
			{
				std::cout << ex.what() << std::endl;
			}
			try {
				cur = c.curvature(t);
				std::cout << "curvature = " << cur << std::endl;
			}
			catch (std::exception& ex)
			{
				std::cout << ex.what() << std::endl;
			}
		}
		std::cin.clear();
		std::cout << "Enter new r to continue or press ctrl+Z to quit:" << std::endl;
		std::cin >> r;
		if (std::cin.good()) {
			try {
				c.setR(r);
			}
			catch (std::exception& ex)
			{
				std::cout << ex.what() << std::endl;
			}
		}
		else
			fl1 = 0;
	}
	_CrtDumpMemoryLeaks();
	return 0;
}