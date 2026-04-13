#pragma once
#include<iostream>
#include<string>
#include"clsScreen.h";
#include"clsBankClint.h";
#include"clsInputValidate.h";
#include<iomanip>
using namespace std;


class clsWithdrawScreen:protected clsScreen
{

private:


	static void _PrintClint(clsBankclint Clint) {
		cout << "\n\tClaint Card:";
		cout << "\n_______________________________";
		cout << "\n Frist Name     :" << Clint.FristName;
		cout << "\n Last Name      :" << Clint.LastName;
		cout << "\n Email          :" << Clint.Email;
		cout << "\n Phon Number    :" << Clint.Phon;
		cout << "\n Acc. Number    :" << Clint.AccountNumber();
		cout << "\n Pincode        :" << Clint.Pincode;
		cout << "\n Acc. Balance   :" << Clint.AccountBalance;
		cout << "\n_______________________________\n";
	}


public:

	static void ShowWithdrawScreen() {

		_DrawScreenHeader("\t Withdraw Screen");
		string AccountNumber = "";

		cout << "\nplease Enter Client Account Number :"; 
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankclint::IsclaintExist(AccountNumber)) {
			cout << "\nClint With [" << AccountNumber << "] dose not found..!\n";

			cout << "\nplease Enter Client Account Number :";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankclint clint1 = clsBankclint::Find(AccountNumber);
		_PrintClint(clint1);

		double Amount = 0;
		cout << "Please enter Withdraw amount.? ";
		Amount = clsInputValidate::ReadDblNumber();

		if (clint1.Withdraw(Amount)) {
			char ch;
			cout << "Are you sure you want to perform this transaction [Y/N]:";
			cin >> ch;


			if (ch == 'y' || ch == 'Y') {
				cout << "\nAmount Withdraw Successfuly :-)\n";
				cout << "New Balance is :" << clint1.AccountBalance << endl;
			}
			else
			{
				cout << "Operation was Cancelled.\n";
			}
		}
		else
		{
			cout << "\n Cannot Withdraw, Insuffecient Balance!\n";
			cout << " Amout to withdraw is :" << Amount << endl;
			cout << " Your Balance is :" << clint1.AccountBalance << endl;
		}
	}

};

