#include <iostream>
#include "Ticket.h"


#ifndef TICKETNODE_H
#define TICKETNODE_H

class TicketList{
    
public:
    TicketList(){
        head = NULL;
        curr = NULL;
    }
    int Get_NextUserID();
    int CloseTicket();
    void Set_NewTicket(Customer Authenticated_Customer);
    void Get_AllTickets();
    void Get_AllTickets(Customer Authenticated_Customer);
    void Get_TicketStatus(Customer Authenticated_Customer,int Ticket_ID);
    void Get_Invoice(Customer Authenticated_Customer, int Ticket_ID);
    void ClaimCustomerTicket(int Ticket_ID, Technician Authenticated_Technician);
    void ClaimCustomerTicket(int Ticket_ID, std::string Technician_ID);
    void UpdateStatus(int Ticket_ID, std::string Ticket_Status);
    void UpdateTicket(int Ticket_ID);
    void Save_AllTickets();
    void Load_AllTickets();
private:
    typedef struct ticket{
        Ticket tick;
        ticket* next = NULL;
    }* ticketPTR;
    ticketPTR head = NULL;
    ticketPTR curr = NULL;
};

#endif
