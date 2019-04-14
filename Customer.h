#include <iostream>

#include "User.h"
#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer: public User{
	
	public:
		Customer();
        Customer(struct current_login Authenticated_User);
		
	private:

};

#endif
