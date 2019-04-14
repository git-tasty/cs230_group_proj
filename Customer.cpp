#include "Customer.h"
#include <iostream>

using namespace std;

Customer::Customer(){
	setInfo("","","");
	setType(1);
}
Customer::Customer(struct current_login Authenticated_User){
    setInfo(Authenticated_User.Username,"","");
    setType(1);
}
