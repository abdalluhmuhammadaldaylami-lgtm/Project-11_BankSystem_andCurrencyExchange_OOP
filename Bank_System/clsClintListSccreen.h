#pragma once
#include<iostream>
#include<string>
#include"clsScreen.h";
#include"clsBankClint.h";
#include<iomanip>
using namespace std;


class clsClintListSccreen:protected clsScreen
{
private:

	static void PrintClintsRecordLine(clsBankclint clint) {
		cout << "| " << left << setw(14) << clint.AccountNumber();
		cout << "| " << left << setw(18) << clint.FullName();
		cout << "| " << left << setw(12) << clint.Phon;
		cout << "| " << left << setw(20) << clint.Email;
		cout << "| " << left << setw(10) << clint.Pincode;
		cout << "| " << left << setw(12) << clint.AccountBalance;
	}

public:

    static void ShowClintList() {
		if (!ChackAccessRight(clsUser::enpermision::pListClints)) {
			return;
		}

		vector<clsBankclint>vclints = clsBankclint::GetClintList();

		string Title = "\tClint List Screen";
		string SubTitle = "\t(" + to_string(vclints.size()) + ") Clints\n";
		_DrawScreenHeader(Title, SubTitle);

		//cout << "\n\t\t\t\t\tClint List (" << vclints.size() << ")Clint (s)\n";
		cout << "------------------------------------------------------------------------------------------------\n";
		cout << "| " << left << setw(14) << "Account Number";
		cout << "| " << left << setw(18) << "Clint Name";
		cout << "| " << left << setw(12) << "Phon";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(12) << "Balance";
		cout << "\n------------------------------------------------------------------------------------------------\n";

		if (vclints.size() == 0) {
			cout << "\n\t\t\t\tNo Clints Available In the System!";
		}
		else {
			for (clsBankclint clint : vclints) {
				PrintClintsRecordLine(clint);
				cout << endl;
			}
		}
		cout << "\n------------------------------------------------------------------------------------------------\n";
	
	}


};

