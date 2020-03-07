#include "rectangle.h"

rectangle::rectangle(string name, bool containsWarpSpace) : shapeTwoD(name, containsWarpSpace){

}

double rectangle::computeArea(){
	length = maxX - minX;
	breath = maxY - minY;
	area = length * breath;
	return area;
}

bool rectangle::isPointInShape(int x, int y){
	if((minX < x) && (x < maxX) && (minY < y) && (y < maxY)){
		return true;
	}
	else{
		return false;
	}
}	

bool rectangle::isPointOnShape(int x, int y){
	if(((minX <= x) && (x <= maxX)) && ((minY == y) || (maxY == y))){
		return true;
	}
	else if(((minX == x) || (x == maxX)) && ((minY <= y) && (y <= maxY))){
		return true;
	}
	else
		return false;
}

double rectangle::getArea(){
	return area;
}

void rectangle::setCoord(coord b){
	cR.push_back(b);
}

void rectangle::setMinMax(){
	minX = cR[0].x;
	minY = cR[0].y;
	maxX = cR[0].x;
	maxY = cR[0].y;
	for(int i = 1; i < 4; i++){
		if(cR[i].x <= minX)
			minX = cR[i].x;
		else if(cR[i].x >= maxX){
			maxX = cR[i].x;
		}
		
		if(cR[i].y <= minY)
			minY = cR[i].y;
		else if(cR[i].y >= maxY){
			maxY = cR[i].y;
		}
	}
}

bool rectangle::findCoord(int x, int y){
	for(unsigned int i=0;i<cR.size();i++){
		if((cR[i].x == x) && (cR[i].y == y)){
			return true;
		}
	}
	return false;
}

void rectangle::setShapeNum(int num){
	shapeNum = num;
}

int rectangle::getShapeNum(){
	return shapeNum;
}

string rectangle::toString(){
	string shape;
	shape = "Shape[" + to_string(getShapeNum()) + "]\n";
	shape += shapeTwoD::toString();
	/*
	shape += "min X = " + to_string(minX);
	shape += ", min Y = " + to_string(minY);
	shape += ", max X = " + to_string(maxX);
	shape += ", max Y = " + to_string(maxY);
	shape += "\n";
	*/
	shape += "Area: " + to_string((int)area) + " units squares\nVertices: \n";
	
	//vertices of the marked points
	for(unsigned int i = 0; i < cR.size(); i++){
		shape += "Point [" + to_string(i) + "] : (" + to_string(cR[i].x) + ", " + to_string(cR[i].y) + ")\n";
	}
	shape += "\n";
	//vertices of perimeter
	shape += "Point on perimeter: ";
	for(int i = minX; i <= maxX; i++){
		for(int j = minY; j <= maxY; j++){
			if(isPointOnShape(i, j) == true && findCoord(i, j) == false){
				shape += "(" + to_string(i) + ", " + to_string(j) + "), ";
			}
		}
	}
	if(((maxX - minX) == 1) && ((maxY - minY) == 1))
		shape += "none!";
	shape += "\n";
	shape += "\n";
	//vertices within perimeter and marked points
	shape += "Point within shape: ";
	for (int i = minX; i <= maxX; i++){
		for (int j = minY; j <= maxY; j++){
			if (isPointInShape(i,j) == true){
				shape += "(" + to_string(i) + ", " + to_string(j) + "), ";
			}
		}
	}
	if(((maxX - minX) == 1) || ((maxY - minY) == 1))
		shape += "none!";
	shape += "\n";
	return shape;
}
