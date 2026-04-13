#pragma once
#include<iostream>
#include"Global.h";
#include"clsDate.h";
using namespace std;

class clsScreen
{

protected:
	static void _DrawScreenHeader(string Title, string SubTitle = "") {
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << "\t\t\t\t" << Title ;
		if (SubTitle != "") {
			cout << "\n\t\t\t\t " << SubTitle;
		}
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

		cout << " User :" << CurrentUser.UserName;
		cout << " \t\t\t\t\t\t\t\t\tDate :" << clsDate::DateToString(clsDate())<<"\n\n";
	}

	static bool ChackAccessRight(clsUser::enpermision permission) {
		if (!CurrentUser.CheckAccessPermission(permission)) {
			cout << "\n\n_____________________________________________________________________\n\n";
			cout << "\t\t Access Denied! Contact your Admin..!";
			cout << "\n\n_____________________________________________________________________\n";
			return false;
		}
		else
		{
			return true;
		}
	}
};

