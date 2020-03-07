#include "square.h"

square::square(string name, bool containsWarpSpace) : shapeTwoD(name, containsWarpSpace){

}

double square::computeArea(){
	length = maxX - minX;
	breath = maxY - minY;
	area = length * breath;
	return area;
}

bool square::isPointInShape(int x, int y){
	if((minX < x) && (x < maxX) && (minY < y) && (y < maxY)){
		return true;
	}
	else{
		return false;
	}
}	

bool square::isPointOnShape(int x, int y){
	if(((minX <= x) && (x <= maxX)) && ((minY == y) || (maxY == y))){
		return true;
	}
	else if(((minX == x) || (x == maxX)) && ((minY <= y) && (y <= maxY))){
		return true;
	}
	else
		return false;
}

double square::getArea(){
	return area;
}

void square::setCoord(coord b){
	cS.push_back(b);
}

void square::setMinMax(){
	minX = cS[0].x;
	minY = cS[0].y;
	maxX = cS[0].x;
	maxY = cS[0].y;
	for(int i = 1; i < 4; i++){
		if(cS[i].x <= minX)
			minX = cS[i].x;
		else if(cS[i].x >= maxX){
			maxX = cS[i].x;
		}
		
		if(cS[i].y <= minY)
			minY = cS[i].y;
		else if(cS[i].y >= maxY){
			maxY = cS[i].y;
		}
	}
}

bool square::findCoord(int x, int y){
	for(unsigned int i=0;i<cS.size();i++){
		if((cS[i].x == x) && (cS[i].y == y)){
			return true;
		}
	}
	return false;
}

void square::setShapeNum(int num){
	shapeNum = num;
}

int square::getShapeNum(){
	return shapeNum;
}

string square::toString(){
	string shape;
	shape = "Shape[" + to_string(getShapeNum()) + "]\n";
	shape += shapeTwoD::toString();
	
	shape += "Area: " + to_string((int)area) + " units square\nVertices:\n";
	
	//vertices of the marked points
	for(unsigned int i = 0; i < cS.size(); i++){
		shape += "Point [" + to_string(i) + "] : (" + to_string(cS[i].x) + ", " + to_string(cS[i].y) + ")\n";
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
