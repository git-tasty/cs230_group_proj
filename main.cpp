//CS-230 Final Group Project
//Deisnged by
//-Andrew Thumma
//-Evan Kamuf
//-Alexander Barnes
//-Jared Pridgeon
//---------- Include ----------------|
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include "Ticket.h"
#include "TicketNode.h"
using namespace std;
#define Name_Limit 20
#define Manager_Password "root"
//------ Function_Prototypes --------|
int MainMenu();
int TechMenu();
int ManagerMenu();
struct current_login Startup_menu();
struct current_login login();
struct current_login Get_Login_information(std::string User_LoginLevel);
struct current_login Create_New_Account();
bool Check_UsernameExists(std::string UsernameToCheck);
int GetNextUserID();
int Manager_Login();
//---------- End Setup ---------------|
/**
 -Main Def-
 Main holds the linked list and login information
 the user can log into diffrent levels of accounts and create and motify tickets
 the end goal was to design this project around a ticketing system
 */
int main(int argc, char** argv){
    //---------- Varables ---------------|
    TicketList Tickets;//Tickets is the Linked List of tickets
    Customer LoggedIn_Customer;//Customer Object
    Technician LoggedIn_Technician;//Technician Object
    struct current_login Authenticated_User;//Login_Attempt will contian the users login information
    string Temp_UserInput;//used for temp user input
    int Temp_intInput;
    int Menu_Selection;//this will contain the users choice from the main menu
    int User_AuthLevel = 0;//this int will be returned with the account level of the current user
    int exit_status = 0;//used to determin exit of loops
    bool brkLoop = false;//if user decides to Exit loop Will be TRUE
    //----- load Alread Created tickets if any ----------|
    Tickets.Load_AllTickets();
    do{
        //----- Login Verification ----------|
        Authenticated_User = Startup_menu();//Send User to login Screen and get results as structure
        switch (Authenticated_User.User_AuthLevel) {
            case 1://when the user's AuthLevel is "Customer"
                //----- Customer Verification ----------|
                LoggedIn_Customer = Customer(Authenticated_User);//set the current Customer to the logged in user
                brkLoop = false;
                do{
                    Menu_Selection = MainMenu();//get the users selection from the main menu
                    switch(Menu_Selection){
                        case 1://Create Ticket
                            Tickets.Set_NewTicket(LoggedIn_Customer);//Call Create Ticket
                            cout<<endl;
                            
                            
                            Tickets.Save_AllTickets();
                            break;
                        case 2://get status of current ticket
                            cout<<"Enter the ID of your Ticket that you want the Status of: ";
                            cin>>Temp_intInput;
                            Tickets.Get_TicketStatus(LoggedIn_Customer, Temp_intInput);
                            break;
                        case 3://get all current tickets
                            Tickets.Get_AllTickets(LoggedIn_Customer);
                            break;
                        case 4://get invoice of single ticket
                            cout<<"Enter the ID of the ticket that you want the invoice of: ";
                            cin>>Temp_intInput;
                            Tickets.Get_Invoice(LoggedIn_Customer, Temp_intInput);
                            break;
                        case 5://logg out of account
                            Authenticated_User.User_AuthLevel = 0;
                            Authenticated_User.Username="";
                            Authenticated_User.id="";
                            brkLoop = true;
                            break;
                        case 6://exit the program
                            cout<<"Goodbye!"<<endl;
                            brkLoop = true;
                            exit_status = 1;
                            break;
                    }
                }while(!brkLoop);
                break;//end case 1
            case 2:
                //----- Technician Verification ----------|
                LoggedIn_Technician = Technician(Authenticated_User);//set the current Customer to the logged in user
                brkLoop = false;
                do{
                    int choice;//the seccondary menu selection
                    string status;
                    Menu_Selection = TechMenu();//display the technician menu to the user
                    switch(Menu_Selection){
                        case 1://claim a ticket
                            cout<<"Enter ticket ID of the ticket you want to claim: ";
                            cin>>Temp_intInput;
                            Tickets.ClaimCustomerTicket(Temp_intInput, LoggedIn_Technician) ;
                            Tickets.Save_AllTickets();
                            break;
                        case 2://update a ticket
                            cout<<"Enter the ticket id of the ticket you want to update the status of: ";
                            cin>>Temp_intInput;
                            cout<<"Enter a 1 for In-Progress or a 2 for Awaiting-Finalization: ";
                            cin>>choice;
                            if(choice == 1){
                                status = "In-Progress";
                            }if(choice == 2){
                                status = "Awaiting-Finalization";
                            }
                            Tickets.UpdateStatus(Temp_intInput, status);
                            Tickets.Save_AllTickets();
                            break;
                        case 3://view all current technicians
                        {
                            ifstream user_list("Technicians.txt");
                            if (!user_list.is_open()){
                                cout << "Failed to Open File!\n";
                            }
                            string whole;
                            while(getline(user_list, whole))
                            {
                                cout << whole.substr(0, whole.find(" ")) << ": " << whole.substr(whole.find(" "), whole.find(" ")) << endl;
                            }
                            user_list.close();
                        }
                            break;
                        case 4://update ticket
                            cout<<"Enter the Ticcket ID of the ticket you want to update: ";
                            cin>>Temp_intInput;
                            Tickets.UpdateTicket(Temp_intInput);
                            Tickets.Save_AllTickets();
                            break;
                        case 5://log out
                            Authenticated_User.Username = "";
                            Authenticated_User.id = "";
                            User_AuthLevel = 0;
                            brkLoop = true;
                            break;
                        case 6://exit program
                            cout<<"Goodbye!"<<endl;
                            brkLoop = true;
                            exit_status = 1;
                            break;
                    }
                }while(!brkLoop);
                break;
            case 3:
                //----- Manager Verification ----------|
                brkLoop = false;
                do{
                    Menu_Selection = ManagerMenu();//display the menu to the Manager
                    switch(Menu_Selection){
                        case 1://display all customers
                        {
                            ifstream user_list("Customers.txt");
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
                        case 2://display all Technician's
                        {
                            ifstream user_list("Technicians.txt");
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
                            
                        case 3://print all tickets
                            Tickets.Get_AllTickets();
                            break;
                        case 4://close a ticket
                            Tickets.UpdateStatus(Tickets.CloseTicket(), "Complete");
                            Tickets.Save_AllTickets();
                            break;
                        case 5://log out of program
                            User_AuthLevel = 0;
                            brkLoop = true;
                            break;
                        case 6://exit program
                            cout<<"Goodbye!"<<endl;
                            brkLoop = true;
                            exit_status = 1;
                            break;
                    }
                }while(!brkLoop);//repeat the entire loop untill the user wishes to exit
                break;
        }
    }while(exit_status!=1);//repeat the entire loop untill the user wish's to exit
    //if exit status is true exit loop and end program
    return 0;
}
/**
 -MainMenu Def-
 This is the menu displayed to the Customer when they first log in
 */
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
/**
 -TechMenu Def-
 This is the menu displayed to the Technicians when they first log in
 */
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
/**
 -ManagerMenu Def-
 This is the menu displayed to the Manager when they first log in
 */
int ManagerMenu(){
    int selection;
    cout<<"======= Welcome, Manager ======="<<endl;
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

struct current_login Startup_menu(){
    int selection;//the users choice
    struct current_login Login_Attempt;//Login_Attempt will contian the users login information
    cout << string( 100, '\n' );//clear display
    cout<<"======= Welcome To AutoTicketing V1.4 ========"<<endl;
    cout<<"| 1. Create a New Account                    |"<<endl;
    cout<<"| 2. Customer Login                          |"<<endl;
    cout<<"| 3. Technician Login                        |"<<endl;
    cout<<"| 4. Manager Login                           |"<<endl;
    cout<<"=============================================="<<endl;
    cout<<"Selection: ";
    cin>>selection;
    switch(selection){
        case 1://Create New User Account
            Login_Attempt = Create_New_Account();
            break;
        case 2://Customer Login
            Login_Attempt = Get_Login_information("Customer");//Send User to Login Page
            break;
        case 3://Tech Login
            Login_Attempt = Get_Login_information("Technician");//Send User to Login Page
            break;
        case 4://Manager Login
            Login_Attempt.User_AuthLevel = Manager_Login();
            break;
    }
    return Login_Attempt;
    };
    
    int Manager_Login(){
        std::string User_Password;
        int confirmation=0,User_AuthLevel = 0;
        while(confirmation==0){//run Forever untill user loggs in or exits
            cout << string( 100, '\n' );//clear display
            cout<<"======= Manager Login ======="<<endl;//display what login we are using
            cout << "Password: ";
            cin >> User_Password;//prompt for Password
            if(User_Password==Manager_Password){
                //Login Sucess
                cout<<"======= Login Acceped ======="<<endl;
                //login found and matched to user update login information for return
                User_AuthLevel = 3;
                confirmation = 1;
            }else{
                //Login Failed
                cout << "======= Login Failed =======" <<endl;
                cout<<"The Manager Password entered is incorrect"<<endl<<"[Enter 1 To Retry Any Other Key To Exit]...";
                string Retry_String;
                cin>>Retry_String;
                if(Retry_String!="1"){
                    exit(1);//If the user dosent want to retry we can exit the Program
                }
            }
        }
        return User_AuthLevel;
    }
    
    struct current_login Get_Login_information(std::string User_LoginLevel){
        struct current_login User;//varable to fill with user information
        std::string User_Username,User_Password,File_FirstName,File_Lastname,File_Username,File_Password,File_ID,Current_Line;//temp string values
        string FileName;
        std::ifstream UserList_File;//IOstream to file
        int File_Experience,confirmation = 0;;//temp Experience value,Confirmation value
        FileName="";
        if(User_LoginLevel=="Customer"){//the login type is Customer
            User.User_AuthLevel = 1;
            FileName = "Customers.txt";
        }else{//the login type is Technician
            User.User_AuthLevel = 2;
            FileName = "Technicians.txt";
        }
        while(confirmation==0){//run Forever untill user loggs in or exits
            //Start Displaying the Login Menu to the User
            cout << string( 100, '\n' );
            cout<<"======= "<<User_LoginLevel<<" Login ======="<<endl;//display what login we are using
            cout << "Username: ";
            cin >> User_Username;//prompt for Username
            cout << "Password: ";
            cin >> User_Password;//prompt for Password
            if(FileName == "Customers.txt"){
            	UserList_File.open("Customers.txt");
			}else{
				UserList_File.open("Technicians.txt");
			}
            while (std::getline(UserList_File, Current_Line))//loop thorough every line in the file
            {
                std::istringstream iss(Current_Line);
                if (!(iss >> File_FirstName >> File_Lastname >> File_Username >> File_Password >> File_ID >> File_Experience)) {
                    std::cout << "Your File is Corrupt";
                } // error
                if(User_Username==File_Username && File_Password==User_Password){//compare the login provided and the login got from the file
                    cout<<"======= Login Accepted ======="<<endl;
                    //login found and matched to user update login information for return
                    User.first_name = File_FirstName;
                    User.Last_name = File_Lastname;
                    User.Username = File_Username;
                    User.Password = File_Password;
                    User.id = File_ID;
                    User.expertise = File_Experience;
                    confirmation = 1; //user is logged in now
                }
            }//end while check if login Failed
            UserList_File.close();//close the file for use after
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
        return User;
    }
    
    struct current_login Create_New_Account(){
        //create the structure to allow us to get all information from the login session
        //pull all used usernames
        //pull what ID we are using next
        struct current_login Login_Auth;
        std::string first_name,Last_Name,password, Username, id,the_code;
        int User_AuthLevel = 0,user_type = 0,commit = 0,expertise = 0;
        while(commit != 1){
            //This is where we will create a new account
            cout << string( 100, '\n' );
            cout<<"======= New Account ======="<<endl;
            cout<<"First Name: ";
            cin>>first_name;
            cout<<"Last Name: ";
            cin>>Last_Name;
            cout<<"Login Username: ";
            cin>>Username;
            while(Check_UsernameExists(Username)){
                cout<<"============ Note =========="<<endl;
                cout<<"The Username Entered Already Exists"<<endl<<"Please Choose Another Username"<<endl;
                cout<<"=========================="<<endl;
                cout<<"Login Username: ";
                cin>>Username;
            }
            std::ostringstream Var_Temp;
            Var_Temp << GetNextUserID();
            id = Var_Temp.str();
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
            else{
                cout<<"Account type: [Technician]"<<endl;
                if(expertise==1){
                    cout<<"Expertise Level: [Beginner]"<<endl;
                }else if(expertise==2){
                    cout<<"Expertise Level: [Intermediate]"<<endl;
                }else{
                    cout<<"Expertise Level: [Expert]"<<endl;
                }
            }
            cout<<"First Name: ["<<first_name<<"]"<<endl;
            cout<<"Last Name: ["<<Last_Name<<"]"<<endl;
            cout<<"Username: ["<<Username<<"]"<<endl;
            cout<<"Password: ["<<password<<"]"<<endl;
            cout<<"Account ID: ["<<id<<"]"<<endl;
            cout<<"========================="<<endl;
            cout<<"Press 1 to Create Account"<<endl<<"Press any other key to Exit"<<endl<<"Choice: ";
            cin>>commit;
        }
        if(user_type == 1){//when the user_type is 1 we save the new account to the Customer File
            expertise=0;
            User_AuthLevel =1;
            ofstream custbook;//start file/IO
            custbook.open("Customers.txt", ios::app);//append Mode
            custbook<<first_name<<" "<<Last_Name<<" "<<Username<<" "<<password<<" "<<id<<" "<<expertise<<endl;
            custbook.close();//close the file
        }else if(user_type == 2){//when the user_type is 2 we save the new account to the Technician File
            User_AuthLevel=2;
            ofstream techbook;//start file/IO
            techbook.open("Technicians.txt", ios::app);//append Mode
            techbook<<first_name<<" "<<Last_Name<<" "<<Username<<" "<<password<<" "<<id<<" "<<expertise<<endl;
            techbook.close();//close the file
        }
        Login_Auth.User_AuthLevel = User_AuthLevel;
        Login_Auth.first_name = first_name;
        Login_Auth.Last_name = Last_Name;
        Login_Auth.Username = Username;
        Login_Auth.Password = password;
        Login_Auth.id = id;
        Login_Auth.expertise = expertise;
        return Login_Auth;//return to main
    }
    bool Check_UsernameExists(std::string UsernameToCheck){
        std::string FileName = "Customers.txt",Current_Line;
        std::string User_Username,User_Password,File_FirstName,File_Lastname,File_Username,File_Password,File_ID;//temp string values
        std::ifstream UserList_File;//IOstream to file
        int File_Experience;//temp Experience value,Confirmation value
        bool Username_exists=false;
        UserList_File.open("Customers.txt");//opens the file
        while (std::getline(UserList_File, Current_Line))//check customer id's
        {
            std::istringstream iss(Current_Line);
            if (!(iss >> File_FirstName >> File_Lastname >> File_Username >> File_Password >> File_ID >> File_Experience)) {
                std::cout << "Your File is Corrupt";
            } // error parsing
            if(UsernameToCheck==File_Username){
                Username_exists = true;
            }
        }
        UserList_File.close();
        FileName = "Technicians.txt";
        UserList_File.open("Technicians.txt");//opens the file
        while (std::getline(UserList_File, Current_Line))//check tech usernames
        {
            std::istringstream iss(Current_Line);
            if (!(iss >> File_FirstName >> File_Lastname >> File_Username >> File_Password >> File_ID >> File_Experience)) {
                std::cout << "Your File is Corrupt";
            } // error parsing
            if(UsernameToCheck==File_Username){
                Username_exists = true;
            }
        }
        UserList_File.close();
        return Username_exists;
    }
    
    int GetNextUserID(){
        int Next_Userid =0;
        std::string FileName = "Customers.txt",Current_Line;
        std::string User_Username,User_Password,File_FirstName,File_Lastname,File_Username,File_Password;//temp string values
        std::ifstream UserList_File;//IOstream to file
        int File_Experience,File_ID;//temp Experience value,Confirmation value
        UserList_File.open("Customers.txt");//opens the file
        while (std::getline(UserList_File, Current_Line))//check customer id's
        {
            std::istringstream iss(Current_Line);
            if (!(iss >> File_FirstName >> File_Lastname >> File_Username >> File_Password >> File_ID >> File_Experience)) {
                std::cout << "Your File is Corrupt";
            } // error parsing
            if(File_ID>Next_Userid){
                Next_Userid = File_ID;
            }
        }
        UserList_File.close();
        FileName = "Technicians.txt";
        UserList_File.open("Technicians.txt");//opens the file
        while (std::getline(UserList_File, Current_Line))//check tech usernames
        {
            std::istringstream iss(Current_Line);
            if (!(iss >> File_FirstName >> File_Lastname >> File_Username >> File_Password >> File_ID >> File_Experience)) {
                std::cout << "Your File is Corrupt";
            } // error parsing
            if(File_ID>Next_Userid){
                Next_Userid = File_ID;
            }
        }
        UserList_File.close();
        return Next_Userid+1;
    }
