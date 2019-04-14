#include <iostream>
//base class that is inherited by customer and technician
#ifndef USER_H
#define USER_H
class User{
public:
    //default constructor
    User();
    User(std::string User_FirstName_in,std::string User_LastName_in,std::string User_Username_in, std::string User_Password_in,int User_UserType_in, std::string User_ID_in);
    User(struct current_login Authenticated_User);
    //mutator creation
    void Set_Username(std::string User_Username_in);
    void Set_UserID(std::string User_ID_in);
    void Set_Password(std::string User_Password_in);
    void Set_UserType(int User_UserType_in);
    void Set_FirstName(std::string User_FirstName_in);
    void Set_LastName(std::string User_LastName_in);
    void Set_UserInfo(std::string User_FirstName_in,std::string User_LastName_in,std::string User_Username_in, std::string User_Password_in,int User_UserType_in, std::string User_ID_in);
    void Set_UserInfo(struct current_login Authenticated_User);
    //accessor creation
    std::string Get_Username();
    std::string Get_FirstName();
    std::string Get_LastName();
    std::string Get_UserID();
    std::string Get_Password();
    int Get_UserType();
private:
    //private variables for user class
    std::string Username;
    std::string FirstName;
    std::string LastName;
    std::string UserID;
    std::string Password;
    int UserType;
    
};
//---------- Structures -------------|
struct current_login {
    std::string first_name;
    std::string Last_name;
    std::string Username;
    std::string Password;
    std::string id;
    int expertise;
    int User_AuthLevel;
};
#endif
