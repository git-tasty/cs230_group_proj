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
      case 2: verification = 1;
        break;
      case 3: verification = 2;
        break;
      default: cout << choice << " is an invalid option!" << endl;
    }
   return verification;
}



int main(int argc, char** argv){
    int opt;
    int verification = 0;
    int exit_status = 0;
    while (exit_status != 1){
    while(verification == 0){
        verification = login();
    }

    if (verification == 1){
        do{
            opt = MainMenu();
            switch(opt){
                case 1:
                  break;
                case 2:
                  break;
                case 3:
                  break;
                case 4:
                  break;
                case 5: verification = 0;
                  break;
                case 6: cout<<"Goodbye!"<<endl;
            }
        }while(opt!=6);
    }

    if (verification == 2){
      bool brkLoop = false;
        do{
            opt = TechMenu();
            switch(opt){
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
    else{
        cout<<"Somehow you broke our program"<<endl;
        exit(EXIT_FAILURE);
    }
  }
    return 0;
}
