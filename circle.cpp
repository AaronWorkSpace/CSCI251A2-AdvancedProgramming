#include "circle.h"

circle::circle(string name, bool containsWarpSpace):shapeTwoD(name, containsWarpSpace){

}

double circle::getArea(){
	return area;
}

void circle::setMinMax(){
	minX = center.x - radius;
	maxX = center.x + radius;
	minY = center.y - radius;
	maxY = center.y + radius;
}

void circle::setCoord(coord c){
	center = c;
}

void circle::setRadius(int r){
	radius = r;
}

double circle::computeArea(){
	area = PI * pow(radius,2);
	return area;
}

bool circle::isPointInShape(int x, int y){
	if((pow((x - center.x), 2) + pow((y - center.y), 2)) < pow(radius,2)){
		if((x == center.x) && (y == center.y))
			return false;
		else
			return true;
	}
	return false;
}

bool circle::isPointOnShape(int x, int y){
	if((pow((x- center.x), 2) + pow((y - center.y),2)) == pow(radius, 2)){
		return true;
	}
	return false;
}

void circle::setShapeNum(int num){
	shapeNum = num;
}

int circle::getShapeNum(){
	return shapeNum;
}

string circle::toString(){
	string circleShape;
	circleShape = "Shape[" + to_string(getShapeNum()) + "]\n";
	circleShape += shapeTwoD::toString();
	
	circleShape += "Area: " + to_string((int)area) + " units square\nVertices:\n";
	circleShape += "Point: (" + to_string(center.x) + ", " + to_string(center.y) + ")\n";
	circleShape += "\n";
	circleShape += "Point on perimeter: ";
	for(int i = minX; i <= maxX;i++){
		for(int j = minY; j <= maxY; j++){
			if(isPointOnShape(i, j) == true)
				circleShape += "(" + to_string(i) + ", " + to_string(j) + "), ";
		}
	}
	circleShape += "\n";
	circleShape += "\n";
	circleShape += "Points within the shape: ";
	for(int i = minX; i <= maxX; i++){
		for (int j = minY; j <= maxY; j++){
			if(isPointInShape(i, j) == true){
				circleShape += "(" + to_string(i) + ", " + to_string(j)+ "), ";
			}
		}
	}
	if(radius == 1)
		circleShape += "none!";
	circleShape += "\n";
	
	return circleShape;
}
