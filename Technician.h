#include <iostream>
#include "User.h"

#ifndef TECHNICIAN_H
#define TECHNICIAN_H

class Technician: public User{
    
public:
    Technician();
    Technician(struct current_login Authenticated_User);
    void Set_ExpertiseLevel(int User_ExpertiseLevel);
    void Set_WorkHours(double User_WorkHours);
    int Get_ExpertiseLevel();
    double Get_WorkHours();
private:
    int ExpertiseLevel;
    double WorkHours;
};
#endif
