#pragma once
#include<iostream>
#include<string>
#include"clsScreen.h";
#include"clsBankClint.h";
#include"clsInputValidate.h";
#include<iomanip>
using namespace std;
 
class clsTotalBalancesScreen:protected clsScreen
{
private:
	static void _PrintClintsRecordLine(clsBankclint clint) {
		cout << "| " << left << setw(18) << clint.AccountNumber();
		cout << "| " << left << setw(30) << clint.FristName;
     	cout << "| " << left << setw(18) << clint.AccountBalance;
	}


public:

	static void ShowTotalBalancesScreen() {
	/*	if (!ChackAccessRight(clsUser::enpermision::)) {
			return;
		}*/

		vector<clsBankclint>vclints = clsBankclint::GetClintList();

		string Title = "\tBalances List Screen";
		string SubTitle = "\t(" + to_string(vclints.size()) + ") Clints";
		_DrawScreenHeader(Title, SubTitle);

		
		cout << "---------------------------------------------------------------------------\n";
		cout << "| " << left << setw(18) << "Account Number";
		cout << "| " << left << setw(30) << "Clint Name";
		cout << "| " << left << setw(18) << "Balance";
		cout << "\n---------------------------------------------------------------------------\n";

		double TotalBalances = clsBankclint::GetTotalBalances();
		if (vclints.size() == 0) {
			cout << "\n\t\t\t\tNo Clints Available In the System!";
		}
		else {
			for (clsBankclint clint : vclints) {
				_PrintClintsRecordLine(clint);
				cout << endl;
			}
		}
		cout << "---------------------------------------------------------------------------\n";
		cout << "\t\tTotal Balances is = " << TotalBalances << endl;
		cout << "---------------------------------------------------------------------------\n";
	}
};

