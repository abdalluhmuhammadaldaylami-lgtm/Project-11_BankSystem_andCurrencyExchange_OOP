#pragma once
#include<iostream>
#include<string>
#include"clsScreen.h";
#include"clsBankClint.h";
#include"clsInputValidate.h";
#include<iomanip>
using namespace std;


class clsUpdateClintScreen:protected clsScreen
{
private:

	static void _ReadClintInfo(clsBankclint& clint1) {
		cout << "\nEnter Frist Name :";
		clint1.FristName = clsInputValidate::ReadString();
		cout << "\nEnter Last Name :";
		clint1.LastName = clsInputValidate::ReadString();
		cout << "\nEnter Email  :";
		clint1.Email = clsInputValidate::ReadString();
		cout << "\nEnter Phon Number :";
		clint1.Phon = clsInputValidate::ReadString();
		cout << "\nEnter Pincode :";
		clint1.Pincode = clsInputValidate::ReadString();
		cout << "\nEnter Account Balance :";
		clint1.AccountBalance = clsInputValidate::ReadFloatNumber();
	}

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

	static void ShowUpdateClientScreen() {

		if (!ChackAccessRight(clsUser::enpermision::pUpdateClint)) {
			return;
		}

		_DrawScreenHeader("\tUpdate Clint Screen");
		string AccountNumber = "";

		cout << "\nplease Enter Client Account Number :";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankclint::IsclaintExist(AccountNumber)) {
			cout << "\nAccount Number Is not found ,choose another on :";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankclint clint1 = clsBankclint::Find(AccountNumber);
		_PrintClint(clint1);

		cout << " Update  Client Info :\n";
		cout << "--------------------------------------\n";

		_ReadClintInfo(clint1);
		clsBankclint::enSaveResult SaveResult;

		SaveResult = clint1.Save();
		switch (SaveResult) {
		case clsBankclint::enSaveResult::svSucceeded: {
			cout << "\n Account Updated Successfully :-)\n";
			_PrintClint(clint1);
			break;
		}
		case clsBankclint::enSaveResult::svfailEmptyobject:
		{
			cout << "\nError account was not saved bacause it,s Empty\n";
			break;
		}
		}
	}
};

