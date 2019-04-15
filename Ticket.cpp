#include "Ticket.h"
#include <iostream>

using namespace std;
//defaut constructor
Ticket::Ticket(){
    Set_TickID(0);
    Set_Owner(Customer());
    Set_Worker1(Technician());
    Set_Worker2(Technician());
    Set_PartList("");
    Set_PartCost(0);
    Set_TicketTitle("");
    Set_TicketDescription("");
    Set_TicketStatus("Pending");
    Set_InstallDate("");
    Set_FinishDate("");
}
//mutator definitions
void Ticket::Set_TickID(int New_TicketID){
    Ticket_ID = New_TicketID;
}
void Ticket::Set_Owner(Customer Authenticated_Customer){
    Owner = Authenticated_Customer;
}
void Ticket::Set_Worker1(Technician Authenticated_Technician){
    Worker1 = Authenticated_Technician;
}
void Ticket::Set_Worker2(Technician Authenticated_Technician){
    Worker2 = Authenticated_Technician;
}
void Ticket::Set_WorkerHours(Technician Authenticated_Technician,double New_Hour){
    if(Authenticated_Technician.Get_FirstName()==Worker1.Get_FirstName()){//Tech 1 is currently editing ticket
        Worker1.Set_WorkHours(New_Hour);
    }else if(Authenticated_Technician.Get_FirstName()==Worker2.Get_FirstName()){//tech 2 is currewntly editing ticket
        Worker2.Set_WorkHours(New_Hour);
    }
    //For some reason not authed to ticket
    std::cout<<"Error: You Are not Autheroised to Work on this Ticket"<<endl;
}
void Ticket::Set_PartList(std::string New_Parts){
    Ticket_PartsUsed = New_Parts;
}
void Ticket::Set_PartCost(double New_PartCost){
    Ticket_Partcost = New_PartCost;
}
void Ticket::Set_TicketTitle(std::string New_Title){
    Ticket_Title = New_Title;
}
void Ticket::Set_TicketDescription(std::string New_Issue){
    Ticket_Description = New_Issue;
}
void Ticket::Set_TicketStatus(std::string New_Status){
    Ticket_Status = New_Status;
}
void Ticket::Set_InstallDate(std::string NewInstallDate){
    Part_InstallDate = NewInstallDate;
}
void Ticket::Set_FinishDate(std::string NewFinishDate){
    Ticket_FinishDate = NewFinishDate;
}
//accessor definitions
int Ticket::Get_TicketID(){
    return Ticket_ID;
}
Customer Ticket::Get_Owner(){
    return Owner;
}
Technician Ticket::Get_Technician1(){
    return Worker1;
}
Technician Ticket::Get_Technician2(){
    return Worker2;
}
double Ticket::Get_WorkerHours(Technician Authenticated_Technician){
    if(Authenticated_Technician.Get_UserID()==Worker1.Get_UserID()){//Tech 1 is currently editing ticket
        return Worker1.Get_WorkHours();
    }else if(Authenticated_Technician.Get_UserID()==Worker2.Get_UserID()){//tech 2 is currewntly editing ticket
        return Worker2.Get_WorkHours();
    }
    //For some reason not authed to ticket
    std::cout<<"Error: You Are not Autheroised to Work on this Ticket"<<endl;
    return 0;
}
double Ticket::Get_PartCost(){
    return Ticket_Partcost;
}
std::string Ticket::Get_PartList(){
    return Ticket_PartsUsed;
}
std::string Ticket::Get_TicketTitle(){
    return Ticket_Title;
}
std::string Ticket::Get_TicketDescription(){
    return Ticket_Description;
}
std::string Ticket::Get_TicketStatus(){
    return Ticket_Status;
}
string Ticket::Get_PartInstallDate(){
    return Part_InstallDate;
}
string Ticket::Get_TicketFinishDate(){
    return Ticket_FinishDate;
}
void Ticket::Set_TicketInfomration(struct TempTicket Ticket_In){
    Ticket_ID = Ticket_In.Ticket_ID;
    Owner = Ticket_In.Owner;
    Worker1 = Ticket_In.Worker1;
    Worker2 = Ticket_In.Worker2;
    Ticket_PartsUsed = Ticket_In.Ticket_PartsUsed;
    Ticket_Partcost = Ticket_In.Ticket_Partcost;
    Ticket_Title = Ticket_In.Ticket_Title;
    Ticket_Description = Ticket_In.Ticket_Description;
    Ticket_Status = Ticket_In.Ticket_Status;
    Part_InstallDate = Ticket_In.Part_InstallDate;
    Ticket_FinishDate = Ticket_In.Ticket_FinishDate;
}
