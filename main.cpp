//manager master login information:
//password: root
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

#include "User.h"
//#include "User.cpp"   //comment this line out if you're using Dev C++
#include "Customer.h"
//#include "Customer.cpp"   //comment this line out if you're using Dev C++
#include "Technician.h"
//#include "Technician.cpp"   //comment this line out if you're using Dev C++
#include "Ticket.h"
#include "TicketNode.h"

using namespace std;

struct current_login {
  string name, id;
} customer, technician;


int MainMenu(){
    int selection;
    cout<<"========= Main Menu ========="<<endl;
    cout<<"| 1. Create New Ticket.     |"<<endl;
    cout<<"| 2. View Ticket Status.    |"<<endl;
    cout<<"| 3. View All Your Tickets. |"<<endl;
    cout<<"| 4. View Ticket Invoice.   |"<<endl;
    cout<<"| 5. Log Out.               |"<<endl;
    cout<<"| 6. Exit Program.          |"<<endl;
    cout<<"============================="<<endl;
    cout<<"Enter a Selection: ";
    cin>>selection;
    return selection;
}

int TechMenu(){
    int selection;
    cout<<"========= Tech Menu  ========="<<endl;
    cout<<"| 1. Claim a Ticket.         |"<<endl;
    cout<<"| 2. Update Ticket Status.   |"<<endl;
    cout<<"| 3. View Technicians.       |"<<endl;
    cout<<"| 4. Complete a Ticket.      |"<<endl;
    cout<<"| 5. Log Out.                |"<<endl;
    cout<<"| 6. Exit Program.           |"<<endl;
    cout<<"============================="<<endl;
    cout<<"Enter a Selection: ";
    cin>>selection;
    return selection;
}

int ManagerMenu(){
  int selection;
  cout<<"======= Welcome, Chief ======="<<endl;
  cout<<"| 1. See All Customers       |"<<endl;
  cout<<"| 2. See All Technicians.    |"<<endl;
  cout<<"| 3. View All Tickets.       |"<<endl;
  cout<<"| 4. Close a Ticket.         |"<<endl;
  cout<<"| 5. Log Out.                |"<<endl;
  cout<<"| 6. Exit Program.           |"<<endl;
  cout<<"============================="<<endl;
  cout<<"Enter a Selection: ";
  cin>>selection;
  return selection;
}

int login() {
    int verification = 0;
    int choice, user_type;
    int commit = 0;
    int expertise;
    string password, name, id, the_code;
    cout<<"1. Create an Account"<<endl;
    cout<<"2. Login as a Customer"<<endl;
    cout<<"3. Login as a Technician"<<endl;
    cout<<"4. I'm the Manager"<<endl;
    cout<<"Enter a choice: ";
    cin>>choice;

    switch(choice){
      case 1:
      {
        while(commit != 1){
            cout<<"Enter your first name: ";
            cin>>name;
            cout<<"Enter a user id that you'd like to use: ";
            cin>>id;
            cout<<"Enter a password: ";
            cin>>password;
            cout<<"Are you a (1.)Customer or (2.)Technician: ";
            cin>>user_type;
            if(user_type == 2){
            	cout<<"What is your expertise level? (1.)Beginner, (2.)Intermediate, (3.)Expert: ";
            	cin>>expertise;
			}
            cout<<"Press 1 to commit this data, otherwise press any other number: ";
            cin>>commit;
        }

        if(user_type == 1){
        	Customer newcust;
        	newcust.setInfo(name, id, password);

        	ofstream custbook;
        	custbook.open("customerlist.txt", ios::app);
        	custbook<<name<<" "<<id<<" "<<password << endl;
        	custbook.close();
		break;
		}else if(user_type == 2){
			Technician newtech;
			newtech.setInfo(name, id, password);
			newtech.setExpertise(expertise);

			ofstream techbook;
			techbook.open("technicianlist.txt", ios::app);
			techbook << name << " " << id << " " << password << " " << expertise << endl;
			techbook.close();
			break;

		}

        break;
    }
      case 2:
      {
      	string temp_user, temp_pass, line;
	int confirmation = 0;
	while(confirmation == 0){
		cout << "Enter your username: ";
		cin >> temp_user;
		cout << "Enter your password: ";
		cin >> temp_pass;
			ifstream credentials;
			size_t pos;
			while(credentials.good()){
				credentials.open("customerlist.txt");
				getline(credentials, line);
				pos=line.find(temp_user);
				if(pos!=string::npos){
					pos=line.find(temp_pass);
					if(pos!=string::npos){
						string temp_name = line;
						cout << "Welcome, " << temp_name.substr(0, temp_name.find(" ")) << "!" <<endl;
						verification = 1;
						confirmation = 1;
						break;
					}
				}
				else{
				cout << "The username or password you typed is incorrect!" <<endl;
				}
			}
	}
	break;
      }
      case 3:
     	 {
      	string temp_user, temp_pass, line;
	int confirmation = 0;
	while(confirmation == 0){
		cout << "Enter your username: ";
		cin >> temp_user;
		cout << "Enter your password: ";
		cin >> temp_pass;
			ifstream credentials;
			size_t pos;
			while(credentials.good()){
				credentials.open("technicianlist.txt");
				getline(credentials, line);
				pos=line.find(temp_user);
				if(pos!=string::npos){
					pos=line.find(temp_pass);
					if(pos!=string::npos){
						string temp_name = line;
						cout << "Welcome, " << temp_name.substr(0, temp_name.find(" ")) << "!" <<endl;
						verification = 2;
						confirmation = 1;
						break;
					}
				}
				else{
				cout << "The username or password you typed is incorrect!" <<endl;
				}
			}
	}
	break;
      }

      case 4:
          {
          cout <<"Enter the Code, Chief:";
          cin >> the_code;
          if(the_code.compare("root") == 0){
            verification = 3;
            break;
          } else{
            cout <<"....You're not the Chief...\n";
            verification = 0;
            break;
            }
          }
      default: cout << choice << " is an invalid option!" << endl;
    }
   return verification;
}



int main(int argc, char** argv){
	TicketList Tickets;
    int opt;
    int verification = 0;
    int exit_status = 0;
    while (exit_status != 1){
    while(verification == 0){
        verification = login();
    }

    if (verification == 1){
      bool brkLoop = false;
        do{
            opt = MainMenu();
            switch(opt){
                case 1:
                	Tickets.AddTicket("test");//Evan we need to fix id and name they are not pulled at login. WHen this is fixed put id in the () 
                  break;
                case 2:
                  break;
                case 3:
                	Tickets.MyTickets("test");//same as comment for #1 put id in when fixed 
                  break;
                case 4:
                  break;
                case 5: verification = 0;
			             brkLoop = true;
                   break;
                case 6: cout<<"Goodbye!"<<endl;
           		brkLoop = true;
			exit_status = 1;
			break;
	    }
    }while(!brkLoop);
    }

    if (verification == 2){
      bool brkLoop = false;
        do{
            opt = TechMenu();
            switch(opt){
                case 5:
                  technician.name = "";
                  technician.id = "";
                  verification = 0;
                  brkLoop = true;
                  break;
                case 6: cout<<"Goodbye!"<<endl;
                  brkLoop = true;
                  exit_status = 1;
                  break;
            }
        }while(!brkLoop);
    }

    if (verification == 3){
      bool brkLoop = false;
        do{
            opt = ManagerMenu();
            switch(opt){
                  case 1:
			{
			  ifstream user_list("customerlist.txt");
			  if (!user_list.is_open()){
			  	cout << "Failed to Open File!\n";
			  }
				string whole;
				while(getline(user_list, whole))
				{
					cout << whole.substr(0, whole.find(" ")) << ": " << whole.substr(whole.find(" "), whole.find(" ")) << endl;
				}
				user_list.close();
			} break;
		  case 2:

			{
			  ifstream user_list("technicianlist.txt");
			  if (!user_list.is_open()){
			  	cout << "Failed to Open File!\n";
			  }
				string whole;
				while(getline(user_list, whole))
				{
					cout << whole.substr(0, whole.find(" ")) << ": " << whole.substr(whole.find(" "), whole.find(" ")) << endl;
				}
				user_list.close();
			} break;
			
			case 3:
				Tickets.PrintTickets();
				break;

		  case 5:
                  verification = 0;
                  brkLoop = true;
                  break;
                case 6: cout<<"Goodbye!"<<endl;
                  brkLoop = true;
                  exit_status = 1;
                  break;
            }
        }while(!brkLoop);
    }
  }
    return 0;
}
