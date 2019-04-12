#include <iostream>

using namespace std;

#ifndef TICKET_H
#define TICKET_H

class Ticket{
	
	public:
		Ticket();
		void setTickID(string tickid);
		void setOwnID(string ownid);
		void setTechName1(string techname);
		void setTechName2(string techname);
		void setWorkHours1(double workhours);
		void setWorkHours2(double workhours);
		void setExpertise1(int expertise);
		void setExpertise2(int expertise);
		void setParts(string parts);
		void setPartCost(double partcost);
		void setIssue(string issue);
		void setStatus(string status);
		void setInstallDate(string installdate);
		void setFinishDate(string finishdate);
		
		string getTickID();
		string getOwnID();
		string getTechName1();
		string getTechName2();
		double getWorkHours1();
		double getWorkHours2();
		int getExpertise1();
		int getExpertise2();
		string getParts();
		double getPartCost();
		string getIssue();
		string getStatus();
		string getInstallDate();
		string getFinishDate();
		
	private:
		string tickid;
		string ownid;
		string techname1;
		string techname2;
		double workhours1;
		double workhours2;
		int expertise1;
		int expertise2;
		string parts;
		double partcost;
		string issue;
		string status;
		string installdate;
		string finishdate;
		
		
		
};

#endif
