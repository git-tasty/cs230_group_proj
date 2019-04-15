#include <iostream>
#include "Customer.h"
#include "Technician.h"

#ifndef TICKET_H
#define TICKET_H

class Ticket{
    
public:
    Ticket();
    void Set_TickID(int New_TicketID);
    void Set_Owner(Customer Authenticated_Customer);
    void Set_Worker1(Technician Authenticated_Technician);
    void Set_Worker2(Technician Authenticated_Technician);
    void Set_WorkerHours(Technician Authenticated_Technician,double New_Hour);
    void Set_PartList(std::string New_Parts);
    void Set_PartCost(double New_PartCost);
    void Set_TicketTitle(std::string New_Title);
    void Set_TicketDescription(std::string New_Issue);
    void Set_TicketStatus(std::string New_Status);
    void Set_InstallDate(std::string NewInstallDate);
    void Set_FinishDate(std::string NewFinishDate);
    void Set_TicketInfomration(struct TempTicket Ticket_In);
    
    int Get_TicketID();
    Customer Get_Owner();
    Technician Get_Technician1();
    Technician Get_Technician2();
    double Get_WorkerHours(Technician Authenticated_Technician);
    std::string Get_PartList();
    double Get_PartCost();
    std::string Get_TicketTitle();
    std::string Get_TicketDescription();
    std::string Get_TicketStatus();
    std::string Get_PartInstallDate();
    std::string Get_TicketFinishDate();
private:
    int Ticket_ID;
    Customer Owner;
    Technician Worker1;
    Technician Worker2;
    std::string Ticket_PartsUsed;
    double Ticket_Partcost;
    std::string Ticket_Title;
    std::string Ticket_Description;
    std::string Ticket_Status;
    std::string Part_InstallDate;
    std::string Ticket_FinishDate;
};
struct TempTicket{
    int Ticket_ID;
    Customer Owner;
    Technician Worker1;
    Technician Worker2;
    std::string Ticket_PartsUsed;
    double Ticket_Partcost;
    std::string Ticket_Title;
    std::string Ticket_Description;
    std::string Ticket_Status;
    std::string Part_InstallDate;
    std::string Ticket_FinishDate;
};

#endif
