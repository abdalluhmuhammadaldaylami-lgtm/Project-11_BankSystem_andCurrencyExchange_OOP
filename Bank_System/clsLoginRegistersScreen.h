#pragma once
#include<iostream>
#include<string>
#include"clsScreen.h";
#include"clsUser.h";
#include"clsInputValidate.h";
#include<iomanip>

using namespace std;

class clsLoginRegistersScreen:protected clsScreen
{
private:

	static void PrintUsersLoginRegister(clsUser::stLOginRegisterRecord U) {
		cout << "| " << left << setw(26) << U.Time;
		cout << "| " << left << setw(18) << U.UserName;
		cout << "| " << left << setw(15) << U.Password;
		cout << "| " << left << setw(10) << U.Permission;
	}

public:

	static void ShowUsersLoginRegister() {
		if (!ChackAccessRight(clsUser::enpermision::pLoginRegister)) {
			return;
		}

		vector<clsUser::stLOginRegisterRecord>vLoginRegisterRecord = clsUser::GitLoginRegister();

		string Title = "\t Login Register List Screen";
		string SubTitle = "\t(" + to_string(vLoginRegisterRecord.size()) + ") Record(s).";
		_DrawScreenHeader(Title, SubTitle);

		cout << "------------------------------------------------------------------~---------------\n";
		cout << "| " << left << setw(26) << "Date/ Time";
		cout << "| " << left << setw(18) << "User Name";
		cout << "| " << left << setw(15) << "Password";
		cout << "| " << left << setw(10) << "Permission";
		cout << "\n--------------------------------------------------------------------------------\n";

		if (vLoginRegisterRecord.size() == 0) {
			cout << "\n\t\t\t\tNo Logins Available In the System!";
		}
		else {
			for (clsUser::stLOginRegisterRecord Record : vLoginRegisterRecord) {
				PrintUsersLoginRegister(Record);
				cout << endl;
			}
		}
		cout << "\n--------------------------------------------------------------------------------\n";

	}

};

