#include "functions.h"

const int MAX = 100;
const int PI = 3.14159265359;
const int CROSS = 12;
const int RECSQUARE = 4;

vector<shapeTwoD*>sTD;

string toLowerCase(string name){
	char *cstr = new char[name.length() + 1];
	strcpy(cstr, name.c_str());
	
	for(int i = 0; i < name.length();i++){
		cstr[i] = tolower(cstr[i]);
	}
	
	string s;
	
	for(int i = 0; i <name.length(); i++){
		s += cstr[i];
	}
	
	delete [] cstr;
	return s;
}

void printMenu(){
	bool ok = true;
	string str = "";
	do{
		cout << "Student ID  : 5985171" << endl;
		cout << "Student Name: Aaron Lim Cong Kai" << endl;
		cout << "--------------------------------" << endl;
		cout << "Welcome to Assn2 program!" << endl;
		cout << endl;
		cout << "1)	Input sensor data" << endl;
		cout << "2)	Compute area(for all records)" << endl;
		cout << "3)	Print shapes report" << endl;
		cout << "4)	Sort shapes data" << endl;
		cout << "5)	Print individual shape" << endl;
		cout << "6)	Quit" << endl;
		cout << endl;
		cout << "Please enter your choice: ";
		cin >> str;
		
		if(str=="1"){
			cout << endl;
			option1();
			cout << endl;
		}
		else if(str == "2"){
			cout << endl;
			option2();
			cout << endl;
		}
		else if(str == "3"){
			cout << endl;
			option3();
		}
		else if(str == "4"){
			cout << endl;
			option4();
		}
		else if(str == "5"){
			cout << endl;
			option5();
		}
		else if(str == "6"){
			ok = false;
			cout << endl;
			cout << "Thank you for using this program" << endl;
			cout << endl;
		}
		else{
			cout << endl;
			cout << "You have enter a wrong value, please enter 1/2/3/4/5/6." << endl;
			cout << endl;
		}
	}while(ok == true);
}

void option1(){
	string name;
	string type;
	int tempX;
	int tempY;
	int tempRadius;
	bool ok = true;
	int squareRectangleXY = 4;
	float circleRadius = 0;
	bool containsWarpSpace;
	int static counter = 0;
	cout << "[Input sensor data]" << endl;
	
	do{
		cout << "Please enter name of shape: ";
		cin >> name;
		name = toLowerCase(name);
		if(name == "cross" || name == "rectangle" || name == "square" 
		   || name == "circle")
		   	ok = false;
		else
			cout << "Please enter cross / rectangle / square / circle" << endl;
			
	}while(ok == true);
	
	ok = true;
	do{
		cout << "Please enter special type: ";
		cin >> type;
		type = toLowerCase(type);
		if(type == "ws" || type == "ns")
			ok = false;
		else
			cout << "Please enter WS, (Warp-space) or NS, (Normal-space)" << endl;
	}while(ok == true);
	
	if(type == "ws")
		containsWarpSpace = true;
	else
		containsWarpSpace = false;
	
	if(name == "cross"){
		sTD.push_back(new cross(name, containsWarpSpace));
		int x[CROSS];
		int y[CROSS];
		int xy = 0;
		for(int i = 0; i < CROSS; i++){
			coord c;
			ok = true;
			bool okay;
			do{
				cout << "Please enter x-oridinate of pt." << i+1 << ": ";
				cin >> tempX;
				cout << "Please enter y-oridinate of pt." << i+1 << ": ";
				cin >> tempY;
				okay = true;
				for(int j = 0; j < CROSS; j++){
					if(tempX == x[j] && tempY == y[j]){
						cout << "You have entered identical x-oridinate and y-ordinate, please enter again" << endl;
						okay = false;
					}
				}
				if(okay == true){
					x[xy] = tempX;
					y[xy] = tempY;
					c.x = tempX;
					c.y = tempY;
					xy += 1;
					sTD[(sTD.size() - 1)]->setCoord(c);
					ok = false;
				}
				else if(okay == false){
					ok = true;
				}
			}while(ok == true);
		} 
		
		sTD[(sTD.size() - 1)]-> setMinMax();
		sTD[(sTD.size() - 1)] -> setShapeNum(counter);
		counter += 1;
		//Haven't check if proper shape is made
		cout << endl;
		cout << "Record successfully stored, Going back to main menu ..." << endl;
	}
	
	else if(name == "rectangle"){
		sTD.push_back(new rectangle(name, containsWarpSpace));
		int x[RECSQUARE];
		int y[RECSQUARE];
		int xy = 0;
		for(int i = 0; i < RECSQUARE; i++){
			coord c;
			ok = true;
			bool okay;
			do{
				cout << "Please enter x-oridinate of pt." << i+1 << ": ";
				cin >> tempX;
				cout << "Please enter y-oridinate of pt." << i+1 << ": ";
				cin >> tempY;
				okay = true;
				for(int j = 0; j < RECSQUARE; j++){
					if(tempX == x[j] && tempY == y[j]){
						cout << "You have entered identical x-oridinate and y-ordinate, please enter again" << endl;
						okay = false;
					}
				}
				if(okay == true){
					x[xy] = tempX;
					y[xy] = tempY;
					c.x = tempX;
					c.y = tempY;
					xy += 1;
					sTD[(sTD.size() - 1)]->setCoord(c);
					ok = false;
				}
				else if(okay == false){
					ok = true;
				}
			}while(ok == true);
		} 
		
		sTD[(sTD.size() - 1)]-> setMinMax();
		sTD[(sTD.size() - 1)] -> setShapeNum(counter);
		counter += 1;
		//Haven't check if proper shape is made
		cout << endl;
		cout << "Record successfully stored, Going back to main menu ..." << endl;
	}
	
	else if(name == "square"){
		sTD.push_back(new square(name, containsWarpSpace));
		int x[RECSQUARE];
		int y[RECSQUARE];
		int xy = 0;
		for(int i = 0; i < RECSQUARE; i++){
			coord c;
			ok = true;
			bool okay;
			do{
				cout << "Please enter x-oridinate of pt." << i+1 << ": ";
				cin >> tempX;
				cout << "Please enter y-oridinate of pt." << i+1 << ": ";
				cin >> tempY;
				okay = true;
				for(int j = 0; j < RECSQUARE; j++){
					if(tempX == x[j] && tempY == y[j]){
						cout << "You have entered identical x-oridinate and y-ordinate, please enter again" << endl;
						okay = false;
					}
				}
				if(okay == true){
					x[xy] = tempX;
					y[xy] = tempY;
					c.x = tempX;
					c.y = tempY;
					xy += 1;
					sTD[(sTD.size() - 1)]->setCoord(c);
					ok = false;
				}
				else if(okay == false){
					ok = true;
				}
			}while(ok == true);
		} 
		
		sTD[(sTD.size() - 1)]-> setMinMax();
		sTD[(sTD.size() - 1)] -> setShapeNum(counter);
		counter += 1;
		//Haven't check if proper shape is made
		cout << endl;
		cout << "Record successfully stored, Going back to main menu ..." << endl;
	}
	
	else if(name == "circle"){
		sTD.push_back(new circle(name, containsWarpSpace));
		coord c;
		
		cout << "Please enter x-oridinate of center: ";
		cin >> c.x;
		cout << "Please enter y-oridinate of center: ";
		cin >> c.y;
		
		sTD[(sTD.size() - 1)]->setCoord(c);
		
		int r;
		cout << "Please enter radius(units): ";
		cin >> r;
		
		sTD[(sTD.size() - 1)]->setRadius(r);
		sTD[(sTD.size() - 1)]-> setMinMax();
		sTD[(sTD.size() - 1)] -> setShapeNum(counter);
		counter += 1;
		//Haven't check if proper shape is made
		cout << endl;
		cout << "Record successfully stored, Going back to main menu ..." << endl;
	}
}

//computing area
void option2(){
	if(sTD.size() == 0)
		cout << "You have not input data" << endl;
	else{
		for(unsigned int i = 0; i < sTD.size(); i++){
			sTD[i] -> computeArea();
		}
		
		cout << "Computation completed (" << sTD.size() << " records were updated)" << endl;
	}
}

//printing
void option3(){
	if(sTD.size() == 0)
		cout << "You have not input data" << endl;
	else{
		cout << "Total no. of records available = " << sTD.size() << endl;
		cout << endl;
		for(unsigned int i = 0; i < sTD.size(); i++){
			cout << sTD[i] -> toString() << endl;
		}
	}
}

//sorting
bool compareAreaAsc(shapeTwoD *a, shapeTwoD *b){
	return b->getArea() > a->getArea();
}

bool compareAreaDesc(shapeTwoD *a, shapeTwoD *b){
	return b->getArea() < a->getArea();
}

bool compareWarpAreaDesc(shapeTwoD *a, shapeTwoD *b){
	if(a->getContainsWarpSpace() != b->getContainsWarpSpace()){
		return a-> getContainsWarpSpace() == true;
	}
	else
		return a->getArea() > b-> getArea();
}

void option4(){
	string abc;
	static int i = 0;
	if(sTD.size() == 0)
		cout << "You have not input data" << endl;
	else{
		do{
			cout << "\t a)\tSort by area (ascending)" << endl;
			cout << "\t b)\tSort by area (descending)" << endl;
			cout << "\t c)\tSort by special type and area" << endl;
			cout << "Please select sort option ('q' to go main menu) : ";
			cin >> abc;
		
			abc = toLowerCase(abc);
		
			if (abc == "a"){
				cout << "Sort by area (smallest to largest)" << endl;
				sort(sTD.begin(), sTD.end(), compareAreaAsc);
				abc = "q";
			}
			else if (abc == "b"){
				cout << "Sort by area (largest to smallest)" << endl;
				sort(sTD.begin(), sTD.end(), compareAreaDesc);
				abc = "q";
			}
			else if (abc == "c"){
				cout << "Sort by special type (WS then NS) and area (largest to smallest)" << endl;
				sort(sTD.begin(), sTD.end(), compareWarpAreaDesc);
				abc = "q";
			}
			else if (abc == "q"){
				
			}
			else{
				cout << "Please input the correct value (a,b,c,q)" << endl << endl; 
			}
		}while(abc != "q");
		
		cout << endl;
		for(unsigned int i = 0; i < sTD.size(); i++){
			cout << sTD[i]->toString() << endl;
		}
	}
}

void option5(){
	string shape;
	bool ok = true;
	bool exist = false;
	if(sTD.size() == 0)
		cout << "You have not input data" << endl;
	else{
		do{
		cout << "Please enter the shape you want to print: ";
		cin >> shape;
		shape = toLowerCase(shape);
		if(shape == "circle" || shape == "square" || shape == "rectangle" || shape == "cross")
			ok = false;
		else
			cout << "Please input circle / square / rectangle / cross" << endl;
		}while(ok == true);
		cout << endl;
		
		for(unsigned int i = 0; i < sTD.size(); i++){
			if(sTD[i]->getName() == shape){
				cout << sTD[i] -> toString() << endl;
				exist = true;
			}
		}
		if(exist == false)
			cout << "You have not key in data for it" << endl;
	}
}
