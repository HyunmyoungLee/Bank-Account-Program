//Hyunmyoung Lee
//hyunmyoung266@gmail.com 
//BANK PROGRAM - Version 1
#include <iostream>
#define NAME_LEN 50
#define NUMBER_OF_ACCOUNT 100
using namespace std;
static int COUNT = 0;

struct Customer{
	int AccountNumber;
	char name[NAME_LEN];
	int Balance;
};


void display(){
	cout << "------Menu------" << endl;
	cout << "1.CreateAccout" << endl;
	cout << "2.Deposit     " << endl;
	cout << "3.Withdraw    " << endl;
	cout << "4.Check Balance"<< endl;
	cout << "5.Exit        " << endl;
}

void CreateAccount(struct Customer* customer){
	if(COUNT < NUMBER_OF_ACCOUNT){
		cout << "Account Number: ";
		cin >> customer[COUNT].AccountNumber;
		cout << "Name: ";
		cin >> customer[COUNT].name;
		cout << "Balance: ";
		cin >> customer[COUNT].Balance;
		cout << endl;
		COUNT++;
	}
}

void Deposit(struct Customer* customer){
	int id, deposit;
	cout << "Enter Valid Account Number: ";
	cin >> id;
	cout << endl;

	for(int i = 0 ; i < NUMBER_OF_ACCOUNT ; i++){
		if(id == customer[i].AccountNumber){
			cout << "Enter amount for deposit: ";
			cin >> deposit;
			customer[i].Balance += deposit;
		}
	}
	cout << "Invalid Account Number" << endl;
	cout << endl;
}

void Withdraw(struct Customer* customer){
	int id,withdraw;
	cout << "Enter Valid Account Number: ";
	cin >> id;
	cout << endl;

	for(int i = 0; i < NUMBER_OF_ACCOUNT ; i++){
		if(id == customer[i].AccountNumber){
			cout << "Enter amount for withdraw: ";
			cin >> withdraw;
			customer[i].Balance -= withdraw;
		}
	}
	cout << "Invalid Account Number" << endl;
	cout << endl;
}

void CheckBalance(struct Customer* customer){
		int id;
		cout<< "Enter Valid Account Number: ";
		cin >> id;
		cout << endl;

		for(int i = 0 ; i < NUMBER_OF_ACCOUNT; i++){
			if(id == customer[i].AccountNumber){
				cout << "Account Number : " << customer[i].AccountNumber << endl;
				cout << "Customer Name  : " << customer[i].name << endl;
				cout << "Account Balance: " << customer[i].Balance << endl << endl;
			}
		}
		cout << "Invalid Account Number" << endl << endl;
}


int main(){
	int option;
	struct Customer customer[NUMBER_OF_ACCOUNT];
	do{
		display();
		cout << "Choose Option: ";
		cin >> option;

		cout << endl;

		switch(option){

			case 1 :
				CreateAccount(customer);
				break;
			case 2 :
				Deposit(customer);
				break;
			case 3 :
				Withdraw(customer);
				break;
			case 4 :
				CheckBalance(customer);
				break;
			case 5 :
				cout << "End Program." << endl;
				break;

			default :
				cout << "Invalid Number" << endl;
				break;	
		}
	}while(option != 5);

	return 0;
}
