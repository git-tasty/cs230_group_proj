#include <iostream>
#include <fstream>
#include <sstream>
#include "TicketNode.h"

using namespace std;

void TicketList::Set_NewTicket(Customer Authenticated_Customer){
    ticketPTR t = new ticket;
    Ticket Temp_NewTicket;
    string StartingIssue;
    string EndingIssue;
    std::string Temp_TicketTitle1,Temp_TicketTitle2;
    t -> next = NULL;
    cout << string( 100, '\n' );
    cout<<"========= New Support Ticket ========="<<endl;
    cout<<"Give a Brief Name For The Ticket:"<<endl;
    cin>>Temp_TicketTitle1;
    getline(cin, Temp_TicketTitle2);
    Temp_TicketTitle1 = Temp_TicketTitle1 + Temp_TicketTitle2;
    cout<<"Please Describe Your issue:"<<endl;
    cin>>StartingIssue;
    getline(cin, EndingIssue);
    EndingIssue = StartingIssue + EndingIssue;
    //print the temp ticket to the user so they can see it
    cout << string( 100, '\n' );
    cout<<"========= Review Support Ticket ========="<<endl;
    cout<<"Ticket Owner: ["<<Authenticated_Customer.Get_FirstName()<<" "<<Authenticated_Customer.Get_LastName()<<"]"<<std::endl;
    cout<<"Ticket ID: ["<<Get_NextUserID()<<"]"<<endl;
    cout<<"Ticket Title: ["<<Temp_TicketTitle1<<"]"<<endl;
    cout<<"Stated Issue: ["<<EndingIssue<<"]"<<endl;
    cout<<"========================================="<<endl;
    cout<<"Press 1 To Confirm and Submit the Ticket"<<endl<<"Press any Other Key To Cancel Submission"<<endl<<"Choice: ";
    cin>>StartingIssue;
    if(StartingIssue=="1"){
        //now that we have the issue saved we can assign the ticket a new ID Number
        Temp_NewTicket.Set_TickID(Get_NextUserID());
        Temp_NewTicket.Set_TicketTitle(Temp_TicketTitle1);
        Temp_NewTicket.Set_TicketDescription(EndingIssue);
        Temp_NewTicket.Set_Owner(Authenticated_Customer);
        t -> tick = Temp_NewTicket;
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
        cout << string( 100, '\n' );
        cout<<"=============================="<<endl;
        cout<<"Ticket Entered Correctly"<<endl<<"[Enter Any Key to Continue]...";
        cin>>StartingIssue;
        cout << string( 100, '\n' );
    }
}

void TicketList::Get_AllTickets(){
    if(head != NULL){
        //double total;
        curr = head;
        cout<<"================= List of all Tickets Submitted ================="<<endl;
        while(curr != NULL){
            cout<<"Ticket ID: "<<curr->tick.Get_TicketID()<<endl<<"Ticket Title: "<<curr->tick.Get_TicketTitle()<<endl;
            cout<<"Ticket Owner: "<<curr->tick.Get_Owner().Get_FirstName()<<endl;
            if(curr->tick.Get_Technician1().Get_UserID()!=""&&curr->tick.Get_Technician2().Get_UserID()!=""){
                cout<<"Technicians Currently Working On Ticket 2/2"<<endl;
            } else if(curr->tick.Get_Technician1().Get_UserID()!=""||curr->tick.Get_Technician2().Get_UserID()!=""){
                cout<<"Technicians Currently Working On Ticket 1/2"<<endl;
            }else{
                cout<<"Technicians Currently Working On Ticket 0/2"<<endl;
            }
            cout<<"================================================================"<<endl;
            curr = curr->next;
        }
    }else{
        cout<<"There Are Currently No Tickets In the System"<<endl;
    }
}

void TicketList::Get_AllTickets(Customer Authenticated_Customer){
    double total;
    curr = head;
    cout<<"================= List of all Your Submitted Tickets ================="<<endl;
    while(curr != NULL){
        if(curr -> tick.Get_Owner().Get_UserID() == Authenticated_Customer.Get_UserID()){
            total = 0;
            cout<<"Ticket Title: "<<curr->tick.Get_TicketTitle()<<endl;//displays ticket title
            cout<<"Ticket ID: "<<curr->tick.Get_TicketID()<<endl;//diaplys ticket id
            cout<<"Ticket Owner's Name: "<<curr->tick.Get_Owner().Get_FirstName()<<" "<<curr->tick.Get_Owner().Get_LastName()<<endl;//displays ticket owner name
            cout<<"Ticket Owners Username: "<<curr->tick.Get_Owner().Get_Username()<<endl;//owners username
            cout<<"First Technician: "<<curr->tick.Get_Technician1().Get_FirstName()<<" "<<curr->tick.Get_Technician1().Get_LastName()<<endl;//tech 1 name
            cout<<"First Technician's Username: "<<curr->tick.Get_Technician1().Get_Username()<<endl;//tech 1 username
            cout<<"Seccond Technician: "<<curr->tick.Get_Technician2().Get_FirstName()<<" "<<curr->tick.Get_Technician2().Get_LastName()<<endl;//tech 2 name
            cout<<"Seccond Technician's Username: "<<curr->tick.Get_Technician2().Get_Username()<<endl;//tech 2 username
            //logic for labor pricing
            if(curr -> tick.Get_Technician1().Get_ExpertiseLevel() == 1){
                total = total + curr -> tick.Get_Technician1().Get_WorkHours() * 100;
            }else if(curr ->tick.Get_Technician1().Get_ExpertiseLevel() == 2){
                total = total + curr -> tick.Get_Technician1().Get_WorkHours() * 175;
            }else if(curr ->tick.Get_Technician1().Get_ExpertiseLevel() == 3){
                total = total + curr -> tick.Get_Technician1().Get_WorkHours() * 250;
            }
            if(curr -> tick.Get_Technician2().Get_ExpertiseLevel() == 1){
                total = total + curr -> tick.Get_Technician2().Get_WorkHours() * 100;
            }else if(curr ->tick.Get_Technician2().Get_ExpertiseLevel() == 2){
                total = total + curr -> tick.Get_Technician2().Get_WorkHours() * 175;
            }else if(curr ->tick.Get_Technician2().Get_ExpertiseLevel() == 3){
                total = total + curr -> tick.Get_Technician2().Get_WorkHours() * 250;
            }
            cout<<"Total Labor Costs: $"<<total<<endl;//total labor cost
            cout<<"Parts Required/Ordered For Ticket: "<<curr -> tick.Get_PartList()<<endl;//parts ordered
            cout<<"Total Parts Cost: "<<curr -> tick.Get_PartCost()<<endl;//part costs
            cout<<"Stated Issue: "<<curr -> tick.Get_TicketDescription()<<endl;//issue from user
            cout<<"Parts installed on: "<<curr -> tick.Get_PartInstallDate()<<endl;//date parts were installed
            cout<<"Current Status: "<<curr -> tick.Get_TicketStatus()<<endl;//ticket status
            cout<<"Finish Date: "<<curr -> tick.Get_TicketFinishDate()<<endl;//finish date
            total = total + curr-> tick.Get_PartCost();
            cout<<"Total Cost: $"<<total<<endl;//total cost
            cout<<"==========================================="<<endl;
        }
        curr = curr -> next;
    }
}
int TicketList::Get_NextUserID(){
    int Next_UserID=0;
    curr = head;
    while(curr != NULL){//get string steam from the Ticket ID
            if(curr->tick.Get_TicketID()>Next_UserID){//we check for the largest ID from all of the Tickets
                Next_UserID=curr->tick.Get_TicketID();
            }
        curr = curr -> next;
    }
    return Next_UserID+1;
}
//displays status of entered ticket
void TicketList::Get_TicketStatus(Customer Authenticated_Customer, int Ticket_ID){
    curr = head;
    while(curr != NULL){
        if(curr -> tick.Get_Owner().Get_UserID() == Authenticated_Customer.Get_UserID()){
            if(curr -> tick.Get_TicketID() == Ticket_ID){
                cout<<"Current Status: "<<curr -> tick.Get_TicketStatus()<<endl;//status of selected ticket
            }
        }
        curr = curr -> next;
    }
}

void TicketList::Get_Invoice(Customer Authenticated_Customer, int Ticket_ID){
    curr = head;
    double total;
    while(curr != NULL){
        if(curr -> tick.Get_Owner().Get_UserID() == Authenticated_Customer.Get_UserID()){
            if(curr -> tick.Get_TicketID() == Ticket_ID){
                if(curr -> tick.Get_TicketStatus() == "Complete"){
                    total = 0;
                    cout<<"Ticket Title: "<<curr->tick.Get_TicketTitle()<<endl;//ticket title
                    cout<<"Ticket ID: "<<curr->tick.Get_TicketID()<<endl;//ticket id
                    cout<<"Ticket Owner's Name: "<<curr->tick.Get_Owner().Get_FirstName()<<" "<<curr->tick.Get_Owner().Get_LastName()<<endl;//owner name
                    cout<<"Ticket Owners Username: "<<curr->tick.Get_Owner().Get_Username()<<endl;//owner username
                    cout<<"First Technician: "<<curr->tick.Get_Technician1().Get_FirstName()<<" "<<curr->tick.Get_Technician1().Get_LastName()<<endl;//tech 1 name
                    cout<<"First Technician's Username: "<<curr->tick.Get_Technician1().Get_Username()<<endl;//tech 1 username
                    cout<<"Seccond Technician: "<<curr->tick.Get_Technician2().Get_FirstName()<<" "<<curr->tick.Get_Technician2().Get_LastName()<<endl;//tech 2 name
                    cout<<"Seccond Technician's Username: "<<curr->tick.Get_Technician2().Get_Username()<<endl;//tech 2 username
                    //logic for labor pricing
                    if(curr -> tick.Get_Technician1().Get_ExpertiseLevel() == 1){
                        total = total + curr -> tick.Get_Technician1().Get_WorkHours() * 100;
                    }else if(curr ->tick.Get_Technician1().Get_ExpertiseLevel() == 2){
                        total = total + curr -> tick.Get_Technician1().Get_WorkHours() * 175;
                    }else if(curr ->tick.Get_Technician1().Get_ExpertiseLevel() == 3){
                        total = total + curr -> tick.Get_Technician1().Get_WorkHours() * 250;
                    }
                    if(curr -> tick.Get_Technician2().Get_ExpertiseLevel() == 1){
                        total = total + curr -> tick.Get_Technician2().Get_WorkHours() * 100;
                    }else if(curr ->tick.Get_Technician2().Get_ExpertiseLevel() == 2){
                        total = total + curr -> tick.Get_Technician2().Get_WorkHours() * 175;
                    }else if(curr ->tick.Get_Technician2().Get_ExpertiseLevel() == 3){
                        total = total + curr -> tick.Get_Technician2().Get_WorkHours() * 250;
                    }
                    cout<<"Total Labor Costs: $"<<total<<endl;//total labor cost
                    cout<<"Parts Required/Ordered For Ticket: "<<curr -> tick.Get_PartList()<<endl;//parts used
                    cout<<"Total Parts Cost: "<<curr -> tick.Get_PartCost()<<endl;//part cost
                    cout<<"Stated Issue: "<<curr -> tick.Get_TicketDescription()<<endl;//ticket issue from customer
                    cout<<"Parts installed on: "<<curr -> tick.Get_PartInstallDate()<<endl;//date partrs were installed
                    cout<<"Current Status: "<<curr -> tick.Get_TicketStatus()<<endl;//shows ticket status
                    cout<<"Finish Date: "<<curr -> tick.Get_TicketFinishDate()<<endl;//date ticket was finished
                    total = total + curr-> tick.Get_PartCost();//part costs
                    cout<<"Total Cost: $"<<total<<endl;//total costs
                    cout<<"==========================================="<<endl;
                }else{
                    cout<<"No invoice is available for this ticket yet as it is not complete."<<endl;
                }
            }
        }
        curr = curr -> next;
    }
} 
//adding techs to tickets
void TicketList::ClaimCustomerTicket(int Ticket_ID, Technician Authenticated_Technician){
    curr = head;
    while(curr != NULL){
        if(curr ->tick.Get_TicketID() == Ticket_ID){
            if(curr -> tick.Get_Technician1().Get_Username() == ""){
                curr -> tick.Set_Worker1(Authenticated_Technician);//setting techs
                cout<<"You have been added to Ticket "<<Ticket_ID<<endl;
                
            }else if(curr -> tick.Get_Technician1().Get_Username() != "" && curr->tick.Get_Technician2().Get_Username() == ""){//sets tech 2
                curr -> tick.Set_Worker2(Authenticated_Technician);
                cout<<"You have been added to Ticket "<<Ticket_ID<<endl;
            }else{
                cout<<"This Ticket Already has two technicians and can not be claimed."<<endl;
            }
        }
        curr = curr -> next;
    }
}
int TicketList::CloseTicket(){
    int Temp_TicketID;
    curr = head;
    cout<<"================== All Tickets =================="<<endl;
    while(curr != NULL){
    	if(curr -> tick.Get_TicketStatus() != "Complete"){
		
        	cout<<"ID: "<<curr -> tick.Get_TicketID()<<" | Owner: "<<curr -> tick.Get_Owner().Get_FirstName()<<" | Title: "<<curr -> tick.Get_TicketTitle()<<endl;
       		curr = curr -> next;//lists all tickets if they are not complete
    	}
    }
    cout<<"Enter the ID of the ticket you want to close: ";
    cin>>Temp_TicketID;
    return Temp_TicketID;
}
//method for updating ticket statuses
void TicketList::UpdateStatus(int Ticket_ID, std::string Ticket_Status){
    curr = head;
    while(curr != NULL){
        if(curr -> tick.Get_TicketID() == Ticket_ID){
            curr -> tick.Set_TicketStatus(Ticket_Status);//sets status of selected ticket
        }
        curr = curr -> next;
    }
}

void TicketList::UpdateTicket(int Ticket_ID){
    curr = head;
    while (curr != NULL){
        if(curr -> tick.Get_TicketID() == Ticket_ID){
            int select = 0;
            Technician TempTech1 = curr->tick.Get_Technician1();
            Technician TempTech2 = curr->tick.Get_Technician2();
            while(select != 7){
            	//menu for update options
                cout<<"======== Ticket Update Menu ========"<<endl;
                if(TempTech1.Get_Username()!=""){
                    cout<<"| 1. Update "<<TempTech1.Get_FirstName()<<"'s Hours"<<endl;
                }
                if(TempTech2.Get_Username()!=""){
                    cout<<"| 2. Update "<<TempTech2.Get_FirstName()<<"'s Hours"<<endl;
                }
                cout<<"| 3. Update Parts"<<endl;
                cout<<"| 4. Update Part Costs"<<endl;
                cout<<"| 5. Update Part Installation Date"<<endl;
                cout<<"| 6. Update Finish Date"<<endl;
                cout<<"| 7. Exit"<<endl;
                cout<<"===================================="<<endl;
                cout<<"Select an Option: ";
                cin>>select;
                double hours;
                double partcost;
                string part;
                string parts;
                string date;
                if(select == 1){//option to update tech 1 hours
                    if(TempTech1.Get_Username()!=""){
                        cout<<"How many hours did "<<TempTech1.Get_FirstName()<<" Work: ";
                        cin>>hours;
                        curr->tick.Set_WorkerHours(TempTech1, hours);
                    }
                }else if(select == 2){//option to update tech 2 hours
                    if(TempTech1.Get_Username()!=""){
                        cout<<"How many hours did "<<TempTech2.Get_FirstName()<<" Work: ";
                        cin>>hours;
                        curr->tick.Set_WorkerHours(TempTech2, hours);
                    }
                }else if(select == 3){//option to update parts used
                    cout<<"What Parts were used: ";
                    cin>>part;
                    getline(cin, parts);
                    parts = part + parts;
                    curr -> tick.Set_PartList(parts);
                }else if(select == 4){//option to update part costs
                    cout<<"How much did the parts cost: ";
                    cin>>partcost;
                    curr -> tick.Set_PartCost(partcost);
                }else if(select == 5){//option to update installation date
                    cout<<"The format for date is mm-dd-yyyy"<<endl;
                    cout<<"What day were the parts installed: ";
                    cin>>date;
                    curr -> tick.Set_InstallDate(date);
                }else if(select == 6){//option to update finish date
                    cout<<"The format for date is mm-dd-yyyy"<<endl;
                    cout<<"What day was the ticket finished: ";
                    cin>>date;
                    curr -> tick.Set_FinishDate(date);
                }
            }
        }
        curr = curr -> next;
    }
} 
//saves all tickets to file
void TicketList::Save_AllTickets(){
    Ticket TempTicket;
    std::ofstream UserList_File;//IOstream to file
    std::string FileName = "Tickets.txt";
    UserList_File.open("Tickets.txt");
    if(head != NULL){
        curr = head;
        while(curr != NULL){
            TempTicket = curr->tick;
           
            
            UserList_File<<TempTicket.Get_TicketID()<<","<<TempTicket.Get_PartList()<<","<<TempTicket.Get_PartCost()<<","<<TempTicket.Get_TicketTitle()<<","<<TempTicket.Get_TicketDescription()<<","<<TempTicket.Get_TicketStatus()<<","<<TempTicket.Get_PartInstallDate()<<","<<TempTicket.Get_TicketFinishDate()<<","<<endl;
            
            
            
            UserList_File<<TempTicket.Get_Owner().Get_Username()<<","<<TempTicket.Get_Owner().Get_FirstName() <<","<< TempTicket.Get_Owner().Get_LastName()<<","<< TempTicket.Get_Owner().Get_UserID()<<","<< TempTicket.Get_Owner().Get_Password()<<","<<TempTicket.Get_Owner().Get_UserType()<<","<<endl;
            UserList_File<<TempTicket.Get_Technician1().Get_Username()<<","<<TempTicket.Get_Technician1().Get_FirstName() <<","<< TempTicket.Get_Technician1().Get_LastName()<<","<< TempTicket.Get_Technician1().Get_UserID()<<","<< TempTicket.Get_Technician1().Get_Password()<<","<<TempTicket.Get_Technician1().Get_UserType()<<","<<TempTicket.Get_Technician1().Get_ExpertiseLevel()<<","<<TempTicket.Get_Technician1().Get_WorkHours()<<","<<endl;
            UserList_File<<TempTicket.Get_Technician2().Get_Username()<<","<<TempTicket.Get_Technician2().Get_FirstName() <<","<< TempTicket.Get_Technician2().Get_LastName()<<","<< TempTicket.Get_Technician2().Get_UserID()<<","<< TempTicket.Get_Technician2().Get_Password()<<","<<TempTicket.Get_Technician2().Get_UserType()<<","<<TempTicket.Get_Technician2().Get_ExpertiseLevel()<<","<<TempTicket.Get_Technician2().Get_WorkHours()<<","<<endl;
            
            curr = curr->next;
        }
    }//while there is information to save
    UserList_File.close();//close the file
}
//loads all tickets from file
void TicketList::Load_AllTickets(){
    struct TempTicket temp;
    int Check_Line=0;
    int Current_Save=0;
    int ExpertiseLevel = 0;
    double WorkHours = 0.0;
    std::ifstream UserList_File;//IOstream to file
    std::string FileName="Tickets.txt",Current_Line;
    UserList_File.open("Tickets.txt");//opens the file
    while (std::getline(UserList_File, Current_Line))//loop thorough every line in the file
    {
        if(Check_Line==0){//ticket details
            std::istringstream iss(Current_Line);
            std::string Inner_String;
            while(getline(iss, Inner_String, ','))
            {
                std::istringstream Var_Temp(Inner_String);
                switch (Current_Save) {
                    case 0:
                        Var_Temp >> temp.Ticket_ID;
                        Current_Save++;
                        break;
                    case 1:
                        Var_Temp >> temp.Ticket_PartsUsed;
                        Current_Save++;
                        break;
                    case 2:
                        Var_Temp >> temp.Ticket_Partcost;
                        Current_Save++;
                        break;
                    case 3:
                        Var_Temp >> temp.Ticket_Title;
                        Current_Save++;
                        break;
                    case 4:
                        Var_Temp >> temp.Ticket_Description;
                        Current_Save++;
                        break;
                    case 5:
                        Var_Temp >> temp.Ticket_Status;
                        Current_Save++;
                        break;
                    case 6:
                        Var_Temp >> temp.Part_InstallDate;
                        Current_Save++;
                        break;
                    case 7:
                        Var_Temp >> temp.Ticket_FinishDate;
                        Current_Save=0;
                        break;
                }
            }
            Check_Line=1;
        }else if(Check_Line==1){//owner
            struct current_login TempLogin;
            std::istringstream iss(Current_Line);
            std::string Inner_String;
            while(getline(iss, Inner_String, ','))
            {
                std::istringstream Var_Temp(Inner_String);
                
                switch (Current_Save) {
                    case 0:
                        Var_Temp >> TempLogin.Username;
                        Current_Save++;
                        break;
                    case 1:
                        Var_Temp >> TempLogin.first_name;
                        Current_Save++;
                        break;
                    case 2:
                        Var_Temp >> TempLogin.Last_name;
                        Current_Save++;
                        break;
                    case 3:
                        Var_Temp >> TempLogin.id;
                        Current_Save++;
                        break;
                    case 4:
                        Var_Temp >> TempLogin.Password;
                        Current_Save++;
                        break;
                    case 5:
                        Var_Temp >> TempLogin.User_AuthLevel;
                        Current_Save=0;
                        break;
                }
            }
            Customer Temp_Customer = Customer(TempLogin);
            temp.Owner = Temp_Customer;
            Check_Line=2;
        }
        else if(Check_Line==2){//tech1
            struct current_login TempLogin;
            std::istringstream iss(Current_Line);
            std::string Inner_String;
            while(getline(iss, Inner_String, ','))
            {
                std::istringstream Var_Temp(Inner_String);
                
                switch (Current_Save) {
                    case 0:
                        Var_Temp >> TempLogin.Username;
                        Current_Save++;
                        break;
                    case 1:
                        Var_Temp >> TempLogin.first_name;
                        Current_Save++;
                        break;
                    case 2:
                        Var_Temp >> TempLogin.Last_name;
                        Current_Save++;
                        break;
                    case 3:
                        Var_Temp >> TempLogin.id;
                        Current_Save++;
                        break;
                    case 4:
                        Var_Temp >> TempLogin.Password;
                        Current_Save++;
                        break;
                    case 5:
                        Var_Temp >> TempLogin.User_AuthLevel;
                        Current_Save++;
                        break;
                    case 6:
                        Var_Temp >> ExpertiseLevel;
                        Current_Save++;
                        break;
                    case 7:
                        Var_Temp >> WorkHours;
                        Current_Save=0;
                        break;
                }
            }
            Technician Temp_Technician = Technician(TempLogin);
            Temp_Technician.Set_WorkHours(WorkHours);
            Temp_Technician.Set_ExpertiseLevel(ExpertiseLevel);
            temp.Worker1 = Temp_Technician;
            Check_Line=3;
        }
        else if(Check_Line==3){
            struct current_login TempLogin;
            std::istringstream iss(Current_Line);
            std::string Inner_String;
            while(getline(iss, Inner_String, ','))
            {
                std::istringstream Var_Temp(Inner_String);
                
                switch (Current_Save) {
                    case 0:
                        Var_Temp >> TempLogin.Username;
                        Current_Save++;
                        break;
                    case 1:
                        Var_Temp >> TempLogin.first_name;
                        Current_Save++;
                        break;
                    case 2:
                        Var_Temp >> TempLogin.Last_name;
                        Current_Save++;
                        break;
                    case 3:
                        Var_Temp >> TempLogin.id;
                        Current_Save++;
                        break;
                    case 4:
                        Var_Temp >> TempLogin.Password;
                        Current_Save++;
                        break;
                    case 5:
                        Var_Temp >> TempLogin.User_AuthLevel;
                        Current_Save++;
                        break;
                    case 6:
                        Var_Temp >> ExpertiseLevel;
                        Current_Save++;
                        break;
                    case 7:
                        Var_Temp >> WorkHours;
                        Current_Save=0;
                        break;
                }
            }
            Technician Temp_Technician = Technician(TempLogin);
            Temp_Technician.Set_WorkHours(WorkHours);
            Temp_Technician.Set_ExpertiseLevel(ExpertiseLevel);
            temp.Worker2 = Temp_Technician;
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
            
            Check_Line=0;
        }
    }
    
    UserList_File.close();//close the file for use after
}
