#include "User.h"
#include <iostream>

using namespace std;
//constructor
User::User(){
	setInfo("", "", "");
}
//mutators
void User::setID(string id){
	ID = id;
} 

void User::setName(string name) {
	name = name;
}

void User::setType(int type){
	type = type;
} 

void User::setPassword(string password){
	password = password;
}

void User::setInfo(string name, string id, string pass){
	name = name;
	password = pass;
	ID = id;
} 
//accessors
string User::getID(){
	return ID;
}

string User::getName(){
	return name;
}

string User::getPassword(){
	return password;
}

int User::getType(){
	return type;
}
