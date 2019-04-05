#include <iostream>

using namespace std;

#ifndef USER_H
#define USER_H
class User{
	
	public:
		User();
		void setName(string name);
		void setID(string id);
		void setPassword(string pass);
		void setType(int type);
		void setInfo(string name, string ID, string password);	
		
		string getName();
		string getID();
		string getPassword();
		int getType();
	private:
		string name;
		string ID;
		string password;
		int type;
	
};
#endif
