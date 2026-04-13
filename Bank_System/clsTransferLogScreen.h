#pragma once
#include<iostream>
#include<string>
#include"clsScreen.h";
#include"clsBankClint.h";
#include"clsInputValidate.h";
#include"Global.h";
#include<iomanip>
using namespace std;

class clsTransferLogScreen:protected clsScreen
{

private:

	static void PrintTransferLogRecordLine(clsBankclint::stTransferLog U) {
		cout << "| " << left << setw(24) << U.DateTime;
		cout << "| " << left << setw(10) << U.SoursAccountNumber;
		cout << "| " << left << setw(10) << U.DestinationAccountNumber;
		cout << "| " << left << setw(10) << U.Amount;
		cout << "| " << left << setw(12) << U.soursBalance;
		cout << "| " << left << setw(12) << U.DestinationBalance;
		cout << "| " << left << setw(10) << U.UserName;
	}

public:    

	static void ShowTransferLogScreen() {
		vector<clsBankclint::stTransferLog>vTransferlog = clsBankclint::GitTransferLogList();

		string Title = "\t Transfer Log List.";
		string SubTitle = "\t(" + to_string(vTransferlog.size()) + ") Record(s).";
		_DrawScreenHeader(Title, SubTitle);

		cout << "--------------------------------------------------------------------------------------------------\n";
		cout << "| " << left << setw(24) << "Date/ Time";
		cout << "| " << left << setw(10) << "S.Acct";
		cout << "| " << left << setw(10) << "d.Acct";
		cout << "| " << left << setw(10) << "Amount";
		cout << "| " << left << setw(12) << "S.Balance";
		cout << "| " << left << setw(12) << "d.Balance";
		cout << "| " << left << setw(10) << "User";
		cout << "\n--------------------------------------------------------------------------------------------------\n";

		if (vTransferlog.size() == 0) {
			cout << "\n\t\t\t\tNo Logins Available In the System!";
		}
		else {
			for (clsBankclint::stTransferLog Record : vTransferlog) {
				PrintTransferLogRecordLine(Record);
				cout << endl;
			}
		}
		cout << "\n--------------------------------------------------------------------------------------------------\n";


	}

};

