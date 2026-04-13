#pragma once
#include<iostream>
#include<string>
#include"clsScreen.h";
#include"clsBankClint.h";
#include"clsInputValidate.h";
#include"Global.h";
#include<iomanip>
using namespace std;

class clsTransfarScreen:protected clsScreen
{
private:

	static string ReadAccountNumber() {
		string AccountNumber = "";

		cout << "\nplease Enter Account Number to Transfer From :";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankclint::IsclaintExist(AccountNumber)) {
			cout << "\nClint With [" << AccountNumber << "] dose not found..!\n";

			cout << "\nplease Enter Account Number to Transfer From :";
			AccountNumber = clsInputValidate::ReadString();
		}
		return AccountNumber;
	}

	static float _ReadAmount(clsBankclint SourceClint) {
		float amount;
		cout << "Enter Trancfar Amount.? ";
		amount = clsInputValidate::ReadFloatNumber();

		if (amount > SourceClint.AccountBalance) {
			cout << "Amount Exceed the available Balance ,Enter Another Amount.? ";
			amount = clsInputValidate::ReadFloatNumber();
		}
		return amount;
	}

	static void _PrintClint(clsBankclint Clint) {
		cout << "\n\tClaint Card:";
		cout << "\n_______________________________";
		cout << "\n Full Name     :" << Clint.FullName();
		cout << "\n Acc. Number   :" << Clint.AccountNumber();
		cout << "\n Acc. Balance  :" << Clint.AccountBalance;
		cout << "\n_______________________________\n";
	}



public:

	static void ShowTransfarScreen() {
		_DrawScreenHeader("Transfar Screen");

		clsBankclint SourceClint= clsBankclint::Find(ReadAccountNumber());
		_PrintClint(SourceClint);

		clsBankclint DestinationClint = clsBankclint::Find(ReadAccountNumber());
		_PrintClint(DestinationClint);


		double TransferAmount = _ReadAmount(SourceClint);
	
		char ch;
		cout << "\nAre you sure you want to perform this transaction [Y/N]:";
		cin >> ch;

		if (ch == 'y' || ch == 'Y') {
			if (SourceClint.Trancfar(TransferAmount, DestinationClint,CurrentUser.UserName)) {
				cout << "\n\nTransfer done Successfully\n";
			}
			else
			{
				cout << "Transfar Faild\n\n";
			}

		}
		_PrintClint(SourceClint);
		_PrintClint(DestinationClint);

		
	}


};

