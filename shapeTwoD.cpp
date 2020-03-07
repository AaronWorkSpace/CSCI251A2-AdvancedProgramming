#include "shapeTwoD.h"

shapeTwoD::shapeTwoD(string name, bool containsWarpSpace){
	this->name = name;
	this-> containsWarpSpace = containsWarpSpace;
}

string shapeTwoD::getName(){
	return name;
}

bool shapeTwoD::getContainsWarpSpace(){
	return containsWarpSpace;
}

void shapeTwoD::setName(string name){
	this->name = name;
}

void shapeTwoD::setContainsWarpSpace(bool containsWarpSpace){
	this->containsWarpSpace = containsWarpSpace;
}

string shapeTwoD::toString(){
	string wsOrNs;
	if(containsWarpSpace == true){
		wsOrNs = "WS";
	}
	else{
		wsOrNs = "NS";
	}
	
	string s = "Name: " + name + "\nSpecial Type: " + wsOrNs + "\n";
	
	return s;
}
