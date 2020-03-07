#include "cross.h"

cross::cross(string name, bool containsWarpSpace):shapeTwoD(name, containsWarpSpace){

}

double cross::getArea(){
	return area;
}

bool cross::findCoord(int x, int y){
	for(unsigned int i = 0; i < cC.size(); i++){
		if((cC[i].x == x) && (cC[i].y == y)){
			return true;
		}
	}
	return false;
}

coord cross::findCoordX(int x){
	for(unsigned int i = 0; i < cC.size();i++){
		if(cC[i].x == x){
			return cC[i];
		}
	}
	return coord();
}

coord cross::findCoordY(int y){
	for(unsigned int i = 0; i < cC.size();i++){
		if(cC[i].y == y){
			return cC[i];
		}
	}
	return coord();
}

void cross::setCoord(coord c){
	cC.push_back(c);
}

void cross::setMinMax(){
	minX = cC[0].x;
	minY = cC[0].y;
	maxX = cC[0].x;
	maxY = cC[0].y;
	for(int i = 1; i < 12;i++){
		if(cC[i].x <= minX){
			minX = cC[i].x;
		}
		else if(cC[i].x >= maxX){
			maxX = cC[i].x;
		}
		if(cC[i].y <= minY){
			minY = cC[i].y;
		}
		else if(cC[i].y >= maxY){
			maxY = cC[i].y;
		}
	}
	topL = findCoordY(maxY);
	topR = findCoordY(maxY);
	Ltop = findCoordX(minX);
	Lbot = findCoordX(minX);
	botL = findCoordY(minY);
	botR = findCoordY(minY);
	Rbot = findCoordX(maxX);
	Rtop = findCoordX(maxX);
	for(int i = 0; i < 12; i++){
		if((cC[i].y == maxY) && (findCoord(cC[i].x, cC[i].y) == true) && (cC[i].x < topL.x))
			topL = cC[i];
		else if((cC[i].y == maxY) && (findCoord(cC[i].x, cC[i].y) == true) && (cC[i].x > topR.x))
			topR = cC[i];
		else if((cC[i].y == minY) && (findCoord(cC[i].x, cC[i].y) == true) && (cC[i].x < botL.x))
			botL = cC[i];
		else if((cC[i].y == minY) && (findCoord(cC[i].x, cC[i].y) == true) && (cC[i].x > botR.x))
			botL = cC[i];
		else if((cC[i].x == minX) && (findCoord(cC[i].x, cC[i].y) == true) && (cC[i].y > Ltop.y))
			Ltop = cC[i];
		else if((cC[i].x == minX) && (findCoord(cC[i].x, cC[i].y) == true) && (cC[i].y < Lbot.y))
			Lbot = cC[i];
		else if((cC[i].x == maxX) && (findCoord(cC[i].x, cC[i].y) == true) && (cC[i].y > Rtop.y))
			Rtop = cC[i];	
		else if((cC[i].x == maxX) && (findCoord(cC[i].x, cC[i].y) == true) && (cC[i].y < Rbot.y))
			Rbot = cC[i];
	}
}

double cross::computeArea(){
	double rec1;
	double rec2;
	double rec3;
	double rec4;
	double rec5;
	double length;
	double width;
	
	length = maxY - minY;
	width = maxX - minX;
	rec1 = length * width;
	
	length = topL.y - Ltop.y;
	width = topL.x - Ltop.x;
	rec2 = length * width;
	
	length = topR.y - Rtop.y;
	width = Rtop.x - topR.x;
	rec3 = length * width;
	
	length = Rbot.y - botR.y;
	width = Rbot.x - botR.x;
	rec4 = length * width;
	
	length = Lbot.y - botL.y;
	width = botL.x - Lbot.x;
	rec5 = length * width;
	
	area = rec1 - rec2 - rec3 - rec4 - rec5;
	
	return area;
}

bool cross::isPointInShape(int x, int y){
	bool check;
	if((Ltop.x < x && x < Rtop.x) && (Lbot.y < y && y < Ltop.y))
			check = true;
	else if((botL.y < y && y < topL.y) && (topL.x < x && x < topR.x))
			check = true;
	else
		check = false;
	return check;
}

bool cross::isPointOnShape(int x, int y){
	bool check = false;
	int j;
	for(int i = 0; i < 12; i++){
		j = i + 1;
		if(i == 11)
			j = 0;
		if(cC[i].x == x){
			if(cC[i].y > y && y > cC[j].y)
				check = true;
			else if(cC[i].y < y && y < cC[j].y)
				check = true;
		}
		if(cC[i].y == y){
			if(cC[i].x > x && x > cC[j].x)
				check = true;
			else if(cC[i].x < x && x < cC[j].x)
				check = true;
		}
	}
	return check;
}

void cross::setShapeNum(int num){
	shapeNum = num;
}

int cross::getShapeNum(){
	return shapeNum;
}

string cross::toString(){
	string cross;
	cross = "Shape["+ to_string(getShapeNum()) + "]\n";
	cross += shapeTwoD::toString();

	cross += "Area: " + to_string((int)area) + " units square\nVertices:\n";
	
	for(unsigned int i = 0; i < cC.size(); i++){
		cross += "Points [" + to_string(i) + "] : (" + to_string(cC[i].x) + ", " + to_string(cC[i].y) + ")\n";
	}
	cross += "\n";
	cross += "Point on perimeter: ";
	for(int i = minX; i <= maxX; i++){
		for(int j = minY; j <= maxY; j++){
			if(isPointOnShape(i, j) == true && findCoord(i, j) == false)
				cross += "(" + to_string(i) + ", " + to_string(j) + "), ";
		}
	}
	
	if(((topL.x - Ltop.x) == 1) && ((topR.x - topL.x) == 1) && ((Rtop.x - topR.x) == 1) && ((topL.y - Ltop.y) == 1) && ((Ltop.y - Lbot.y) == 1) && ((Lbot.y - botL.y) == 1))
		cross += "none!";
	cross += "\n";
	cross += "\n";
	cross += "Point within shape: ";
	//left to right
	for(int i = minX; i <= maxX; i++){
		for(int j = minY; j <= maxY; j++){
			if(isPointInShape(i, j) == true)
				cross += "(" + to_string(i) + ", " + to_string(j) + "), ";
		}
	}
	
	if(((topL.x - Ltop.x) == 1) && ((topR.x - topL.x) == 1) && ((Rtop.x - topR.x) == 1) && ((topL.y - Ltop.y) == 1) && ((Ltop.y - Lbot.y) == 1) && ((Lbot.y - botL.y) == 1))
		cross += "none!";
	
	cross += "\n";
	return cross;
}
