#include "Technician.h"
#include <iostream>
#include <string>

using namespace std;

Technician::Technician(){
	setInfo("","","");
	setType(2);
	setExpertise(0);
}

void Technician::setExpertise(int expertise){
	expertise = expertise;
} 

int Technician::getExpertise(){
	return expertise;
}
