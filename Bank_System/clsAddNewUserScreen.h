#pragma once
#include<iostream>
#include<string>
#include"clsScreen.h";
#include"clsUser.h";
#include"clsInputValidate.h";
#include<iomanip>
using namespace std;

class clsAddNewUserScreen:protected clsScreen
{
private:

	static void _ReadInfoUser(clsUser& user) {
		cout << "\nEnter Frist Name :";
		user.FristName = clsInputValidate::ReadString();
		cout << "\nEnter Last Name :";
		user.LastName = clsInputValidate::ReadString();
		cout << "\nEnter Email  :";
		user.Email = clsInputValidate::ReadString();
		cout << "\nEnter Phon Number :";
		user.Phon = clsInputValidate::ReadString();
		cout << "\nEnter Password :";
		user.Password = clsInputValidate::ReadString();
		cout << "\nEnter Permissions :";
		user.Permissions = _ReadPermissionsToSet();
	}

	static int _ReadPermissionsToSet() {
		int Permissions = 0;
		char enswer = 'n';

		cout << "Do you want to give full permissions.? Y/N.? ";
		cin >> enswer;
		if (enswer == 'Y' || enswer == 'y') {
			return -1;
		}
		cout << "\nDo you want to give access to :\n";

		cout << "\nShow Clint List.? Y/N.? ";
		cin >> enswer;
		if (enswer == 'Y' || enswer == 'y') {
			 Permissions += clsUser::enpermision::pListClints;
		}

		cout << "Add New Clint.? Y/N.? ";
		cin >> enswer;
		if (enswer == 'Y' || enswer == 'y') {
		    Permissions += clsUser::enpermision::pAddNewClint;
		}

		cout << "Delete Clint.? Y/N.? ";
		cin >> enswer;
		if (enswer == 'Y' || enswer == 'y') {
			 Permissions += clsUser::enpermision::pDeleteClint;
		}

		cout << "Update Clint.? Y/N.? ";
		cin >> enswer;
		if (enswer == 'Y' || enswer == 'y') {
			 Permissions += clsUser::enpermision::pUpdateClint;
		}

		cout << "Find Clint.? Y/N.? ";
		cin >> enswer;
		if (enswer == 'Y' || enswer == 'y') {
			 Permissions += clsUser::enpermision::pFindClint;
		}

		cout << "Transactions.? Y/N.? ";
		cin >> enswer;
		if (enswer == 'Y' || enswer == 'y') {
			 Permissions += clsUser::enpermision::pTranaction;
		}

		cout << "Manage Users.? Y/N.? ";
		cin >> enswer;
		if (enswer == 'Y' || enswer == 'y') {
			 Permissions += clsUser::enpermision::pManageUser;
		}

		cout << "Show Login Registers.? Y/N.? ";
		cin >> enswer;
		if (enswer == 'Y' || enswer == 'y') {
			Permissions += clsUser::enpermision::pLoginRegister;
		}

		cout << "Show Currencies Exchange.? Y/N.? ";
		cin >> enswer;
		if (enswer == 'Y' || enswer == 'y') {
			Permissions += clsUser::enpermision::pCurrenciesExchange;
		}

		return Permissions;
	}

	static void _PrintUser(clsUser User) {
		cout << "\n\tUser Card:";
		cout << "\n_______________________________";
		cout << "\n Frist Name    :" << User.FristName;
		cout << "\n Last Name     :" << User.LastName;
		cout << "\n Full Name     :" << User.FullName();
		cout << "\n Email         :" << User.Email;
		cout << "\n Phon Number   :" << User.Phon;
		cout << "\n UserName      :" << User.UserName;
		cout << "\n Password      :" << User.Password;
		cout << "\n Permissions   :" << User.Permissions;
		cout << "\n_______________________________\n";
	}

public:

	static void ShowAddNewUserScreen() {
		_DrawScreenHeader("\tAdd New User Screen");

		string UserName = "";
		cout << "please Enter UserName: ";
		UserName= clsInputValidate::ReadString();

		while (clsUser::IsUserExist(UserName)) {
			cout << "\nAccount Number Is Already Used, Choose another one :";
			UserName = clsInputValidate::ReadString();
		}

		clsUser NewUser = clsUser::GetAddNewUsertoObject(UserName);

		_ReadInfoUser(NewUser);

		clsUser::enSaveResult SaveResult;
		SaveResult = NewUser.Save();

		switch (SaveResult) {
		case clsUser::enSaveResult::svSucceeded: {
			cout << "\n Account Updated Successfully :-)\n";
			_PrintUser(NewUser);
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

 