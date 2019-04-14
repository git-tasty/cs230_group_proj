#include "User.h"
#include <iostream>

//constructor definition
User::User(){
    Set_UserInfo("","","","",0,"");//set to all default
}
User::User(std::string User_FirstName_in,std::string User_LastName_in,std::string User_Username_in, std::string User_Password_in,int User_UserType_in, std::string User_ID_in){
    Username = User_Username_in;
    UserID=User_ID_in;
    Password=User_Password_in;
    UserType = User_UserType_in;
    FirstName = User_FirstName_in;
    LastName=User_LastName_in;
}
User::User(struct current_login Authenticated_User){
    Username = Authenticated_User.Username;
    UserID=Authenticated_User.id;
    Password=Authenticated_User.Password;
    UserType = Authenticated_User.User_AuthLevel;
    FirstName = Authenticated_User.first_name;
    LastName=Authenticated_User.Last_name;
}
//defining mutators for user class
void User::Set_Username(std::string User_Username_in){
    Username = User_Username_in;
}
void User::Set_UserID(std::string User_ID_in){
    UserID=User_ID_in;
}
void User::Set_Password(std::string User_Password_in){
    Password=User_Password_in;
}
void User::Set_UserType(int User_UserType_in){
    UserType = User_UserType_in;
}
void User::Set_FirstName(std::string User_FirstName_in){
    FirstName = User_FirstName_in;
}
void User::Set_LastName(std::string User_LastName_in){
    LastName=User_LastName_in;
}
void User::Set_UserInfo(std::string User_FirstName_in,std::string User_LastName_in,std::string User_Username_in, std::string User_Password_in,int User_UserType_in, std::string User_ID_in){
    Username = User_Username_in;
    UserID=User_ID_in;
    Password=User_Password_in;
    UserType = User_UserType_in;
    FirstName = User_FirstName_in;
    LastName=User_LastName_in;
}
void User::Set_UserInfo(struct current_login Authenticated_User){
    Username = Authenticated_User.Username;
    UserID=Authenticated_User.id;
    Password=Authenticated_User.Password;
    UserType = Authenticated_User.User_AuthLevel;
    FirstName = Authenticated_User.first_name;
    LastName=Authenticated_User.Last_name;
}
std::string User::Get_Username(){
    return Username;
}
std::string User::Get_FirstName(){
    return FirstName;
}
std::string User::Get_LastName(){
    return LastName;
}
std::string User::Get_UserID(){
    return UserID;
}
std::string User::Get_Password(){
    return Password;
}
int User::Get_UserType(){
    return UserType;
}
