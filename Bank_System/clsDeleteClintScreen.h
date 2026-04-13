#pragma once
#include<iostream>
#include<string>
#include"clsScreen.h";
#include"clsBankClint.h";
#include"clsInputValidate.h";
//#include"clsUser.h";
#include<iomanip>
using namespace std;

class clsDeleteClintScreen:protected clsScreen
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
	static void ShowDeleteClintScreen() {

		if (!ChackAccessRight(clsUser::enpermision::pDeleteClint)) {
			return;
		}
		_DrawScreenHeader("\tDelete Clint Screen");

		string AccountNumber = "";

		cout << "\nplease Enter Client Account Number :";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankclint::IsclaintExist(AccountNumber)) {
			cout << "\nAccount Number Is not found ,choose another on :";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankclint Clint = clsBankclint::Find(AccountNumber);
		_PrintClint(Clint);

		cout << "\nAre you sure you want to delete this clint Y/N :";
		char Answer;
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {
			if (Clint.Delete()) {
				cout << "\n Clint Delete Successfully :-)";
				_PrintClint(Clint);
			}
			else {
				cout << "\nError Clint Was not Deleted\n";
			}
		}
	}


};

