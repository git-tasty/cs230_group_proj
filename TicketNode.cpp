#include <iostream>
#include <fstream>
#include <sstream>
#include "TicketNode.h"

using namespace std;

/**
 --AddTicket--
 This method Takes in the userID of the customer creating the ticket
 It will ask the customer for information on the ticket and add the newly created ticket to the linked list
 */
void TicketList::AddTicket(string userid){
    ticketPTR t = new ticket;
    Ticket newtick;
    string iss;
    string issue;
    string tickid;
    t -> next = NULL;
    cout << string( 100, '\n' );
    cout<<"========= New Ticket ========="<<endl;
    cout<<"Please Decribe Your issue:"<<endl;
    cin>>iss;
    getline(cin, issue);
    issue = iss + issue;
    cout<<"Enter a ID to identify your ticket by: ";
    cin>>tickid;
    newtick.setTickID(tickid);
    newtick.setIssue(issue);
    newtick.setOwnID(userid);
    
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
    cout<<"=============================="<<endl;
    cout<<"Ticket Entered Correctly"<<endl<<"[Enter Any Key to Continue]...";
    cin>>iss;
    cout << string( 100, '\n' );
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
    std::cout<<userid;
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

void TicketList::PrintInvoice(string user, string ticID){
    curr = head;
    double total;
    while(curr != NULL){
        if(curr -> tick.getOwnID() == user){
            if(curr -> tick.getTickID() == ticID){
                if(curr -> tick.getStatus() == "Complete"){
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
                }else{
                    cout<<"No invoice is available for this ticket yet as it is not complete."<<endl;
                }
            }
        }
        curr = curr -> next;
    }
} 

void TicketList::ClaimTicket(string tickid, string techname){
    curr = head;
    while(curr != NULL){
        if(curr ->tick.getTickID() == tickid){
            if(curr -> tick.getTechName1() == ""){
                curr -> tick.setTechName1(techname);
            }else if(curr -> tick.getTechName1() != "" && curr -> tick.getTechName2() == ""){
                curr -> tick.setTechName2(techname);
            }else{
                cout<<"This TIcket Already has two technicians and can not be claimed."<<endl;
            }
        }
        curr = curr -> next;
    }
}

void TicketList::UpdateStatus(string tickid, string status){
    curr = head;
    while(curr != NULL){
        if(curr -> tick.getTickID() == tickid){
            curr -> tick.setStatus(status);
        }
        curr = curr -> next;
    }
}

void TicketList::UpdateTicket(string tickid){
    curr = head;
    while (curr != NULL){
        if(curr -> tick.getTickID() == tickid){
            int select = 0;
            while(select != 7){
                
                
                cout<<"        Ticket Update Menu      "<<endl;
                cout<<"1. Update Tech 1's Hours        "<<endl;
                cout<<"2. Update Tech 2's Hours        "<<endl;
                cout<<"3. Update Parts                 "<<endl;
                cout<<"4. Update Part Costs            "<<endl;
                cout<<"5. Update Part Installation Date"<<endl;
                cout<<"6. Update Finish Date           "<<endl;
                cout<<"7. Exit                         "<<endl;
                cout<<"Select an Option: ";
                cin>>select;
                
                double hours;
                double partcost;
                string part;
                string parts;
                string date;
                
                if(select == 1){
                    cout<<"How many hours did Tech 1 work: ";
                    cin>>hours;
                    curr -> tick.setWorkHours1(hours);
                }else if(select == 2){
                    cout<<"How many hours did Tech 2 work: ";
                    cin>>hours;
                    curr -> tick.setWorkHours2(hours);
                }else if(select == 3){
                    cout<<"What Parts were used: ";
                    cin>>part;
                    getline(cin, parts);
                    parts = part + parts;
                    curr -> tick.setParts(parts);
                }else if(select == 4){
                    cout<<"How much did the parts cost: ";
                    cin>>partcost;
                    curr -> tick.setPartCost(partcost);
                }else if(select == 5){
                    cout<<"The format for date is mm-dd-yyyy"<<endl;
                    cout<<"What day were the parts installed: ";
                    cin>>date;
                    curr -> tick.setInstallDate(date);
                }else if(select == 6){
                    cout<<"The format for date is mm-dd-yyyy"<<endl;
                    cout<<"What day was the ticket finished: ";
                    cin>>date;
                    curr -> tick.setFinishDate(date);
                }
            }
        }
        curr = curr -> next;
    }
} 
void TicketList::Save_AllTickets(){
    Ticket TempTicket;
    std::ofstream UserList_File;//IOstream to file
    std::string FileName = "Tickets.txt";
    UserList_File.open(FileName);//append Mode
     if(head != NULL){
         curr = head;
          while(curr != NULL){
              TempTicket = curr->tick;
              UserList_File<<TempTicket.getTickID()<<","<<TempTicket.getOwnID()<<","<<TempTicket.getTechName1()<<","<<TempTicket.getTechName2()<<","<<TempTicket.getWorkHours1()<<","<<TempTicket.getWorkHours2()<<","<<TempTicket.getExpertise1()<<","<<TempTicket.getExpertise2()<<","<<TempTicket.getParts()<<","<<TempTicket.getPartCost()<<","<<TempTicket.getIssue()<<","<<TempTicket.getStatus()<<","<<TempTicket.getInstallDate()<<","<<TempTicket.getFinishDate()<<","<<endl;
              curr = curr->next;
          }
     }//while there is information to save
    UserList_File.close();//close the file
}

void TicketList::Load_AllTickets(){
    struct TempTicket temp;
    int Current_Save=0;
     std::ifstream UserList_File;//IOstream to file
    std::string FileName="Tickets.txt",Current_Line;
    UserList_File.open(FileName);//opens the file
    while (std::getline(UserList_File, Current_Line))//loop thorough every line in the file
    {
        std::istringstream iss(Current_Line);
        std::string Inner_String;
        while(getline(iss, Inner_String, ','))
        {
            std::istringstream Var_Temp(Inner_String);
            switch (Current_Save) {
                case 0:
                    temp.tickid = Inner_String;
                    Current_Save++;
                    break;
                case 1:
                    temp.ownid = Inner_String;
                    Current_Save++;
                    break;
                case 2:
                    temp.techname1 = Inner_String;
                    Current_Save++;
                    break;
                case 3:
                    temp.techname2 = Inner_String;
                    Current_Save++;
                    break;
                case 4:
                   Var_Temp >> temp.workhours1;
                    Current_Save++;
                    break;
                case 5:
                    Var_Temp >> temp.workhours2;
                    Current_Save++;
                    break;
                case 6:
                    Var_Temp >> temp.expertise1 ;
                    Current_Save++;
                    break;
                case 7:
                    Var_Temp >> temp.expertise2;
                    Current_Save++;
                    break;
                case 8:
                    temp.parts = Inner_String;
                    Current_Save++;
                    break;
                case 9:
                    Var_Temp >> temp.partcost;
                    Current_Save++;
                    break;
                case 10:
                    temp.issue = Inner_String;
                    Current_Save++;
                    break;
                case 11:
                    temp.status = Inner_String;
                    Current_Save++;
                    break;
                case 12:
                    temp.installdate = Inner_String;
                    Current_Save++;
                    break;
                case 13:
                    temp.finishdate = Inner_String;
                    Current_Save=0;
                    break;
            }
        }
        ticketPTR t = new ticket;
        Ticket TempTicket;
        TempTicket.Set_TicketInfomration(temp);
        t -> next = NULL;
        t -> tick = TempTicket;
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
     UserList_File.close();//close the file for use after
}
