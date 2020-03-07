#ifndef CIRCLE_H
#define CIRCLE_H

#include "shapeTwoD.h"

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class circle:public shapeTwoD{
	private:
		int minX;
		int maxX;
		int minY;
		int maxY;
		const double PI = 3.141;
		int radius;
		double area = 0;
		coord center;
		int shapeNum;
	public:
		circle(string, bool);
		double computeArea() override;
		bool isPointInShape(int, int) override;
		bool isPointOnShape(int, int) override;
		void setCoord(coord) override;		
		void setMinMax() override;
		double getArea() override;
		void setRadius(int) override;
		void setShapeNum(int) override;
		int getShapeNum() override;
		string toString() override;
};
#endif
