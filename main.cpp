//CS-230 Final Group Project
//Deisnged by
//-Andrew Thumma
//-Username
//-Username
//-Username
//---------- Include ----------------|
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include "User.h"
#include "Customer.h"
#include "Technician.h"
#include "Ticket.h"
#include "TicketNode.h"
#ifdef _WIN32
#include "User.cpp"
#include "Customer.cpp"
#include "Technician.cpp"
#endif

//---------- Define -----------------|
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
int Manager_Login();
//---------- End Setup ---------------|
/**
 -Main Deff-
 Main holds the linked list and login information
 the user can log into diffrent levels of accounts and create and motify tickets
 the end goal was to design this project around a ticketing system
 */
int main(int argc, char** argv){
    //---------- Varables ---------------|
    TicketList Tickets;//Tickets is the Linked List of tickets
    struct current_login Authenticated_User;//Login_Attempt will contian the users login information
    string Temp_UserInput;//used for temp user input
    int Menu_Selection;//this will contain the users choice from the main menu
    int User_AuthLevel = 0;//this int will be returned with the account level of the current user
    int exit_status = 0;//used to determin exit of loops
    int choice;
    bool brkLoop = false;//if user decides to Exit loop Will be TRUE
    //----- Login Verifacation ----------|
    Authenticated_User = Startup_menu();//Send User to login Screen and get results as structure
    //----- Customer Verifacation ----------|
    switch (Authenticated_User.User_AuthLevel) {
        case 1://when the user's AuthLevel is "Customer"
            
            
            
            
            
            Menu_Selection = MainMenu();//get the users selection from the main menu
            do{
            switch(Menu_Selection){
                case 1://Create Ticket
                    Tickets.AddTicket(Authenticated_User.id);//Call Create Ticket
                    cout<<endl;
                    break;
                case 2://get status of current ticket
                    cout<<"Enter the ID of your Ticket that you want the Status of: ";
                    cin>>Temp_UserInput;
                    Tickets.CheckStatus(Authenticated_User.id, Temp_UserInput);
                    break;
                case 3://get all current tickets
                    Tickets.MyTickets(Authenticated_User.id);
                    break;
                case 4://get invoice of single ticket
                    cout<<"Enter the ID of the ticket that you want the invoice of: ";
                    cin>>Temp_UserInput;
                    Tickets.PrintInvoice(Authenticated_User.id, Temp_UserInput);
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
            
            
            break;
        case 2:
            break;
        case 3:
            break;
    }
        //----- Technician Verifacation ----------|
        if (User_AuthLevel == 2){ //users Auth Level is technician
            bool brkLoop = false; //used to tell if user wants to exit loop
            do{
                string TicketID_Input;//the ticket the user wants to search for
                int choice;//the seccondary menu selection
                string status;
                Menu_Selection = TechMenu();//display the technician menu to the user
                switch(Menu_Selection){
                    case 1://claim a ticket
                        cout<<"Enter ticket ID of the ticket you want to claim: ";
                        cin>>TicketID_Input;
                        Tickets.ClaimTicket(TicketID_Input, technician.Username) ;
                        break;
                    case 2://update a ticket
                        cout<<"Enter the ticket id of the ticket you want to update the status of: ";
                        cin>>TicketID_Input;
                        cout<<"Enter a 1 for In-Progress or a 2 for Awaiting-Finalization: ";
                        cin>>choice;
                        if(choice == 1){
                            status = "In-Progress";
                        }if(choice == 2){
                            status = "Awaiting-Finalization";
                        }
                        Tickets.UpdateStatus(TicketID_Input, status);
                        break;
                    case 3://view all current technician's
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
                    }
                        break;
                    case 4://update ticket
                        cout<<"Enter the Ticcket ID of the ticket you want to update: ";
                        cin>>TicketID_Input;
                        Tickets.UpdateTicket(TicketID_Input);
                        break;
                    case 5://log out of program
                        technician.Username = "";
                        technician.id = "";
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
        }
        //----- Manager Verifacation ----------|
        if (User_AuthLevel == 3){//auth level is Manager
            bool brkLoop = false;
            do{
                string TicketID_Input;//the temp ticket ID
                Menu_Selection = ManagerMenu();//display the menu to the Manager
                switch(Menu_Selection){
                    case 1://display all customers
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
                    case 2://display all Technician's
                        
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
                        
                    case 3://print all tickets
                        Tickets.PrintTickets();
                        break;
                    case 4:
                        cout<<"Enter the Ticket ID of the ticket you wish to close: ";
                        cin>>TicketID_Input;
                        Tickets.UpdateStatus(TicketID_Input, "Complete");
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
            }while(!brkLoop);//repeat the entire loop untill the user wish's to exit
        }
//if exit status is true exit loop and end program
    return 0;
}
/**
 -MainMenu Deff-
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
 -TechMenu Deff-
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
 -ManagerMenu Deff-
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
}

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
    std::string User_Username,User_Password,File_FirstName,File_Lastname,File_Username,File_Password,File_ID,FileName,Current_Line;//temp string values
    std::ifstream UserList_File;//IOstream to file
    int File_Experience,confirmation = 0;;//temp Experience value,Confirmation value
    
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
        UserList_File.open(FileName);//opens the file
        while (std::getline(UserList_File, Current_Line))//loop thorough every line in the file
        {
            std::istringstream iss(Current_Line);
            if (!(iss >> File_FirstName >> File_Lastname >> File_Username >> File_Password >> File_ID >> File_Experience)) {
                std::cout << "Your File is Corrupt";
            } // error
            if(User_Username==File_Username && File_Password==User_Password){//compare the login provided and the login got from the file
                cout<<"======= Login Acceped ======="<<endl;
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
            struct current_login Login_Auth;
            std::string first_name,Last_Name,password, Username, id,the_code;
            int User_AuthLevel = 0,user_type = 0,commit = 0,expertise = 0;
            while(commit != 1){
                //This is where we will create a new account
                //setup the display to look nice :)
                cout << string( 100, '\n' );
                cout<<"======= New Account ======="<<endl;
                cout<<"First Name: ";
                cin>>first_name;
                cout<<"Last Name: ";
                cin>>Last_Name;
                cout<<"Login Username: ";
                cin>>Username;
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
    
    
    
    
        /**
         -login Deff-
         Login will present the user with a Menu allowing them to pick what kind of account they want to log into
         this method will also allow new users to be created
         this method will return a current_login structure containing all of the logged in information
         */
        struct current_login login() {
            //create the structure to allow us to get all information from the login session
            struct current_login Login_Auth;
            //login_Auth will contain all the diffrent things we get from the user login
            int User_AuthLevel = 0;
            int choice, user_type = 0;
            int commit = 0;
            int expertise = 0;
            string first_name,Last_Name,password, Username, id,the_code;
            //when the program first loads display starting menu
            cout << string( 100, '\n' );//clear display
            cout<<"======= Welcome To AutoTicketing V1.4 ========"<<endl;
            cout<<"| 1. Create a New Account                    |"<<endl;
            cout<<"| 2. Customer Login                          |"<<endl;
            cout<<"| 3. Technician Login                        |"<<endl;
            cout<<"| 4. Manager Login                           |"<<endl;
            cout<<"=============================================="<<endl;
            cout<<"Selection: ";
            cin>>choice;
            switch(choice){
                case 1://Create New User Account
                {
                    while(commit != 1){
                        //This is where we will create a new account
                        //setup the display to look nice :)
                        cout << string( 100, '\n' );
                        cout<<"======= New Account ======="<<endl;
                        cout<<"First Name: ";
                        cin>>first_name;
                        cout<<"Last Name: ";
                        cin>>Last_Name;
                        cout<<"Login Username: ";
                        cin>>Username;
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
                    break;
                }
                case 2:
                {//Customer Login
                    struct current_login TempLogin = Get_Login_information("Customer");//Send User to Login Page
                    //when we get back a good login we will fill all the information requested
                    User_AuthLevel = TempLogin.User_AuthLevel ;
                    first_name = TempLogin.first_name;
                    Last_Name = TempLogin.Last_name;
                    Username = TempLogin.Username;
                    password = TempLogin.Password;
                    id = TempLogin.id;
                    expertise = TempLogin.expertise;
                    break;
                }
                case 3: //technician login
                {
                    string temp_user, temp_pass, line;
                    int confirmation = 0;
                    while(confirmation == 0){
                        //setup the display to look nice :)
                        cout << string( 100, '\n' );
                        cout<<"======= Technician Login ======="<<endl;
                        cout << "Username: ";
                        cin >> temp_user;
                        cout << "Password: ";
                        cin >> temp_pass;
                        ifstream credentials;
                        size_t pos;
                        while(credentials.good()){
                            credentials.open("Technicians.txt");
                            getline(credentials, line);
                            pos=line.find(temp_user);
                            if(pos!=string::npos){
                                pos=line.find(temp_pass);
                                if(pos!=string::npos){
                                    string temp_name = line;//copy the line
                                    cout<<"======= Login Acceped ======="<<endl;
                                    cout << "Welcome, " << temp_name.substr(0, temp_name.find(" ")) << "!" <<endl;//get the username from the line and print it to the user as the welcome message
                                    User_AuthLevel = 2;//set globsl verifaction to customer
                                    confirmation = 1;//set the global value for loggin in to 1
                                    //first we set the global Username to the username entered becuase we know that the usename worked
                                    Username = temp_user;
                                    //next we copy the string so we can motify it
                                    string tempstring = line;
                                    string temp2 =line;
                                    //first erase the username from the string
                                    tempstring.erase(0, temp_user.length());
                                    //next erase the password from the string
                                    tempstring.erase(tempstring.find(temp_pass),tempstring.length());
                                    //now we can remove all spaces from it
                                    for(int i=0; i<tempstring.length(); i++)
                                        if(tempstring[i] == ' ') tempstring.erase(i,1);
                                    //finaly we save the user id to the global value so it can be passed on
                                    id = tempstring;
                                    //using sscaf to parse the file due to c having more power over strings
                                    char fname[Name_Limit],lname[Name_Limit],uname[Name_Limit],pass[Name_Limit],tid[Name_Limit];
                                    sscanf(tempstring.c_str(), "%s %s %s %s %s %d",&fname,&lname,&uname,&pass,&tid,&expertise);
                                    first_name=fname;
                                    Last_Name = lname;
                                    Username = uname;
                                    password = pass;
                                    id = tid;
                                    cout<<first_name<<Last_Name<<Username<<password<<id<<expertise;
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
                        User_AuthLevel = 3;
                        break;
                    } else{
                        cout <<"....You're not the Chief...\n";
                        User_AuthLevel = 0;
                        break;
                    }
                }
                default: cout << choice << " is an invalid Menu_Selectionion!" << endl;
            }
            //log the new user in and pass them back to main
            Login_Auth.User_AuthLevel = User_AuthLevel;
            Login_Auth.first_name = first_name;
            Login_Auth.Last_name = Last_Name;
            Login_Auth.Username = Username;
            Login_Auth.Password = password;
            Login_Auth.id = id;
            Login_Auth.expertise = expertise;
            return Login_Auth;//return to main
        }
