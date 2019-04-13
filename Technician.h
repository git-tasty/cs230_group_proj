#include <iostream>
#include "User.h"

using namespace std;

#ifndef TECHNICIAN_H
#define TECHNICIAN_H

class Technician: public User{
	
	public:
		Technician();
		void setExpertise(int expert);
		int getExpertise();
	private:
		int expertise;
	
};
#endif
