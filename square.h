#ifndef SQUARE_H
#define SQUARE_H

#include "shapeTwoD.h"

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class square:public shapeTwoD{
	private:
		int minX;
		int minY;
		int maxX;
		int maxY;
		double length;
		double breath;
		double area = 0;
		vector<coord>cS;
		int shapeNum;
	public:
		square(string, bool);
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
