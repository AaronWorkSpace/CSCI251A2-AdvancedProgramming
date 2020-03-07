#ifndef SHAPETWOD_H
#define SHAPETWOD_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

//struct for future use
struct coord{
	int x;
	int y;
};

class shapeTwoD{
	protected:
		//variable
		string name;
		bool containsWarpSpace;
	
	public:
		shapeTwoD(string, bool);
		string getName();
		bool getContainsWarpSpace();
		void setName(string);
		void setContainsWarpSpace(bool);
		
		virtual string toString();
		
		//future shape use
		virtual double computeArea(){return 1.0;};
		virtual bool isPointInShape(int, int){return false;};
		virtual bool isPointOnShape(int, int){return false;};
		virtual void setCoord(coord){};
		virtual void setMinMax(){};
		virtual void setRadius(int){};
		virtual double getArea(){return 1.0;};
		virtual void setShapeNum(int){}
		virtual int getShapeNum(){return 0;}	
};
#endif
