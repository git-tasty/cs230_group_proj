#include <iostream>
#include "TicketNode.h"

using namespace std;

void TicketList::AddTicket(string userid){
	ticketPTR t = new ticket;
	t -> next = NULL;
	Ticket newtick;
	
	string iss;
	string issue;
	cout<<"What is your issue? ";
	cin>>iss;
	getline(cin, issue);
	issue = iss + issue;
	newtick.setIssue(issue);
	newtick.setOwnID(userid); 
	cout<<issue;
	
	t -> tick = newtick;
	
	if(head != NULL){
		curr = head;
		while(curr -> next != NULL){
			curr = curr ->next;
		}
		curr -> next = t;
	}
	else{
		head = t;
	}
}

void TicketList::PrintTickets(){
	if(head != NULL){
		double total;
		curr = head;
		cout<<"List of all Tickets in the System:"<<endl;
		cout<<"=================================="<<endl;
		while(curr != NULL){
			total = 0;
			cout<<"Owner ID: "<<curr -> tick.getOwnID()<<endl;
			cout<<"Technician 1: "<<curr -> tick.getTechName1()<<endl;
			cout<<"Technician 1's Hours: "<<curr -> tick.getWorkHours1()<<endl;
			cout<<"Technician 2: "<<curr -> tick.getTechName2()<<endl;
			cout<<"Technician 2's Hours: "<<curr -> tick.getWorkHours2()<<endl;
			if(curr -> tick.getExpertise1() == 1){
				total = total + curr -> tick.getWorkHours1() * 100;
			}else if(curr -> tick.getExpertise1() == 2){
				total = total + curr -> tick.getWorkHours1() * 175;
			}else if(curr -> tick.getExpertise1() == 3){
				total = total + curr -> tick.getWorkHours1() * 250;
			}
			if(curr -> tick.getExpertise2() == 1){
				total = total + curr -> tick.getWorkHours2() * 100;
			}else if(curr -> tick.getExpertise2() == 2){
				total = total + curr -> tick.getWorkHours2() * 175;
			}else if(curr -> tick.getExpertise2() == 3){
				total = total + curr -> tick.getWorkHours2() * 250;
			}
			cout<<"Total Labor Costs: $"<<total<<endl;
			cout<<"Parts Required/Ordered: "<<curr -> tick.getParts()<<endl;
			cout<<"Parts Cost: "<<curr -> tick.getPartCost()<<endl;
			cout<<"Stated Issue: "<<curr -> tick.getIssue()<<endl;
			cout<<"Parts installed on: "<<curr -> tick.getInstallDate()<<endl;
			cout<<"Current Status: "<<curr -> tick.getStatus()<<endl;
			cout<<"Finish Date: "<<curr -> tick.getFinishDate()<<endl;
			total = total + curr-> tick.getPartCost();
			cout<<"Total Cost: $"<<total<<endl;
			cout<<"==========================================="<<endl;
			
			curr = curr->next;
		}
	}else{
		cout<<"There are no Tickets to display."<<endl;
	}
}

void TicketList::MyTickets(string userid){
	double total;
	curr = head;
	while(curr != NULL){
		if(curr -> tick.getOwnID() == userid){
			total = 0;
			cout<<"Owner ID: "<<curr -> tick.getOwnID()<<endl;
			cout<<"Technician 1: "<<curr -> tick.getTechName1()<<endl;
			cout<<"Technician 1's Hours: "<<curr -> tick.getWorkHours1()<<endl;
			cout<<"Technician 2: "<<curr -> tick.getTechName2()<<endl;
			cout<<"Technician 2's Hours: "<<curr -> tick.getWorkHours2()<<endl;
			if(curr -> tick.getExpertise1() == 1){
				total = total + curr -> tick.getWorkHours1() * 100;
			}else if(curr -> tick.getExpertise1() == 2){
				total = total + curr -> tick.getWorkHours1() * 175;
			}else if(curr -> tick.getExpertise1() == 3){
				total = total + curr -> tick.getWorkHours1() * 250;
			}
			if(curr -> tick.getExpertise2() == 1){
				total = total + curr -> tick.getWorkHours2() * 100;
			}else if(curr -> tick.getExpertise2() == 2){
				total = total + curr -> tick.getWorkHours2() * 175;
			}else if(curr -> tick.getExpertise2() == 3){
				total = total + curr -> tick.getWorkHours2() * 250;
			}
			cout<<"Total Labor Costs: $"<<total<<endl;
			cout<<"Parts Required/Ordered: "<<curr -> tick.getParts()<<endl;
			cout<<"Parts Cost: "<<curr -> tick.getPartCost()<<endl;
			cout<<"Stated Issue: "<<curr -> tick.getIssue()<<endl;
			cout<<"Parts installed on: "<<curr -> tick.getInstallDate()<<endl;
			cout<<"Current Status: "<<curr -> tick.getStatus()<<endl;
			cout<<"Finish Date: "<<curr -> tick.getFinishDate()<<endl;
			total = total + curr-> tick.getPartCost();
			cout<<"Total Cost: $"<<total<<endl;
			cout<<"==========================================="<<endl;
		}
		curr = curr -> next;
	}	
} 

void TicketList::CheckStatus(string userid, string ticketid){
	curr = head;
	while(curr != NULL){
		if(curr -> tick.getOwnID() == userid){
			if(curr -> tick.getTickID() == ticketid){
				cout<<"Current Status: "<<curr -> tick.getStatus()<<endl;
			}
		}
	}
}
