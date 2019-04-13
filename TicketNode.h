#include <iostream>
#include "Ticket.h"

using namespace std;

#ifndef TICKETNODE_H
#define TICKETNODE_H

class TicketList{
	
	public:
		TicketList(){
			head = NULL;
			curr = NULL;
		}		
		void AddTicket(string userid);
		void PrintTickets();
		void MyTickets(string userid);
		void CheckStatus(string user, string ticID);
		void PrintInvoice(string user, string ticID);
		void ClaimTicket(string ticckid, string techname);
		void UpdateStatus(string tickid, string status);
		void UpdateTicket(string tickid);
		
	private:
		typedef struct ticket{
			Ticket tick;
			ticket* next = NULL;
		}* ticketPTR;
		
		ticketPTR head = NULL;
		ticketPTR curr = NULL;
	
};

#endif
