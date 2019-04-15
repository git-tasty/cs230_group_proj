#include "Technician.h"
#include <iostream>

Technician::Technician(){
    Set_UserInfo("","","","","");
    Set_UserType(2);
    Set_ExpertiseLevel(0);
    Set_WorkHours(0);
}
Technician::Technician(struct current_login Authenticated_User){
    Set_UserInfo(Authenticated_User);
    Set_ExpertiseLevel(Authenticated_User.expertise);
    Set_WorkHours(0);
}
void Technician::Set_ExpertiseLevel(int User_ExpertiseLevel){
    ExpertiseLevel = User_ExpertiseLevel;
}
int Technician::Get_ExpertiseLevel(){
    return ExpertiseLevel;
}
void Technician::Set_WorkHours(double User_WorkHours){
    WorkHours = User_WorkHours;
}
double Technician::Get_WorkHours(){
    return WorkHours;
}
