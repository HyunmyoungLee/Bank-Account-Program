#include <iostream>
#include "AccountHandler.h"
using namespace std;

int main(){
	AccountHandler Manager;
	
	int option;
	do{
		Manager.display();
		cout << "Choose Option: ";
		cin >> option;

		cout << endl;

		switch(option){

			case 1 :
				Manager.CreateAccount();
				break;
			case 2 :
				Manager.Deposit();
				break;
			case 3 :
				Manager.Withdraw();
				break;
			case 4 :
				Manager.CheckBalance();
				break;
			case 5 :
				Manager.ShowAllAccount();
				break;
			case 6 : 
				cout << "End Program." << endl;
				break;

			default :
				cout << "Invalid Number" << endl;
				break;	
		}
	}while(option != 6);

	return 0;
}
