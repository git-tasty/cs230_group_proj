#include <iostream>
#include <cstdlib>

using namespace std;

int menu(){
    int choice;
    cout << "Option 1 \n"
         << "Option 2 \n"
         << "Option 3 \n"
         << "Etc. \n"
         << "Etc. \n"
         << "Sub-Menu \n"
         << "Etc. \n"
         << "Etc. \n"
         << "9. Exit \n"
         <<"Enter your choice: ";
    cin >> choice;
    return choice;
}

int sub_menu() {
	int choice;
  cout <<"O1.\n"
  		 <<"O2.\n"
       <<"O3.\n"
       <<"Return\n"
       <<"Enter your choice: ";
	cin >> choice;  
	return choice;
}


int main(){
    int option, option2;
    do {
			option = menu();
      switch(option){
      	case 1:
        	break;
        case 2:
        	break;
        case 3:
        	break;
        case 4:
        	break;
      	case 5:
        	break;
        case 6: do {
        		  option2 = sub_menu();
                  switch(option2){
                  	case 1:
                    	break;
                    case 2:
                    	break;
                    case 3:
                    	break;
                    case 4:
                    	break;
                    default: cout << option2 << " is an invalid option" << endl;
                  }
        				}while(option2 != 4);
        	break;
        case 7:
        	break;
        case 8:
        	break;
        case 9: cout << "Goodbye!" << endl;
        	break;
        default: cout << option << " is an invalid option!" << endl;
      }
    }while(option != 9);
    return 0;
}