#pragma once
#include<iostream>
#include<string>
#include"clsScreen.h";
#include"clsBankClint.h";
#include"clsInputValidate.h";
#include"clsUser.h";
#include<iomanip>
using namespace std;

class clsAddNewClintScreen:protected clsScreen
{
private:

	static void _ReadClintInfo(clsBankclint& clint1) {
		cout << "\nEnter Frist Name :";
		clint1.FristName = clsInputValidate::ReadString();
		cout << "\nEnter Last Name :";
		clint1.LastName = clsInputValidate::ReadString();
		cout << "\nEnter Phon Number :";
		clint1.Phon = clsInputValidate::ReadString();
		cout << "\nEnter Email  :";
		clint1.Email = clsInputValidate::ReadString();
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
	static void ShowAddNewClint() {

		if (!ChackAccessRight(clsUser::enpermision::pAddNewClint)) {
			return;
		}
		_DrawScreenHeader("\tAdd New Clint Screen");

		string AccountNumber = "";
		cout << "Plase Enter Account Number :";
		AccountNumber = clsInputValidate::ReadString();

		while (clsBankclint::IsclaintExist(AccountNumber)) {
			cout << "\nAccount Number Is Already Used, Choose another one :";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankclint NewClint = clsBankclint::GetAddNewClinttoObject(AccountNumber);

		_ReadClintInfo(NewClint);
		clsBankclint::enSaveResult SaveResult;

		SaveResult = NewClint.Save();
		switch (SaveResult) {
		case clsBankclint::enSaveResult::svSucceeded: {
			cout << "\n Account Updated Successfully :-)\n";
			_PrintClint(NewClint);
			break;
		}
		case clsBankclint::enSaveResult::svfailEmptyobject:
		{
			cout << "\nError account was not saved bacause it,s Empty\n";
			break;
		}
		case clsBankclint::enSaveResult::svFaildAccountNumberExists:
		{
			cout << "\nError account was not saved bacause it,s Empty\n";
			break;
		}
		}

	}


};

