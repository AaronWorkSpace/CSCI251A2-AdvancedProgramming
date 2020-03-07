#ifndef CROSS_H
#define CROSS_H

#include "shapeTwoD.h"

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class cross : public shapeTwoD{
	private:
		int minX;
		int minY;
		int maxX;
		int maxY;
		double area = 0;
		coord topL;
		coord Ltop;
		coord Lbot;
		coord botL;
		coord topR;
		coord Rtop;
		coord Rbot;
		coord botR;
		vector<coord>cC;
		int shapeNum;
	public:
		cross(string, bool);
		
		coord findCoordX(int);
		coord findCoordY(int);
		double computeArea() override;
		bool isPointInShape(int, int) override;
		bool isPointOnShape(int, int) override;
		void setCoord(coord) override;	
		void setMinMax() override;
		double getArea();
		bool findCoord(int, int);
		void setShapeNum(int) override;
		int getShapeNum() override;
		string toString() override;
};
#endif
