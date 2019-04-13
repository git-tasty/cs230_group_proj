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
    string name;
    string id;
    int verification;
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
    cout<<"| 4. Update Ticket.          |"<<endl;
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

struct current_login login() {
    //create the structure to allow us to get all information from the login session
    struct current_login Login_Auth;
    //login_Auth will contain all the diffrent things we get from the user login
    int verification = 0;
    int choice, user_type = 0;
    int commit = 0;
    int expertise = 0;
    string password, name, id, the_code;
    
    cout<<"1. Create an Account"<<endl;
    cout<<"2. Login as a Customer"<<endl;
    cout<<"3. Login as a Technician"<<endl;
    cout<<"4. I'm the Manager"<<endl;
    cout<<"Enter a choice: ";
    cin>>choice;
    
    switch(choice){
        case 1://Create New User Account
        {
            while(commit != 1){
                //This is where we will create a new account
                //setup the display to look nice :)
                cout << string( 100, '\n' );
                cout<<"======= New Account ======="<<endl;
                cout<<"Login Username: ";
                cin>>name;
                cout<<"ID Number: ";
                cin>>id;
                cout<<"Login Password: ";
                cin>>password;
                cout<<"Are you a (1.)Customer or (2.)Technician: ";
                cin>>user_type;
                if(user_type == 2){
                    cout<<"What is your expertise level? (1.)Beginner, (2.)Intermediate, (3.)Expert: ";
                    cin>>expertise;
                }
                //Here we print all the entered data to the user for confirmation
                cout << string( 100, '\n' );//clear the screen
                cout<<"======= Confirm ======="<<endl;
                if(user_type==1)//check if Customer or Technician
                    cout<<"Account type: [Customer]"<<endl;
                else
                    cout<<"Account type: [Technician]"<<endl;
                cout<<"Username: ["<<name<<"]"<<endl;
                cout<<"Password: ["<<password<<"]"<<endl;
                cout<<"Account ID: ["<<id<<"]"<<endl;
                cout<<"========================="<<endl;
                cout<<"Press 1 to Create Account"<<endl<<"Press any other key to Exit"<<endl<<"Choice: ";
                cin>>commit;
            }
            
            if(user_type == 1){//when the user_type is 1 we save the new account to the Customer File
                Customer newcust;//create a Customer instance
                newcust.setInfo(name, id, password);//call the method to save the information to the linked list
                customer.id = id;//set global values
                customer.name = name;//set global values
                ofstream custbook;//start file/IO
                custbook.open("customerlist.txt", ios::app);//append Mode
                custbook<<name<<" "<<id<<" "<<password << endl;
                custbook.close();//close the file
            }else if(user_type == 2){//when the user_type is 2 we save the new account to the Technician File
                Technician newtech;//create a Technician instance
                newtech.setInfo(name, id, password);
                newtech.setExpertise(expertise);//call the method to save the information to the linked list
                technician.id = id;//set global values
                technician.name = name;//set global values
                ofstream techbook;//start file/IO
                techbook.open("technicianlist.txt", ios::app);//append Mode
                techbook << name << " " << id << " " << password << " " << expertise << endl;
                techbook.close();//close the file
            }
            break;
        }
        case 2:
        {
            string temp_user, temp_pass, line;
            int confirmation = 0;
            while(confirmation == 0){
                //setup the display to look nice :)
                cout << string( 100, '\n' );
                cout<<"======= Customer Login ======="<<endl;
                cout << "Username: ";
                cin >> temp_user;
                cout << "Password: ";
                cin >> temp_pass;
                ifstream credentials;//start the file/IO Stream
                size_t pos;//location of the username in the line
                while(credentials.good()){
                    credentials.open("customerlist.txt");//open the file
                    getline(credentials, line);//read the line in from the file
                    pos=line.find(temp_user);//get the location of the username in the file
                    if(pos!=string::npos){//check to see if the username exists on the line
                        pos=line.find(temp_pass);//get the location of the password in the file
                        if(pos!=string::npos){//check if the password exists on the line we are reading
                            string temp_name = line;//copy the line
                            cout<<"======= Login Acceped ======="<<endl;
                            cout << "Welcome, " << temp_name.substr(0, temp_name.find(" ")) << "!" <<endl;//get the username from the line and print it to the user as the welcome message
                            verification = 1;//set globsl verifaction to customer
                            confirmation = 1;//set the global value for loggin in to 1
                            //first we set the global name to the username entered becuase we know that the usename worked
                            name = temp_user;
                            //next we copy the string so we can motify it
                            string tempstring = line;
                            //first erase the username from the string
                            tempstring.erase(0, temp_user.length());
                            //next erase the password from the string
                            tempstring.erase(tempstring.find(temp_pass),tempstring.length());
                            //now we can remove all spaces from it
                            std::string::iterator end_pos = std::remove(tempstring.begin(), tempstring.end(), ' ');
                            tempstring.erase(end_pos, tempstring.end());
                            //finaly we save the user id to the global value so it can be passed on
                            id = tempstring;
                            break;
                        }
                    }
                }
                //we have to check if the user has allready been authenticated
                //if there is more then one user in the database it would fail even if it was right for one of the accounts
                if(confirmation==0){
                //If the username entered dosent match any of the usernames inside the system
                //We need to inform the user and prompt for a retry
                cout << "======= Login Failed =======" <<endl;
                cout<<"The Username or Password entered is incorrect"<<endl<<"[Enter 1 To Retry Any Other Key To Exit]...";
                string Retry_String;
                cin>>Retry_String;
                if(Retry_String!="1"){
                    exit(1);//If the user dosent want to retry we can exit the Program
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
    //here we set the Verifacation level to the return type
    Login_Auth.verification = verification;
    //here we fill the structure with the information we get from the login
    Login_Auth.id = id;
    Login_Auth.name = name;
    //last we return the structure containing all of our information
    return Login_Auth;
    }
    
    
    
    int main(int argc, char** argv){
        TicketList Tickets;
        //declare a new varbale from the type login so we can get all the information from the login
        struct current_login Login_Attempt;
        int opt;
        int verification = 0;
        int exit_status = 0;
        while (exit_status != 1){
            while(verification == 0){
                Login_Attempt = login();//this method will return the username the ID and the verification level
                verification = Login_Attempt.verification;//get the Login verification from the Attempt
            }
            string tikid;
            if (verification == 1){
                bool brkLoop = false;
                do{
                    opt = MainMenu();
                    switch(opt){
                            //fix pulling ID
                            //add ticket issue enter ID and ticket id newtick.set
                            //it dosent set the net ticket
                        case 1:
                            Tickets.AddTicket(Login_Attempt.id);
                            cout<<endl;
                            break;
                        case 2:
                            cout<<"Enter the ID of your Ticket that you want the Status of: ";
                            cin>>tikid;
                            Tickets.CheckStatus(Login_Attempt.id, tikid);
                            break;
                        case 3:
                            Tickets.MyTickets(Login_Attempt.id);
                            break;
                        case 4:
                            cout<<"Enter the ID of the ticket that you want the invoice of: ";
                            cin>>tikid;
                            Tickets.PrintInvoice(Login_Attempt.id, tikid);
                            break;
                        case 5: verification = 0;
                            Login_Attempt.name="";
                            Login_Attempt.id="";
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
                    string tickid;
                    int choice;
                    string status;
                    opt = TechMenu();
                    switch(opt){
                        case 1:
                            cout<<"Enter ticket ID of the ticket you want to claim: ";
                            cin>>tickid;
                            Tickets.ClaimTicket(tickid, technician.name) ;
                            break;
                        case 2:
                            cout<<"Enter the ticket id of the ticket you want to update the status of: ";
                            cin>>tickid;
                            cout<<"Enter a 1 for In-Progress or a 2 for Awaiting-Finalization: ";
                            cin>>choice;
                            if(choice == 1){
                                status = "In-Progress";
                            }if(choice == 2){
                                status = "Awaiting-Finalization";
                            }
                            Tickets.UpdateStatus(tickid, status);
                            break;
                        case 3:
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
                        }break;
                        case 4:
                            cout<<"Enter the Ticcket ID of the ticket you want to update: ";
                            cin>>tickid;
                            Tickets.UpdateTicket(tickid);
                            break;
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
                    string tickid;
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
                        case 4:
                            cout<<"Enter the Ticket ID of the ticket you wish to close: ";
                            cin>>tickid;
                            Tickets.UpdateStatus(tickid, "Complete");
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
