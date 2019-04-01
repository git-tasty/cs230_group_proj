#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;


int MainMenu(){
    int selection;
    cout<<"========= Main Menu ========="<<endl;
    cout<<"| 1. Create New Ticket.     |"<<endl;
    cout<<"| 2. View Ticket Status.    |"<<endl;
    cout<<"| 3. View All Your Tickets. |"<<endl;
    cout<<"| 4. Remove Your Ticket.    |"<<endl;
    cout<<"| 5. Log In as Employee.    |"<<endl;
    cout<<"| 6. Exit Program.          |"<<endl;
    cout<<"============================="<<endl;
    cout<<"Enter a Selection: ";
    cin>>selection;
    return selection;
}

int TechMenu(){
    int selection;
    cout<<"========= Main Menu ========="<<endl;
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

int login() {
    int verification = 0;
    int choice, user_type;
    int commit = 0;
    string password, name, id;
    cout<<"1. Create an Account"<<endl;
    cout<<"2. Login as a Customer"<<endl;
    cout<<"3. Login as a Technician"<<endl;
    cout<<"Enter a choice: ";
    cin>>choice;
       
    if(choice == 1){
            while(commit != 1){
            cout<<"Enter your first name: ";
            cin>>name;
            cout<<"Enter a user id that you'd like to use: ";
            cin>>id;
            cout<<"Enter a password: ";
            cin>>password;
            cout<<"Are you a (1.)Customer or (2.)Technician: ";
            cin>>user_type;
            cout<<"Press 1 to commit this data, otherwise press any other number: ";
            cin>>commit;
        }
        ofstream userbook;
        userbook.open ("userlist.txt");
        userbook<<user_type<<" "<<name<<" "<<id<<" "<<password<<" "<<endl;
        userbook.close();
        verification = user_type;
        break;
    }
    if(choice == 2){
    
    
    verification = 1;
    }
    if(choice == 3){
    
    
    verification = 2;
    }
    else{
    cout<<choice<<"is an invalid choice!"<<endl;
    }
   return verification;
}



int main(int argc, char** argv){
    int opt;
    int verification = 0;
    
    while(verification == 0){
        verification = login();
    }
    
    if (verification == 1){
        do{
            opt = MainMenu();
            switch(opt){
            
                case 5: verification = 2;
                    return;
                case 6: cout<<"Goodbye!"<<endl;
            }
        }while(opt!=6);
    }
    
    if (verification == 2){
        do{
            opt = TechMenu();
            switch(opt){
            
                case 6: cout<<"Goodbye!"<<endl;
            }
        }while(opt!=6);
    }
    else{
        cout<<"Somehow you broke our program"<<endl;
        exit(EXIT_FAILURE);
    }
    
    return 0;
}