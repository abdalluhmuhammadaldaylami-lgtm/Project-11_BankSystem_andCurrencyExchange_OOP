#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include"clsInputValidate.h";
#include"clsScreen.h";
#include"clsCurrency.h";
using namespace std;

class clsListCurrenciesScreen:protected clsScreen
{
	
	static void PrintCurrenciesRecordLine(clsCurrency C) {
		cout << "| " << left << setw(30) << C.Country();
		cout << "| " << left << setw(10) << C.CurrencyCode();
		cout << "| " << left << setw(33) << C.CurrencyName();
		cout << "| " << left << setw(15) << C.Rate();
	}

public:

	static void ShowListCurenciesScreen() {
		vector<clsCurrency>vCurency = clsCurrency::GetCurrenciesList();

		string Title = "\tCurrencies List Screen";
		string SubTitle = "\t(" + to_string(vCurency.size()) + ") Currency";
		_DrawScreenHeader(Title, SubTitle);

		cout << "-------------------------------------------------------------------------------------------\n";
		cout << "| " << left << setw(30) << "Country";
		cout << "| " << left << setw(10) << "Code";
		cout << "| " << left << setw(33) << "Name";
		cout << "| " << left << setw(15) << "Rate/(1$)";
		cout << "\n-------------------------------------------------------------------------------------------\n";

		if (vCurency.size() == 0) {
			cout << "\n\t\t\t\tNo Cureency Available In the System!";
		}
		else {
			for (clsCurrency c : vCurency) {
				PrintCurrenciesRecordLine(c);
				cout << endl;
			}
		}
		cout << "\n-------------------------------------------------------------------------------------------\n";

	}


};

