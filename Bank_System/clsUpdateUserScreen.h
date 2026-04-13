#pragma once
#include<iostream>
#include<string>
#include"clsScreen.h";
#include"clsUser.h";
#include"clsInputValidate.h";
#include<iomanip>
using namespace std;

class clsUpdateUserScreen :protected clsScreen
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

	static void ShowUpdateUserScreen() {

		_DrawScreenHeader("\tUpdate User Screen");

		string UserName = "";
		cout << "please Enter UserName: ";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName)) {
			cout << "\nUserName Is Already Used, Choose another one :";
			UserName = clsInputValidate::ReadString();
		}
		clsUser User = clsUser::Find(UserName);
		_PrintUser(User);

		cout << " Update  User Info :\n";
		cout << "--------------------------------------\n";

		char ch = 'n';
		cout << "\nAre you sure you want to Update this User Y/N :";
		cin >> ch;

		if (ch == 'y' || ch == 'Y') {
			_ReadInfoUser(User);

			clsUser::enSaveResult SaveResult;
			SaveResult = User.Save();

			switch (SaveResult) {
			case clsUser::enSaveResult::svSucceeded:
			{
				cout << "\n UserName Updated Successfully :-)\n";
				_PrintUser(User);
				break;
			}
			case clsUser::enSaveResult::svfailEmptyobject:
				cout << "\nError User was not saved bacause it,s Empty\n";
				break;
			}
		}

	}

};

