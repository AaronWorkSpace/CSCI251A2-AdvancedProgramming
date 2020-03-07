#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shapeTwoD.h"

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class rectangle : public shapeTwoD{
	private:
		int minX;
		int minY;
		int maxX;
		int maxY;
		double length;
		double breath;
		double area = 0;
		vector<coord>cR;
		int shapeNum;
	public:
		rectangle(string, bool);
		double computeArea() override;
		bool isPointInShape(int, int) override;
		bool isPointOnShape(int, int) override;
		double getArea();
		void setCoord(coord) override;
		void setMinMax() override;
		bool findCoord(int, int);
		string toString() override;
		void setShapeNum(int) override;
		int getShapeNum() override;
};
#endif
