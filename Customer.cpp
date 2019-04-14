#include "Customer.h"
#include <iostream>

Customer::Customer(){
	Set_UserInfo("","","","","");
	Set_UserType(1);
}
Customer::Customer(struct current_login Authenticated_User){
   Set_UserInfo(Authenticated_User);
}
